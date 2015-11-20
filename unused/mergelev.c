//=============================================================================
// Merge Levels (mergelev)  Written 12-3-2004, by Barry Mead.  License GPL
// See COPYING file for full details of GPL License.
// This program merges scavenger levels from two source files according to
// designated level numbers and outputs the result to a third file.
// It can either keep the movie portion of the file or omit it as needed.
//
// $Author$    $Date$   $Id$   $Revision$ 
//
// calling sequence:
// mergelev infile1.scl infile2.scl outFile.scl start1 stop1 start2 stop2 erase
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <sys/types.h>

#define LEVELSIZE 180
//All levels are this size
#define MAXLEVELS 400
//New maximum number
#define MAXMOVIESIZE 4118
//Movies vary in size, but this is the maximum size allowed.
//MAXMOVIESIZE is 4096+2+20 4096 is scav.h MAXMOVIE, 2 is last entry, 20 is header(4 score + 16 name)
typedef struct 
{                                      //Structure of each header item
   int32_t levelOffset;
   int32_t levelLength;
   int32_t movieOffset;
   int32_t movieLength;
} header_t;

typedef struct 
{                                      //Structure of each preamble
   char signature[4];
   int32_t numLevels;
} preamble_t;


// Global Variables

FILE * inFile1;                     //2 input files and one output file
FILE * inFile2;
FILE * outFile;
preamble_t *inPreamble1=NULL;       //Preamble for input file 1
preamble_t *inPreamble2=NULL;       //Preamble for input file 2
preamble_t *outPreamble=NULL;       //Preamble for output file
char *levelBuf=NULL;                //For copying level portion
char *movie=NULL;                   //For copying movie portion
header_t *inHeader1=NULL;
header_t *inHeader2=NULL;
header_t *outHeader=NULL;
int32_t in1Start,in1Stop;           //Start and stop level numbers for input file 1
int32_t in2Start,in2Stop;           //Start and stop level numbers for input file 2
int32_t EraseMovies=0;              //Default mode is keep movies
int32_t in1Levels=0;                //Number of levels in input file 1
int32_t in2Levels=0;                //Number of levels in input file 2
int32_t outLevels=0;                //Number of levels in the output file
int32_t outOffset;                  //Byte offset into output file where level/movie is stored
int32_t outIndex;                   //Index into the output headers
int32_t file2Used=1;                //If second file is "null" this is zero
int32_t actual;                     //Actual number of records read or written. (not bytes)
int32_t inIndex;                    //Index into the input headers 1 & 2
int32_t i=0;
int32_t j=0;                        //Hold temporary values

//----------- End of Global Variables

void mergecleanup(void)
{
   free(inPreamble1);               //Free memory allocated by calloc
   free(inPreamble2);
   free(outPreamble);
   free(levelBuf);
   free(movie);
   free(inHeader1);
   free(inHeader2);
   free(outHeader);
   fclose(inFile1);                 //and close any open files
   if (file2Used) fclose(inFile2);
   fclose(outFile);
}

int32_t BigE(int32_t in)  					//Big Endian byte reverser
{
   union {
      int32_t i;                    //The int32_t shares memory with an
      char c[4];                    //array of 4 characters.
   } e;
   char csave;
   e.i = in;                        //Get the input integer, and use
   csave = e.c[0];
   e.c[0]=e.c[3];                   //the character array to reverse the bytes
   e.c[3]=csave;
   csave=e.c[1];
   e.c[1]=e.c[2];
   e.c[2]=csave;
   return(e.i);                     //Then return the reversed integer
}

// Check function verifies that the start and stop level numbers are valid
int32_t check(char * input, int32_t minValue)
{
   char nonnum=0;
   for (i=0; i<strlen(input); i++)
      if(!isdigit(input[i])) nonnum++;
   if(nonnum == 0) i = atoi(input);
   if (nonnum || i < 1 || i > MAXLEVELS)
   {
      printf("Level numbers must be numeric, in the range of 1 to %d\n",MAXLEVELS);
      exit(0);
   }
   if (i < minValue)
   {
      printf("The stop level number %d must equal or greater than the start number %d\n",i,minValue);
      exit(0);
   }
   return(i);
}

//prepHeader calculates the offset and length values for the output header using a given input header.
void prepHeader(header_t * inHeader, int32_t start, int32_t stop)
{
   for (inIndex=start-1; inIndex<stop; inIndex++,outIndex++)
   {
      outHeader[outIndex].levelOffset = BigE(outOffset);
      i = outHeader[outIndex].levelLength = inHeader[inIndex].levelLength;
      if (BigE(i) > LEVELSIZE)
      {
         printf("Input file has an invalid level length %d, max is %d\n",BigE(i),LEVELSIZE);
         exit(2);
      }
      outOffset += BigE(i);
      if (EraseMovies || 0 == inHeader[inIndex].movieLength)
      {
         outHeader[outIndex].movieOffset = 0;
         outHeader[outIndex].movieLength = 0;
      }
      else
      {
         outHeader[outIndex].movieOffset = BigE(outOffset);
         i = outHeader[outIndex].movieLength = inHeader[inIndex].movieLength;
         if (BigE(i) > MAXMOVIESIZE)
         {
            printf("Input file has an invalid movie length %d, max is %d\n",BigE(i),MAXMOVIESIZE);
            exit(2);
         }
         outOffset += BigE(i);
      }
   }           ///End of for
}              //End of prepHeader

//copyData routine copys the data from an input file to the output file
void copyData(FILE * inFile,header_t * inHeader,int32_t start, int32_t stop)
{
   for (inIndex=start-1; inIndex<stop; inIndex++,outIndex++)
   {
      fseek(inFile,BigE(inHeader[inIndex].levelOffset),SEEK_SET);
      //Is output file tracking with outHeader projections?
      i = BigE(outHeader[outIndex].levelOffset);
      j = ftell(outFile);
      if (i != j)
      {
         printf("Output level should be at offset %x but is at offset %x\n",i,j);
         exit(3);
      }
      actual = fread(levelBuf,1,LEVELSIZE,inFile); //Levels should all be the same size
      i = BigE(inHeader[inIndex].levelLength);
      if (i != LEVELSIZE || i != actual)
      {
         printf("Expected to read %d bytes of level %d, but got %d\n",LEVELSIZE,inIndex+1,actual);
         exit(3);
      }
#ifdef DEBUG
      printf("Level %d at %x size %x\n",outIndex+1,j,i);
#endif
      actual = fwrite(levelBuf,1,LEVELSIZE,outFile);
      if (actual != LEVELSIZE)
      {
         printf("Expected to write %d bytes of level %d, but wrote %d\n",LEVELSIZE,outIndex+1,actual);
         exit(3);
      }
      if (EraseMovies == 0 && 0 != inHeader[inIndex].movieLength)   //Copy movie if length not zero
      {
         fseek(inFile,BigE(inHeader[inIndex].movieOffset),SEEK_SET);
         //Is output file tracking with outHeader projections?
         i = BigE(outHeader[outIndex].movieOffset);
         j = ftell(outFile);
         if (i != j)
         {
            printf("Output movie should be at offset %x but is at offset %x\n",i,j);
            exit(3);
         }
         i = BigE(inHeader[inIndex].movieLength);
         actual = fread(movie,1,i,inFile); //Movies have variable size.
         if (i != actual)
         {
            printf("Expected to read %d bytes movie on level %d but got %d\n",i,inIndex+1,actual);
            exit(3);
         }
#ifdef DEBUG
         printf("Movie %d at %x size %x\n",outIndex+1,j,i);
#endif
         actual = fwrite(movie,1,i,outFile);
         if (actual != i)
         {
            printf("Expected to write %d bytes movie %d, but wrote %d\n",i,outIndex+1,actual);
            exit(3);
         }
      }        //End of not Erase Movies
   }           //End of for
}              //End of copyData

// Main Program Starts Here
int32_t main(int32_t argc, char *argv[])
{

// Initialize the data areas

   levelBuf = (char *)calloc(1,LEVELSIZE);
   movie = (char *)calloc(1,MAXMOVIESIZE);
   inPreamble1 = (preamble_t *)calloc(1,sizeof(preamble_t));
   inPreamble2 = (preamble_t *)calloc(1,sizeof(preamble_t));
   outPreamble = (preamble_t *)calloc(1,sizeof(preamble_t));
   inHeader1 = (header_t *)calloc(MAXLEVELS,sizeof(header_t));
   inHeader2 = (header_t *)calloc(MAXLEVELS,sizeof(header_t));
   outHeader = (header_t *)calloc(MAXLEVELS,sizeof(header_t));

// Collect user input about starting and stopping levels

   if (argc < 8)
   {
      printf("\nmergelev: A simple, useful command line driven utility for creating,\n"
             "managing, and maintaining scavenger level archives.\n\n"
             "Usage:\n\n"
             "mergelev infile1 infile2 outfile start1 stop1 start2 stop2 erase\n\n"
             "Example:\n\nmergelev levels.scl mylevels.scl out.scl 1 180 181 200 1\n\n"
             "If the optional erase parameter is specified (the last 1), then the movies\n"
             "will be erased in the merged output file.  The erase parameter should be\n"
             "omitted entirely (only 7 parameters) to preserve the movies.\n"
             "The four numbers after the out.scl represent start and stop levels\n"
             "to be copied from the infile1 and infile2 respectively\n\n"
             "Use scavenger to browse through the levels in the prospecive input files.\n"
             "You can achieve this by copying each prospective input file to the levels.scl\n"
             "file in your $HOME/.scavenger directory.\n"
             "Once you have picked which numbers you like from each file, simply use this\n"
             "utility to create your own custom collection of levels.  You can also use\n"
             "mergelev to clip a single file shorter, or remove the movies from a collection\n"
             "For single file clipping or movie removal, use the following syntax:\n\n"
             "mergelev levels.scl null out.scl 1 150 1 1 1\n\n"
             "In this example notice that the second input file is named \"null\"\n"
             "This is a special name and must be spelled exactly as shown.  As before\n"
             "the optional erase parameter (the last 1) will erase the movies if desired\n"
             "Note that the start and stop numbers for the second file are now merely place\n"
             "holders to preserve the command line parameter count, and should be set to 1.\n\n");

      free(levelBuf);         //Free allocated memory and exit
      free(movie);
      free(inPreamble1);
      free(inPreamble2);
      free(outPreamble);
      free(inHeader1);
      free(inHeader2);
      free(outHeader);
      exit(1);
   }                          //end of argc < 8
   //Value check the input parameters and collect the start, stop and erase data
   in1Start = check(argv[4],1);
   in1Stop  = check(argv[5],in1Start);
   in2Start = check(argv[6],1);
   in2Stop  = check(argv[7],in2Start);
   if (argc == 9)
      EraseMovies = check(argv[8],1);

   //Open all files here so we can use the atexit function to close up everything

   inFile1 = fopen(argv[1],"r");
   if (NULL == inFile1)
   {
      printf("Input file 1 %s does not exist!\n",argv[1]);
      free(inPreamble1);
      free(inPreamble2);
      free(outPreamble);
      free(levelBuf);
      free(movie);
      free(inHeader1);
      free(inHeader2);
      free(outHeader);
      exit(1);
   }
   if (0 == strncmp(argv[2],"null",5)) file2Used = 0; //If null then no file 2
   if (file2Used)
   {
      inFile2 = fopen(argv[2],"r");
      if (NULL == inFile2)
      {
         printf("Input file 2 %s does not exist!\n",argv[2]);
         free(inPreamble1);
         free(inPreamble2);
         free(outPreamble);
         free(levelBuf);
         free(movie);
         free(inHeader1);
         free(inHeader2);
         free(outHeader);
         fclose(inFile1);
         exit(2);
      }
   }
   outFile = fopen(argv[3],"w");
   if (NULL == outFile)
   {
      printf("Output file %s is not writable\n",argv[3]);
      free(inPreamble1);
      free(inPreamble2);
      free(outPreamble);
      free(levelBuf);
      free(movie);
      free(inHeader1);
      free(inHeader2);
      free(outHeader);
      fclose(inFile1);
      fclose(inFile2);
      exit(1);
   }
   atexit(mergecleanup); // From now on mem is freed and all three files will be closed at exit


   actual = fread((char *)inPreamble1,sizeof(preamble_t),1,inFile1); //Read 1 preamble
   in1Levels = (BigE(inPreamble1->numLevels)>>1); //Num of levels = 1/2 num in signature
   if ((actual != 1) || (0 != strncmp("SCAV",inPreamble1->signature,4)) || (in1Levels > MAXLEVELS))
   {
      printf("Input file 1 %s is not a proper scavenger file\n",argv[1]);
      exit(1);
   }
   actual = fread((char *)inHeader1,sizeof(header_t),in1Levels,inFile1); //Read input file headers
   if (actual != in1Levels)
   {
      printf("Error Reading input file headers\n");
      exit(1);
   }
   if (in1Stop > in1Levels)
   {
      printf("You asked for level %d, yet input file 1 only has %d levels\n",in1Stop,in1Levels);
      exit(1);
   }

   //Read the signature and headers from input file 2


   if (file2Used)
   {
      actual = fread((char *)inPreamble2,sizeof(preamble_t),1,inFile2); //Read 1 preamble
      in2Levels = (BigE(inPreamble2->numLevels)>>1); //Num of levels = 1/2 num in signature
      if ((actual != 1) || (0 != strncmp("SCAV",inPreamble2->signature,4)) || (in2Levels > MAXLEVELS))
      {
         printf("Input file 2 %s is not a proper scavenger file\n",argv[2]);
         exit(2);
      }
      actual = fread((char *)inHeader2,sizeof(header_t),in2Levels,inFile2); //Read input file headers
      if (actual != in2Levels)
      {
         printf("Error Reading input file headers\n");
         exit(2);
      }
      if (in2Stop > in2Levels)
      {
         printf("You asked for level %d, yet input file 2 only has %d levels\n",in2Stop,in2Levels);
         exit(2);
      }
   }
// Create the output file

   outLevels = (in1Stop - in1Start) + 1;                    //# levels from file 1
   if (file2Used) outLevels += (in2Stop - in2Start) + 1;    //# levels from file 2 
   strncpy(outPreamble->signature,"SCAV",4);                //Put in the signature
   outPreamble->numLevels = BigE((outLevels*2));            //Big endian format
   actual = fwrite((char *)outPreamble,sizeof(preamble_t),1,outFile);
   if (actual != 1)  //1-preamble written?
   {
      printf("Error writing preamble to output file %s\n",argv[2]);
      exit(1);
   }

   outOffset= 8 + (outLevels * sizeof(header_t));  //Compute initial output offset

   // Initialize the output headers

   outIndex = 0;
   prepHeader(inHeader1,in1Start,in1Stop);
   if (file2Used) prepHeader(inHeader2,in2Start,in2Stop);

   // Now that the output headers are ready, write them to the output file.

   actual = fwrite((char *)outHeader,sizeof(header_t),outLevels,outFile);
   if (actual != outLevels)
   {
      printf("Error writing headers to output file %s\n",argv[3]);
      exit(3);
   }

   // Copy the input files to the output file

   outIndex = 0;
   copyData(inFile1,inHeader1,in1Start,in1Stop);
   if (file2Used) copyData(inFile2,inHeader2,in2Start,in2Stop);
   printf("Copy Successful\n");
   exit(0);
}
