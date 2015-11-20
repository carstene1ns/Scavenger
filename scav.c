/* SCAVENGER David Ashley dash@xdr.com SDL ver Barry Mead barrymead@cox.net */
/* License GPL.  See COPYING for details of GPL License */
/* $Author$    $Date$   $Id$   $Revision$ */
#define VERSION "SDL Scavenger version 1.4.5.4 (1/5/2015)"

#include "scav.h"

char demolevel0[]={
0x04,0x44,0x44,0x07,0x00,0x06,0x60,0x00,0x70,0x44,0x44,0x40,
0x30,0x00,0x00,0x1a,0x00,0x06,0x60,0x00,0x11,0x00,0x00,0x03,
0x30,0x44,0x40,0x00,0x09,0x06,0x60,0x80,0x80,0x84,0x44,0x03,
0x31,0x00,0x01,0x11,0x11,0x12,0x21,0x11,0x11,0x10,0x00,0x13,
0x30,0x00,0x00,0x01,0x11,0x11,0x11,0x11,0x10,0x00,0x00,0x03,
0x31,0x00,0x00,0x0b,0x11,0x11,0x11,0x11,0x70,0x00,0x00,0x13,
0x30,0x00,0x70,0x00,0xb1,0x11,0x11,0x1b,0x00,0x07,0x00,0x03,
0x31,0x11,0xa0,0x00,0x00,0x11,0x11,0x00,0x00,0x0a,0x11,0x13,
0x30,0x00,0x00,0x00,0x00,0x01,0x10,0x00,0x00,0x00,0x00,0x03,
0x30,0x70,0x00,0x04,0x44,0x00,0x00,0x44,0x40,0x00,0x70,0x03,
0x31,0x11,0x11,0x10,0x00,0x31,0x13,0x00,0x01,0x11,0x11,0x13,
0x31,0x11,0x11,0x10,0x03,0x11,0x11,0x30,0x01,0x11,0x11,0x13,
0x30,0x00,0x00,0x00,0x31,0x11,0x11,0x13,0x00,0x00,0x00,0x03,
0x30,0x00,0x00,0x03,0x11,0x11,0x11,0x11,0x30,0x00,0x00,0x03,
0x30,0x00,0x70,0x31,0x11,0x11,0x11,0x11,0x13,0x07,0x00,0x03
};

char demomovie0[]={
0xba,0xa9,0x00,0x00,0x6c,0x6f,0x72,0x64,0x20,0x64,0x61,0x76,
0x65,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x66,0x03,0x10,
0x02,0x01,0x00,0x05,0x03,0x2c,0x02,0x52,0x00,0x2e,0x01,0x69,
0x04,0x08,0x05,0x19,0x04,0x07,0x05,0x19,0x04,0x05,0x05,0x05,
0x00,0x2e,0x03,0x04,0x00,0x06,0x05,0x03,0x00,0x18,0x04,0x07,
0x05,0x06,0x00,0x18,0x03,0x06,0x00,0x09,0x05,0x08,0x00,0x20,
0x03,0x0e,0x00,0xcd,0x04,0x1d,0x01,0x0d,0x03,0x06,0x01,0x33,
0x03,0x0d,0x04,0x08,0x05,0x2e,0x04,0x45,0x01,0x55,0x03,0x03,
0x00,0x06,0x04,0x1f,0x00,0x21,0x03,0x10,0x06,0x18,0x03,0x07,
0x06,0x03,0x03,0x05,0x00,0x15,0x04,0x0f,0x06,0x25,0x04,0x25,
0x00,0x31,0x02,0x38,0x04,0x13,0x03,0x07,0x01,0x07,0x03,0x07,
0x01,0x0d,0x03,0x06,0x01,0x10,0x03,0x06,0x01,0x0d,0x03,0x08,
0x01,0x0b,0x03,0x09,0x01,0x0d,0x03,0x0c,0x01,0x78,0x04,0x0c,
0x01,0x05,0x00,0x04,0x01,0x28,0x00,0x42,0x01,0xbe,0x03,0x08,
0x06,0x1a,0x03,0x06,0x06,0x01,0x03,0x04,0x00,0x27,0x04,0x08,
0x05,0x07,0x00,0x29,0x03,0x2e,0x00,0x28,0x03,0x01,0x00,0x26,
0x04,0x1b,0x02,0x11,0x03,0x05,0x02,0x50,0x03,0x66,0x01,0x16,
0x00,0x05,0x02,0x01,0x00,0x26,0x04,0x07,0x06,0x05,0x00,0x19,
0x03,0x07,0x06,0x27,0x03,0x31,0x01,0x23,0x04,0x10,0x00,0x07,
0x02,0x2d,0x00,0x22,0x03,0x44,0x01,0x91,0x04,0x17,0x00,0x8b,
0x03,0x8e,0x00,0x2a,0x02,0x22,0x00,0x29,0x01,0xb1,0x04,0x06,
0x05,0x05,0x04,0x08,0x00,0x0d,0x04,0x07,0x05,0x1a,0x04,0x07,
0x05,0x06,0x00,0x2e,0x03,0x05,0x00,0x06,0x05,0x03,0x00,0x18,
0x04,0x07,0x05,0x06,0x00,0x27,0x03,0x08,0x06,0x02,0x03,0x03,
0x00,0xa8,0x04,0x52,0x01,0x83,0x03,0x19,0x01
};

uchar rotbytes[]={
0x00,0x01,0x03,0x03,0x07,0x0f,0x00,0x00,
0x01,0x02,0x06,0x0d,0x19,0x33,0x00,0x00,
0x01,0x03,0x05,0x0e,0x1e,0x3c,0x00,0x00
};
 
int marks[MARKMAX],*markpoint;

char libpath[256];
char localname[256];
char localdirname[256];
char resourcename[256];
char newresname[256];
char rcname[256];
char LevelsName[20];

uchar playername[20];
int NameEntryMode = 0;
uchar bestname[20];
int fallsound;
int digsound;
int gottimer = -50;   /* hold action for 1.0 seconds for screen to fully wake up */
int	SoundEnable = 1;	/* Global to enable sound (Default on) off by cmd option */
uchar needwhole=0,needtoptext=1,needbottomtext=1;

int xpos=BLOCKX/2,ypos=BLOCKY/2;
int hc=0;

int upkey,downkey,leftkey,rightkey,digleftkey,digrightkey;

int hiddens[3],hiddennum;
int ilevel=1;
int file;
int ptx;                /* global for text here function */
int pty;                /* global for other text functions */
char gfxname0[256];
char gfxname1[256];
char gfxname2[256];
char gfxname3[256];
char *gfxnames[4]={gfxname0,gfxname1,gfxname2,gfxname3};

uchar movie[MOVIEMAX+2+20];
uchar *mpoint;
uchar *savempoint;
uchar savewhatcount;
uchar *mend=movie+MOVIEMAX+20;
static int32_t score,bestscore,besttime;
//Time 1 is 
//Time 2 is
//Time 3 is
//Time 4 is

int32_t  bonusSecondsLeft,cyclesThisSecond,totalPlaySeconds,bonusPenaltyDelay;
int32_t totalPlayCycles,bestPlayCycles;
int playflags;
gfxset gfxsets[NUMGFX];

uchar toptext[72];
uchar bottomtext[72];
uchar topwant[73];
uchar statuswant[20];
uchar bottomwant[73];
uchar mtflag;
uchar paused=0;

int oldmode;
int wnum;
int rowbytes;
int gran,gran64;
int cwin;
int seed=1;
int figseg;
uchar colormap[768];
int mousex,mousey;
int numenemies;
int numgold;
int cframe;
int clevel=1;
int bright;
uchar temp[1024];
void (*mode)();
uchar playing;
uchar recording;
static int32_t testval=-1;
uchar wonflag=0;
uchar lostflag=0;
uchar freezing=0;
uchar randcount,randcount2;
uchar smap[16];
int mbuttons,mbuttons2;
int curx,cury;

int rotnum;

int gothidden;
int gotflashing;

/*void mode0(),mode1(),mode2(),mode3(),mode4();
*/

uchar levelbuff[LEVELSIZE];
uchar levelback[LEVELSIZE];
uchar movings[LEVELSIZE];
uchar randoms[LEVELSIZE];
int xcomp[640];
int ycomp[480];
int ycomp2[480];
int centerx[640];
int centery[480];

int cantascend[LX];
int cantdescend[LX];
int enterableo[LX+2];
int *enterable=enterableo+1;
int stable[LX];
int upgoal[LX];
int downgoal[LX];
int bits[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
uchar calced;

struct sprite spritelist[MAXSPRITES];

uchar *flashat;
int flashx,flashy;
int flashtimer;
struct sprite *flashsprite;

struct entity entities[8];

struct dig diggings[MAXDIG];


int skips[192];

int mickeyx,mickeyy;
int mx,my;

int offscreen;
int vp=0;
int tileseg;

uchar *wantiff="Picture file must be in IFF format.\n";

uchar *picloc=NULL,*picput=NULL; /* Initialize pointers */
int bmw,bmh,byteswide,depth;
int ihand,ileft;
uchar *itake;
uchar ibuff[IBUFFLEN];

int bestdir,bestdist,aboveenemy,belowenemy,mask,thisdir,aboveplayer,belowplayer;

void *configtab[]=
{
"upkey",&upkey,setint,
"downkey",&downkey,setint,
"leftkey",&leftkey,setint,
"rightkey",&rightkey,setint,
"digleftkey",&digleftkey,setint,
"digrightkey",&digrightkey,setint,
"background",gfxname0,setstring,
"hero",gfxname1,setstring,
"enemy",gfxname2,setstring,
"hidden",gfxname3,setstring,
0,0,0
};







static uint32_t readuint32()
{
   uint32_t val1=0;

   val1=myci()<<24L;
   val1|=myci()<<16L;
   val1|=myci()<<8;
   val1|=myci();

   return val1;
}
int rbs()
{
   int ch;
   ch=myci();
   if(ch>127) ch-=256;
   return ch;
}

int myci()
{
   if(!ileft)
   {
      ileft=read(ihand,ibuff,IBUFFLEN);

      if(!ileft) return -1;
      itake=ibuff;
   }
   ileft--;
   return *itake++;
}

int expandpath(char *put,char *name,int num)
{
char *p,ch='\0';

   if(!num)
   {
      sprintf(put,"%s/%s/%s",localname,localdirname,name);
      return 1;
   }
   --num;
   p=libpath;
   while(num-- && *p)
   {
      while(*p && *p++!=':');
   }
   if(!*p) return 0;
   while(*p && *p!=':')
      ch=*put++=*p++;
   if(ch!='/') *put++='/';
   strcpy(put,name);
   return 1;
}

uchar *doiff(uchar *name)
{
uint32_t type,size;
uchar comp;
int i,j;
uchar lines[8][MAXBYTES];
uchar temparea[256];

   if(!picloc)
   {
      picloc=malloc(64000);
      if(!picloc)
         return "Could not allocate memory for picture.\n";
   }
   picput=picloc;
   for(i=0;;)
   {
      if(!expandpath(temparea,name,i))
         return "Cannot open picture file.\n";
      ihand=open(temparea,O_RDONLY|O_BINARY);
      if(ihand!=-1) break;
      ++i;
   }
   ileft=0;
   type=readuint32();
   if(type!=FORM) {close(ihand);ihand=0;return wantiff;}
   readuint32();
   type=readuint32();
   if(type!=ILBM) {close(ihand);ihand=0;return wantiff;}
   bmw=bmh=byteswide=0;
   while( (type=readuint32()) )
   {
      if(type==0xffffffffL) break;
      size=readuint32();
      if(size&1) size++;
      if(type==BMHD)
      {
         for(i=0;i<size;i++) temparea[i]=myci();
         bmw=temparea[0]*256+temparea[1];
         byteswide=(bmw+7)>>3;
         bmh=temparea[2]*256+temparea[3];
         depth=temparea[8];
         comp=temparea[10];
/*printf("(%d,%d) %d bpp\n",bmw,bmh,depth);*/
      } else
      if(type==BODY)
      {
         for(i=0;i<bmh;i++)
         {
            for(j=0;j<depth;j++)
            {
               unpack(byteswide,lines[j]);
            }
            debit ((uchar *)lines, byteswide, depth);
         }
      } else
      if(type==CMAP)
      {
         for(i=0;i<size;i++)
         {
            colormap[i]=myci();
         }
      } else
      {
         while(size--) myci();
      }
   }
   close(ihand);ihand=0;

   return 0;
}

void debit(uchar *lines, int numb, int deep)
{
int i,j;
   for(i=0;i<numb;i++)
   {
      for(j=7;j>=0;j--)
         *picput++ = fixbyte(lines+i,1<<j,deep);
   }
}

int fixbyte(char *take,int bit,int deep)
{
int res=0,mask=1;
   while(deep--)
   {
      if(*take & bit)
         res|=mask;
      mask+=mask;
      take+=MAXBYTES;
   }
   return res;
}

void unpack(int len, uchar *where)
{
   int ch,ch2;
   while(len>0)
   {
      ch=rbs();
      if(ch>=0)
      {
         ch++;
         len-=ch;
         while(ch--) *where++=readbyte();
      } else
      {
         ch=1-ch;
         len-=ch;
         ch2=readbyte();
         while(ch--) *where++=ch2;
      }
   }
}

/* Level and movie resources alternate. So num is ((level number -1) * 2) for level */
/* and ((Level number -1) * 2) + 1 for the movie (there is no resource for level 0) */
int getresource(int num,char *put,int len)
{
int input;
int got;
uchar buff[8];
int32_t offset,length;
int32_t max;

   input=open(resourcename,O_RDONLY|O_BINARY);
   if(input<0) return -1;
   got=read(input,buff,8);
   if(got!=8) {close(input);return -2;}
   if (strncmp(buff,"SCAV",4)) {close(input);return -3;}
   max=(buff[4]<<24) | (buff[5]<<16) | (buff[6]<<8) | buff[7];
   if(num>=max) {close(input);return 0;}
   lseek(input,(num+1)<<3,SEEK_SET);
   got=read(input,buff,8);
   offset=(buff[0]<<24) | (buff[1]<<16) | (buff[2]<<8) | buff[3];
   length=(buff[4]<<24) | (buff[5]<<16) | (buff[6]<<8) | buff[7];
   if(len>length) len=length;
   if(!offset || !len) {close(input);return 0;}
   lseek(input,offset,SEEK_SET);
   got=read(input,put,len);
   close(input);
   return got;
}

static int rlout(int handle, uint32_t value)
{
char buff[4];
   buff[0]=value>>24;
   buff[1]=value>>16;
   buff[2]=value>>8;
   buff[3]=value;
   return write(handle,buff,4) == 4;
}

/* Level and movie resources alternate. So num is ((level number -1) * 2) for level */
/* and ((Level number -1) * 2) + 1 for the movie (there is no resource for level 0) */
int putresource(int num,uchar *take,int len) /* levels.scl file */
{
int input,output;
uchar buff[8];
int32_t offset, length;
int err,got;
int32_t headers[MAXLEVELS*4];
int32_t oldnum,count;
int max;
int i, delta;
char copybuff[1024]; /* copy as much as 1024 bytes at at time */

   if(num>=(MAXLEVELS*2)) return -5;
   input=open(resourcename,O_RDONLY|O_BINARY);
   if(input==-1) return -4;
   got=read(input,buff,8);  /* get first 8 bytes of file */
   if(got!=8) {close(input);return -2;}
   if(strncmp(buff,"SCAV",4)) {close(input);return -3;} /* first 4-bytes are SCAV signature */
   output=open(newresname,O_WRONLY|O_BINARY|O_CREAT|O_TRUNC,0600);
   if(output==-1) {close(input);return -6;}
   /* next 4-bytes are the number of levels saved in this file (BIG ENDIAN ORDER) */
   oldnum=(buff[4]<<24) | (buff[5]<<16) | (buff[6]<<8) | buff[7];
   for(i=0;i<oldnum+oldnum;i++)
   {  /* each header has a 4-byte offset and a 4-byte length and each level has 2-headers
         the first for the level itself and the second for the demo movie to that level */
      got=read(input,buff,4);
      headers[i]=(buff[0]<<24) | (buff[1]<<16) | (buff[2]<<8) | buff[3];
   }
   while(i<=num+num+1)  /* zero fill headers after end of file up to num */
      headers[i++]=0;
   max=i>>1;            /* potential new max value */
   offset=headers[num+num];
   length=headers[num+num+1];
   delta=(max-oldnum)<<3;
   if(offset)
      for(i=0;i<max;i++)
         if(headers[i+i]>offset)
            headers[i+i]-=length;
   if(delta)
      for(i=0;i<max;i++)
         if(headers[i+i])
            headers[i+i]+=delta;
   if (write(output,"SCAV",4) != 4) return -200;
   if (!rlout(output,max)) return -200;
   headers[num+num]=0;
   headers[num+num+1]=len;
   for(i=0;i<max+max;i++)
      if (!rlout(output,headers[i])) return -200;

   if(offset)
   {
      offset-=(oldnum+1)<<3;
      count=offset;
      while(count)
      {
         got=count>1024 ? 1024 : count;
         if (read(input,copybuff,got) != got) return -200;
         if (write(output,copybuff,got) != got) return -200;
         count-=got;
      }
      lseek(input,length,SEEK_CUR);
   }
   offset += (max+1) << 3;
   for(;;)
   {
      got=read(input, copybuff, 1024);
      if (!got) break;
      if (write (output, copybuff, got) != got) return -200;
      offset += got;
   }
   if(len)
   {
      if (write (output, take, len) != len) return -200;
      lseek (output, (num+1) << 3, SEEK_SET);
      if (!rlout (output, offset)) return -200;
   }
   close(input);
#if !defined(__WIN32__) && !defined(WIN32)
   if (fsync(output)) return -200;
#endif
   if (close(output)) return -200;
 eprintf("trying to unlink %s\n",resourcename); 
   err=unlink(resourcename);
   if(err) return -1;
 eprintf("trying to rename %s to %s\n",newresname,resourcename); 
   err=rename(newresname,resourcename);
   if(err)
   {
      eprintf("Error renaming %s to %s code was %d",newresname,resourcename,err);
      return -1;
   }
   return 0;
}

/* num is the actual level number  here */
int loadlevel(int num)
{
   int err;
   uchar tlevel[180];
   uchar *p1,*p2;
   int i,j;
   erasetile(32,440); /* unmark flashing */
   erasetile(56,440); /* unmark hidden */
   erasetile(80,440); /* unmark ladders */
   erasetile(104,440); /* unmark penalties */
   memset(levelbuff,BORDER,LEVELSIZE);
   if(num)
   {
      err = getresource ((num-1) << 1, tlevel, 180);
      if (err != 180) return (0);
   } else
      memcpy(tlevel,demolevel0,180);

   p2=levelbuff+30;
   p1=tlevel;
   for(j=0;j<15;j++)
   {
      for(i=0;i<12;i++)
      {
         *p2++ = *p1>>4;
         *p2++ = *p1++ & 0x0f;
      }
      p2+=4;
   }
   return (1);
}

int scavrand()
{
int ttt;
   ttt=seed;
   seed>>=1;
   if(ttt&1) seed^=0xb400;
   return seed;
}

void paintlevel()
{
   int i,j;
   uchar *p;
   int w;
   uchar v;
   uchar ttt[64];
   p=levelbuff+30;
   for(j=0;j<LY;j++)
   {
      for(i=0;i<LX;i++)
      {
         w=*p;
         if(w!=BRICK && w!=CEMENT && w!=HIDDEN && w!=FAKE)
         {
            w=*((p-levelbuff)+randoms)*12;
            puttile(i*24+XOFF,j*24+YOFF,w);
            v=smap[*(p-28)];
            v|=smap[*(p-29)]<<1;
            v|=smap[*(p-1)]<<2;
            if(v) puttile(i*24+XOFF,j*24+YOFF,SHADOWFIGS+v);
         }
         p++;
      }
      p+=4;
   }
   p=levelbuff+30;
   for(j=0;j<LY;j++)
   {
      for(i=0;i<LX;i++)
      {
         w=*p;
         if(w) puttile(i*24+XOFF,j*24+YOFF,w + 12*randoms[p-levelbuff]);
         p++;
      }
      p+=4;
   }
   for(i=0;i<24;i++)
   {
      j=i*24+XOFF;
      puttile(j,YOFF-24,BORDERFIGS+1);
      puttile(j,YOFF+24*15,BORDERFIGS+7);
   }
   for(i=0;i<15;i++)
   {
      j=i*24+YOFF;
      puttile(XOFF-24,j,BORDERFIGS+3);
      puttile(XOFF+24*24,j,BORDERFIGS+5);
   }
   puttile(XOFF-24,YOFF-24,BORDERFIGS);
   puttile(XOFF+24*24,YOFF-24,BORDERFIGS+2);
   puttile(XOFF+24*24,YOFF+15*24,BORDERFIGS+8);
   puttile(XOFF-24,YOFF+15*24,BORDERFIGS+6);
   if(playing)
   {
      if (recording)
         sprintf(ttt,"PLAYER:%s",playername);
      else
         sprintf(ttt,"PRESS SPACE FOR MENU");
      pty=YOFF+16*TY;
      centertext("                          "); /* enough space to clear longest player name */
      pty=YOFF+16*TY;
      centertext(ttt);
   }
}


void statustext(uchar * txt,int sdelay);

void dectime()
{
/* int i;
   uchar *p1,*p2;
 */
 
   if(!playing || freezing) return;
   totalPlayCycles++;
   if (bonusPenaltyDelay)
   {
      bonusPenaltyDelay--;
      if (bonusPenaltyDelay == 0)
      {
         sprintf(statuswant,"               ");
         statustext(statuswant,0);
      }
   }
   cyclesThisSecond++; /* count each iteration 60 per sec */
   if(cyclesThisSecond<60) return;
   cyclesThisSecond=0; /* reset tick per second counter */
   if(bonusSecondsLeft > 0) 
   {
      bonusSecondsLeft--; /* decrement play bonus timer */
      score -= 100; /* decrement score by 100 for each of the first 100 secs */
   }
   totalPlaySeconds++; /* increment total play time seconds */
   mtflag++; /* update scores */
}

void fixtext()
{
int i,x,y;
uchar ch,*p1,*p2;

   if(!playing) return;
   p1=toptext;
   p2=topwant;
   i=72;
   y=YOFF-36;
   x=XOFF;
   while(i--)
   {
      if(*p1++!=*p2++)
      {
         ch=p1[-1]=p2[-1];
         writechar(x,y,ch ,whitecolor);
         needtoptext=1;
      }
      x+=8;
   }
   p1=bottomtext;
   p2=bottomwant;
   i=72;
   y=YOFF+15*24+24;
   x=XOFF;
   while(i--)
   {
      if(*p1++!=*p2++)
      {
         ch=p1[-1]=p2[-1];
         writechar(x,y,ch ,whitecolor);
         needbottomtext=1;
      }
      x+=8;
   }
}

void writestring(str,x,y,color)
int x,y,color;
uchar *str;
{
   while(*str)
   {
      writechar(x,y,*str++ ,color);
      x+=8;
   }
}

void storesprites()
{
int i;
struct sprite *p;
   p=spritelist;
   for(i=0;i<MAXSPRITES;i++)
   {
      if(p->spriteflags & SPRITEACTIVE)
      {
         store(p->spritex,p->spritey,i);
         p->spriteflags |= SPRITESTORING;
      }
      p++;
   }
}

void restoresprites()
{
int i;
struct sprite *p;
   p=spritelist;
   for(i=0;i<MAXSPRITES;i++)
   {
      if(p->spriteflags & SPRITESTORING)
      {
            restore(p->spritex,p->spritey,i);
            mark(p->spritex,p->spritey);
            p->spriteflags ^= SPRITESTORING;
      }
      p++;
   }
}
void drawsprites()
{
int i;
struct sprite *p;
   p=spritelist+MAXSPRITES;
   for(i=0;i<MAXSPRITES;i++)
   {
      --p;
      if(p->spriteflags & SPRITEACTIVE)
      {
         mark(p->spritex,p->spritey);
         puttile(p->spritex,p->spritey,p->spritefig);
      }
   }
}

struct sprite *newsprite()
{
int i;
struct sprite *sp;

   sp=spritelist;
   for(i=0;i<MAXSPRITES;i++)
      if(!(sp->spriteflags & (SPRITEACTIVE | SPRITESTORING)))
         break;
      else  sp++;
   sp->spriteflags=SPRITEACTIVE;
   sp->spritex=0;
   sp->spritey=0;
   sp->spritefig=0;
   return sp;
}

void initplay()
{
int i,lr;
uchar *p1,*p2,ch;
int flashes[3];
int flashnum;
int moviesize;
struct entity *plent,*enent;

   if(recording) randcount=randcount2%24;
   score=30000;
   bonusSecondsLeft=100;
   cyclesThisSecond=0;
   totalPlaySeconds=0;
   totalPlayCycles=0;
   bestPlayCycles = 0;
   mtflag=1;
   mpoint=movie+20;
   bestname[0]=0;
   bestscore=0;
   besttime=0;
   gotflashing = -1;  /* Dont yet know if this level has flashing objects */
   gothidden = -1;   /* Dont yet know if this level has hidden monsters */
   if(clevel)
      moviesize = getresource (1 + ((clevel-1) << 1), movie, MOVIEMAX+20);
   else
      memcpy(movie,demomovie0,moviesize=sizeof(demomovie0));
   if(moviesize > 0)
   {
      bestscore=movie[0] | (movie[1]<<8) | (movie[2]<<16) | (movie[3]<<24);
      /* Find the playtime of the movie */
      for (mpoint = movie+21, i=moviesize - 21; i > 0; i -= 2, mpoint += 2)
         bestPlayCycles += *mpoint;
      besttime = bestPlayCycles / 60;
      mpoint=movie+20;  /* restore normal mpoint */
   }
   if(recording)
   {
      *mpoint++=randcount;
      *mpoint=0;
   } else
   {
      if(moviesize > 0)
      {
         memcpy(bestname,movie+4,16);
         mpoint=movie+20;
         randcount=*mpoint++;
      }
   }
   for(i=0;i<72;i++)
      toptext[i]=bottomtext[i]=topwant[i]=bottomwant[i]=0;
   lostflag=wonflag=0;
   playflags=0;
   freezing=1;
   for(i=0;i<MAXDIG;i++)
      diggings[i].digtimer=0;
   numenemies=0;
   numgold=0;
   p1=levelbuff;
   p2=levelback;
   flashnum=0;
   hiddennum=0;
   enent=plent=entities;
   for(i=0;i<LEVELSIZE;i++)
   {
      if(i%28 < 14) lr=4; else lr=3;
      movings[i]=0;
      *p2++=ch=*p1;
      if(ch==HIDDEN)
      {
         gothidden = 0;       /* There are some hidden monsters on this level */
         ch=BRICK;
         if(hiddennum<3)
            hiddens[hiddennum++]=i;
      }
      if(ch==ESCAPE) ch=EMPTY;
      if(ch==FLASHING)
      {
         gotflashing = 0;      /* There are some flashing objects on this level */
         ch=GOLD;
         if(flashnum<3)
            flashes[flashnum++]=i;
      }
      if(ch==HERO)
      {
         ch=EMPTY;
         plent->enx=XCONV(i);
         plent->eny=YCONV(i);
         plent->enat=p1;
         plent->enflags=PLAYER;
         plent->endir=-1;
         plent->enwhat=lr;
         plent->enacount=0;
      movings[i]|=plent->enmask=0x80;

      } else if(ch==ENEMY)
      {
         ch=EMPTY;
         numenemies++;
         enent++;
         enent->enx=XCONV(i);
         enent->eny=YCONV(i);
         enent->ensprite=newsprite();
         enent->enat=p1;
         enent->enflags=0;
         enent->enwhat=lr;
         enent->enacount=0;
         movings[i]|=enent->enmask=0x80>>numenemies;
      }
      *p1++=ch;
      if(ch==GOLD) numgold++;
   }
   entities[0].ensprite=newsprite();
   rotnum=numenemies-1;
   rethink();
   if(flashnum)
   {
      i=flashes[randcount%flashnum];
      flashat=levelbuff+i;
      flashsprite=newsprite();
      flashx=XCONV(i);
      flashy=YCONV(i);
      flashtimer=0;
   } else flashat=0;
   sprintf(statuswant,"-100 EACH SEC.  ");
   statustext(statuswant,SDELAY);
}

void maketext()
{
   sprintf(topwant,"LEVEL %04d %-18s SCORE-TIME %05d-%04d  BEST %05d-%04d.%02d ",clevel,bestname,score,totalPlaySeconds,bestscore,besttime,(bestPlayCycles % 60));
   mtflag=0;
}

void initdemo()
{
int err;

   fadeout();
   mode=mode0;
   playing=1;
   recording=0;

   if(!loadlevel(clevel))
      clevel=0;
   if(clevel)
   {
      err = getresource (1 + ((clevel-1) << 1), movie, 20);
      if(err<=0) clevel=0;
   }

   loadlevel(clevel);
   restoresprites();
   initplay();
   paintlevel();
   maketext();
   fixtext();
   changesprites();
   storesprites();
   drawsprites();
   copyup();
   fadein();
   SDL_ShowCursor(SDL_DISABLE);
}

void startgame()
{
/* int i;
 */
   fadeout();
   playing=1;
   recording=1;

   restoresprites();
   initplay();
   paintlevel();
   maketext();
   fixtext();
   changesprites();
   storesprites();
   drawsprites();
   copyup();
   fadein();
   SDL_ShowCursor(SDL_DISABLE);
}

void spritesoff()
{
struct entity *en;
struct sprite *sp;
struct dig *adig;
int i;

   restoresprites();
   en=entities;
   for(i=0;i<numenemies+1;i++)
      SPRITEOFF((en++)->ensprite);
   adig=diggings;
   for(i=0;i<MAXDIG;i++)
   {
      if(adig->digtimer && (sp=adig->digsprite))
         SPRITEOFF(sp);
      adig++;
   }
   if(flashat) {SPRITEOFF(flashsprite);flashat=0;}
}

void statustext(uchar * txt,int sdelay)
{
   ptx=480;
   pty=YOFF+16*TY;
   texthere(txt);
   bonusPenaltyDelay = sdelay;
	 copyupxysize(480,YOFF+16*TY,15*8,12);
}
void texthere(uchar *txt) /* uses global vars ptx and pty for position */
{
uchar ch;
   while ((ch=*txt++))
   {
      writechar(ptx,pty,ch ,whitecolor);
      ptx+=8;
   }
}

void lefttext(uchar *txt)
{
int ptx;
uchar ch;

   ptx=140;
   while ((ch=*txt++))
   {
      writechar(ptx,pty,ch ,whitecolor);
      ptx+=8;
   }
   pty+=16;
}

void centertext (uchar *txt)
{
int   ptx;
uchar ch;

   ptx=320-(8*(strlen(txt)/2));
   while((ch=*txt++))
   {
      writechar(ptx,pty,ch ,whitecolor);
      ptx+=8;
   }
   pty+=16;
}

void nextlevel (int type)
{
uchar ttt[64];

   fadeout();
   spritesoff();

   if(type)
   {
      clear();
      pty=130;
      centertext("YOU PASSED THE LEVEL!");
      strcpy(ttt,"HIDDEN MONSTER - ");
      if (gothidden == 1)
         strcat(ttt,"YES\n");
      else if (gothidden == -1)
         strcat(ttt,"N/A\n");
      else
         strcat(ttt," NO\n");
      centertext(ttt);
      strcpy(ttt,"FLASHING FIRST - ");
      if (gotflashing == 1)
         strcat(ttt,"YES\n");
      else if (gotflashing == -1)
         strcat(ttt,"N/A\n");
      else
         strcat(ttt," NO\n");
      centertext(ttt);
      centertext("-----------");
      sprintf(ttt,"TIME BONUS     %03d00",bonusSecondsLeft);
      centertext(ttt);
      if(!(playflags&HASTRAPPED))
      {
         centertext("NO TRAPPING    20000\n");
      } else if(!(playflags&HASKILLED))
      {
         centertext("NO KILLING     10000\n");
      }
      centertext("-----------");
      sprintf(ttt,"YOUR SCORE     %05d",score);
      centertext(ttt);
      sprintf(ttt,"BEST SCORE     %05d",bestscore);
      centertext(ttt);
      centertext("-----------");
      sprintf(ttt,"YOUR TIME %04d.%02d SECS.",totalPlaySeconds,(totalPlayCycles % 60));
      centertext(ttt);
      sprintf(ttt,"BEST TIME %04d.%02d SECS.",besttime,(bestPlayCycles % 60));
      centertext(ttt);
      if(score>bestscore || ((score == bestscore) && (totalPlayCycles < bestPlayCycles)))
      {
         centertext("");
         if (score == bestscore)
            sprintf(ttt,"SCORE TIED WITH A BETTER TIME ON LEVEL %04d!",clevel);
         else
            sprintf(ttt,"YOU JUST GOT THE HIGH SCORE FOR LEVEL %04d!!!",clevel);
         centertext(ttt);
         movie[0]=score;
         movie[1]=score>>8;
         movie[2]=score>>16;
         movie[3]=score>>24;
         memcpy(movie+4,playername,16);
         if(clevel)
            putresource(((clevel-1)<<1)+1,movie,(mpoint-movie)+2);
      }
      pty=YOFF+16*TY;
      sprintf(ttt,"PRESS SPACE FOR NEXT LEVEL");
      centertext(ttt);
      fadein();
      copyup();
      for(;;)
      {
         SDL_WaitEvent(NULL);
                        resetinput();
         scaninput();
          /* New Function - F12 to overwrite the demo with this last game */
                        if(checkdown(SDLK_F12)) 
                        {
                           movie[0]=score;
                           movie[1]=score>>8;
                           movie[2]=score>>16;
                           movie[3]=score>>24;
                           memcpy(movie+4,playername,16);
                           if(clevel)
                              putresource(((clevel-1)<<1)+1,movie,mpoint-movie+2);
                           break;
                        }
         if(checkdown(SDLK_SPACE) || checkdown(SDLK_ESCAPE))  /* space or Escape */
            break;
         if(checkdown(SDLK_x) && (checkpressed(SDLK_RALT) || checkpressed(SDLK_LALT))) /* Alt-X */
            exit(0);
      }
      fadeout();
      clear();
   }

   clevel++;
   if(!loadlevel(clevel))
   {
      clevel=1;
      loadlevel(clevel);
   }
   initplay();
   paintlevel();
   maketext();
   fixtext();
   changesprites();
   storesprites();
   drawsprites();
   copyup();
   fadein();
}

void samelevel()
{
int i;
   fadeout();
   erasetile(32,440); /* unmark flashing */
   erasetile(56,440); /* unmark hidden */
   erasetile(80,440); /* unmark ladders */
   erasetile(104,440); /* unmark penalties */
   spritesoff();
   for(i=0;i<LEVELSIZE;i++)
      levelbuff[i]=levelback[i];
   initplay();
   paintlevel();
   changesprites();
   storesprites();
   drawsprites();
   copyup();
   fadein();
}

void endplay()
{
int i;

   quiet();
   restoresprites();
   spritesoff();
   playing=0;
   for(i=0;i<LEVELSIZE;i++) levelbuff[i]=levelback[i];
}

int whichfig (struct entity *en)
{
int a,what;
uchar ch;

   ch=*COMPXY(en->enx,en->eny);
   a=en->enacount>>1;
   what=en->enwhat;
   switch(what)
   {
   case 0:
      if(ch==LADDER)
         a+=72;
      else a+=12;
      break;
   case 1:
      a+=72;            /* climbing up */
      break;
   case 2:
      if(en->enflags & FALLING)
         a+=60;         /* falling */
      else
         a+=72;         /* climbing down */
      break;
   case 3:
      if(ch==RAIL)
         a+=36;         /* climbing left on rail */
      else
         a+=12;         /* running left */
      break;
   case 4:
      if(ch==RAIL)
         a+=48;         /* climbing right on rail */
      else
         a+=24;         /* running right */
      break;
   case 5:
      a+=84;
      break;
   case 6:
      a+=90;
      break;
   }
   return a;
}

void changesprites()
{
struct sprite *sp;
struct entity *en;
struct dig *adig;
int time;
int i;

   if(playing) {

   en=entities;
   sp=en->ensprite;
   sp->spritex=en->enx;
   sp->spritey=en->eny;
   i=sp->spritefig=whichfig(en)+96;
/* if(i==12+96+3 || i==24+96+3 || i==12+96+9 || i==24+96+9) makesound(4);*/
   for(i=0;i<numenemies;i++)
   {
      ++en;
      sp=en->ensprite;
      sp->spritex=en->enx;
      sp->spritey=en->eny;
      sp->spritefig=whichfig(en)+192;
      if(en->enflags & HIDDENTYPE) sp->spritefig+=96;
   }
   adig=diggings;
   for(i=0;i<MAXDIG;i++)
   {
      time=adig->digtimer;
      sp=adig->digsprite;
      if(time>=1 && time<=DIGTIME)
      {
         sp->spritex=adig->digx;
         sp->spritey=adig->digy;
         sp->spritefig=DIGFIGS+1+((time-1)>>2);
      } else if(time>=DIGLIFE-DIGTIME)
      {
         sp->spritex=adig->digx;
         sp->spritey=adig->digy;
         sp->spritefig=DIGFIGS+((DIGLIFE-time-1)>>2);
      }
      adig++;
   }
   if(flashat)
   {
      flashsprite->spritex=flashx;
      flashsprite->spritey=flashy;
      if(flashtimer<8) flashsprite->spritefig=FLASHFIGS+(flashtimer>>1);
      else if(flashtimer<16) flashsprite->spritefig=FLASHFIGS+7-(flashtimer>>1);
      else  flashsprite->spritefig=DIGFIGS; /* empty fig */
      flashtimer++;
      flashtimer&=63;
   }
   }
}

void fadein()
{
}
void fadeout()
{
}

int mxloc,myloc;

int iterate()
{
   randcount2++;
   if(gottimer >= 1)gottimer = 0;
   resetinput();
	 SDL_Delay(10);
   do 
   {
      if ( scaninput() )
         return 1;
      if((checkpressed(SDLK_LALT) || checkpressed(SDLK_RALT)) && checkdown(SDLK_x))
			{
				quiet();
        return 1; /* alt-x */
			}
   } while(paused || (gottimer < 1));

   mbuttons=(checkbutton(1) ? 1 : 0) | (checkbutton(3) ? 2 : 0);
   mbuttons2=(checkbuttondown(1) ? 1 : 0) | (checkbuttondown(3) ? 2 : 0);

   xpos=getmousex();
   ypos=getmousey();
   if(xpos<BLOCKX/2) xpos=BLOCKX/2;
   if(xpos>IXSIZE-BLOCKX/2) xpos=IXSIZE-BLOCKX/2;
   if(ypos<BLOCKY/2) ypos=BLOCKY/2;
   if(ypos>IYSIZE-BLOCKY/2) ypos=IYSIZE-BLOCKY/2;
   curx=xpos;
   cury=ypos;
   mxloc=xpos-BLOCKX/2;
   myloc=ypos-BLOCKY/2;

   restoresprites();
   animprocess();
   editprocess();
   movement();
   dodiggings();
   dectime();
   if(playing && mtflag) maketext();
   fixtext();
   changesprites();
   storesprites();
   drawsprites();
   if(needwhole)
   {
      markpoint=marks;
      needwhole=0;
      copyup();
   } else
   {
      domarks();
      if(needtoptext)
      {
         needtoptext=0;
         copyupxysize(TEXTX,TOPTEXTY,8*72,12);
      }
      if(needbottomtext)
      {
         needbottomtext=0;
         copyupxysize(TEXTX,BOTTOMTEXTY,8*72,12);
      }
   }
   mode();
   if(checkdown(SDLK_SYSREQ))
      capturescreen();
   return 0;
}


uchar *getgfx(int num)
{
uchar *p;
gfxset *gs;

   p=doiff(gfxnames[num]);
   if(p)
   {
      sprintf(temp,"%s:%s",gfxnames[num],p);
      return temp;
   }
   gs=gfxsets+num;
   if(!gs->gs_pic)
      gs->gs_pic=malloc(64000);
   if(!gs->gs_pic)
      return "Could not allocate memory for gfx set.\n";
   memcpy(gs->gs_pic,picloc,64000);
   memcpy(gs->gs_colormap,colormap,768);
   return 0;
}


void setint(char *ip,int *op)
{
   sscanf(ip,"%x",op);
}

void setstring(char *ip,char *op)
{
   strcpy(op,ip);
}


void getconfig()
{
int i,j,md;
uchar *p,ch;
uchar name[16];
void **pnt=NULL;
/* uchar ahex;
 */
char name2[256];
void (*func)()=NULL;
char *op=NULL;

   sprintf(name2,"%s/%s/%s",localname,localdirname,rcname);
   file=open(name2,O_RDONLY);
   if(file==-1) return;
   i=read(file,temp,1023);
   temp[i]=0;
   p=temp;
   md=0;
   for(;;)
   {
      ch=tolower(*p++);
      if(!ch) break;
      if(ch==13) continue;
      switch(md)
      {
      case 0:
         if(ch==10) break;
         if(ch=='#' || ch<'a' || ch>'z')
         {
            md=1;
            break;
         }
         i=0;
         md=2;
      case 2:
         if(ch<'a' || ch>'z')
         {
            if(ch=='=')
            {
               name[i]=0;
               i=0;
               pnt=configtab;
               j=0;
               while(*pnt)
               {
                  if(!strcmp(*pnt++,name))
                     break;
                  j++;
                  pnt+=2;
               }
               op=name2;
               func=pnt[1];
               md=3;
            } else
               md=0;
            break;
         }
         if(i<15)
         {
            name[i++]=ch;
         } else
            md=0;
         break;
      case 1:
         if(ch==10)
            md=0;
         break;
      case 3:
         if(ch && ch!=10)
            *op++=ch;
         else
         {
            *op=0;
            if(func)
               func(name2,*pnt);
            md=0;
         }
         break;
      }
   }
}

void remslash(char *str)
{
int i;
   i=0;
   while(*str) {i++;str++;}
   while(i-- && *--str=='/') *str=0;
}

int dupfile(char *src, char *dest)
{
int input,output,len,res;
char buff[1024];

   input=open(src,O_RDONLY|O_BINARY);
   if(input==-1) return -1;
   output=open(dest,O_WRONLY|O_CREAT|O_TRUNC|O_BINARY,0600);
   if(output==-1)
   {
      close(input);
      return -2;
   }
   do
   {
      len=read(input,buff,1024);
      res=write(output,buff,len);
      if(len!=res)
      {
         close(input);
         close(output);
         return -3;
      }
   } while(len);
   close(input);
   close(output);
   return 0;
}

static int ehand=-1;
void eprintf(char *str, ...)
{
   char buff[128];
   va_list ap;

   va_start(ap, str);
   vsprintf(buff,str,ap);
   va_end(ap);

   if(ehand==-1)
      ehand=open("SCAVINFO.LOG",O_WRONLY|O_CREAT|O_TRUNC,0644);
   if(ehand!=-1)
      write(ehand,buff,strlen(buff));
}

void abortall(int code)
{
	 fadeout();
   scavfree();
   fflush(0);
   exit(code);
}

void finddata()
{
char *p;
int file,err;
int i;
struct stat statbuf;

   strcpy(libpath,LIBPATH);
   strcpy(localdirname,LOCALDIRNAME);

   p=getenv(ENVHOME);
   if(!p)
   {
      eprintf("Cannot find %s environment variable!\n",ENVHOME);
      strcpy(localname,".");
   } else
   {
      strcpy(localname,p);
      remslash(localname);
   }
   sprintf(temp,"%s/%s",localname,localdirname);
   i=stat(temp,&statbuf);
   if(i!=0)
   {
      eprintf("No directory %s/!!! Setting one up...\n",temp);
#if defined(__WIN32__) || defined(WIN32)
      err=mkdir(temp);
#else
      err=mkdir(temp,00700);
#endif
      if(err==-1)
      {
         eprintf("Failed to create directory %s, exiting\n",temp);
         abortall(1);
      }
   }

   sprintf(resourcename,"%s/%s/%s",localname,localdirname,LevelsName);
   sprintf(newresname,"%s/%s/%s",localname,localdirname,NEWLEVELSNAME);
   file=open(resourcename,O_RDONLY|O_BINARY);
   if(file==-1)
   {
      eprintf("No %s, setting one up...\n",resourcename);
      eprintf("Trying to copy %s...",temp);
      for(i=0;;)
      {
         if(!expandpath(temp,LevelsName,i))
         {
            eprintf("failed to copy\n");
            abortall(1);
         }
         err=dupfile(temp,resourcename);
         if(!err) break;
         ++i;
      }
      eprintf("...copied.\n");
   } else close(file);
   makercname(temp);
   file=open(temp,O_RDONLY|O_BINARY);
   if(file==-1)
   {
      eprintf("No %s, setting one up...\n",temp);
      strcpy(gfxname0,"redbrick.lbm");
      strcpy(gfxname1,"regularguy.lbm");
      strcpy(gfxname2,"badguy.lbm");
      strcpy(gfxname3,"spiral.lbm");
      upkey=SDLK_UP;
      downkey=SDLK_DOWN;
      leftkey=SDLK_LEFT;
      rightkey=SDLK_RIGHT;
      digleftkey=SDLK_LCTRL;
      digrightkey=SDLK_LALT;
      if(!makercfile(temp))
      {
         eprintf("Couldn't create %s\n",temp);
         abortall(1);
      }
   }
}

void makercname(char *str)
{
   sprintf(str,"%s/%s/%s",localname,localdirname,rcname);
}

int makercfile(char *str)
{
FILE *file;
   file=fopen(str,"w");
   if(!file) return 0;
   fprintf(file,"background=%s\n",gfxname0);
   fprintf(file,"hero=%s\n",gfxname1);
   fprintf(file,"enemy=%s\n",gfxname2);
   fprintf(file,"hidden=%s\n",gfxname3);
   fprintf(file,"upkey=%x\n",upkey);
   fprintf(file,"downkey=%x\n",downkey);
   fprintf(file,"leftkey=%x\n",leftkey);
   fprintf(file,"rightkey=%x\n",rightkey);
   fprintf(file,"digleftkey=%x\n",digleftkey);
   fprintf(file,"digrightkey=%x\n",digrightkey);
   fclose(file);
   return 1;
}
unsigned char havepulse;
static Uint32 sdlhandler(Uint32 time)
{
   SDL_Event timeevent;
   
   timeevent.type = SDL_USEREVENT;

   hc++;

   SDL_PeepEvents(&timeevent, 1, SDL_ADDEVENT, 0);

   return time;
}

void pulseon(void)
{
   if(havepulse) return;
   havepulse=1;
   SDL_SetTimer(20,sdlhandler);
   hc=0;
}
void pulseoff(void)
{
   if(!havepulse) return;
   havepulse=0;
   SDL_SetTimer(0,NULL);
}

void scavfree(void)  /* Frees up all malloc'ed memory */
{
   int i;
   free(picloc);picloc=NULL;
   free(block64);block64=NULL;
   free(storageblock);storageblock=NULL;
   free(figureblock);figureblock=NULL;
   for (i=0; i < NUMGFX; i++)
   {
      free(gfxsets[i].gs_pic);
      gfxsets[i].gs_pic=NULL;
   }
}
void scavcleanup(void)
{
	 quiet();
printf("End.\n");
	 fadeout();
   fflush(0);
   pulseoff();
   if (SoundEnable) soundclose();
   SDL_Quit();
   scavfree(); /* Free up memory */
}

uint32_t ScavFullScreen=SDL_FULLSCREEN;

int main (int argc, char **argv) 
{
   int i,j;
   int c;
   int nonLevel;                  /* Invalid level number flag */
   char * optp;
   uchar *err;
   memset((char *)gfxsets,0,sizeof(gfxset)*NUMGFX); //Initialize pointers
   strcpy(rcname,RCNAME);
   strcpy(LevelsName,LEVELSNAME); /* Normally use default name */

#if defined(__WIN32__) || defined(WIN32)
   /* Crude command line options for windows (no getopt function) */
   if (argc != 1)  /* command line option used */
   {
      /* Check for -w option */
      if (argc == 2 && 0 == strcmp("-w",argv[1]))
      {
         ScavFullScreen = 0;   /* Run in a window instead */
      }
			/* Check for -q	option */
			if (argc == 2 && 0 ==strcmp("=q",argv[1]))
			{
				SoundEnable = 0;			//Turn Sound Off
			}
      /* Check for -s option */
      if (argc == 2 && 0 ==strcmp("-s",argv[1]))
      {
         strcpy(LevelsName,MASTERNAME);  /* User is stuck show him masters file */
      }
      /* Check for -c option */
      if (argc == 3 && 0 == strcmp("-c",argv[1]))
      {
         strcpy(rcname,argv[2]);
      }
      /* Check for -l option */
      if (argc == 3 && (0 == strcmp("-l",argv[1]) || 0 == strcmp("-s",argv[1])))
      {
         if (0 == strcmp("-s",argv[1]))
            strcpy(LevelsName,MASTERNAME);/* User is stuck show him masters file */
         nonLevel = 0;                    /* Assume that no digits are non numeric */
           i = strlen(argv[2]);
           optp = argv[2];
           if (i > 0 && i <= 3)             /* Valid number of digits for level number */
           {
              while(*optp)
                 if(!isdigit(*optp++)) nonLevel++;   /* Check if each is a numeral */
              if (nonLevel == 0)
              {
                 clevel = atoi(argv[2]);
                 if (clevel < 1 || clevel > 400)nonLevel++;
                 ilevel = clevel;      /* if there is no movie then F4 still goes there */
              }
           }
           else nonLevel++;
           if (nonLevel)
           {
              exit(0);
           }
      } /* end of if -l option */
   }    /* end of command line option used */
#else
   while (1) 
   {
       int option_index = 0;
       opterr = 0;
       static struct option long_options[] = {
           {"window", 0, 0, 'w'},
           {"help", 0, 0, 'h'},
           {"version", 0, 0, 'v'},
           {"config", 1, 0, 'c'},
           {"level", 1, 0, 'l'},
           {"Level", 1, 0, 'l'},
           {"stuck", 0, 0, 's'},
					 {"quiet", 0, 0, 'q'},
           {0, 0, 0, 0}
       };

       c = getopt_long (argc, argv, "hvwsqc:l:L:",
                long_options, &option_index);
       if (c == -1)
           break;

       switch (c) {
       case 'v':
           printf ("\n"VERSION"\n\n");
           exit(0);
       case 'w':
           ScavFullScreen = 0;   /* Run in a window instead */
           break;
       case 'c':
           strcpy(rcname,optarg);
           break;
       case 's':
           strcpy(LevelsName,MASTERNAME);  /* User is stuck show him masters file */
           break;
			 case 'q':
					 SoundEnable = 0;								// Turn Sound Off
					 break;
       case 'l':
       case 'L':                            /* Capital L too since this option is mentioned
                                               in the main menu (which has only upper case fonts) */
           nonLevel = 0;                    /* Assume that no digits are non numeric */
           i = strlen(optarg);
           optp = optarg;
           if (i > 0 && i <= 3)             /* Valid number of digits for level number */
           {
              while(*optp)
                 if(!isdigit(*optp++)) nonLevel++;   /* Check if each is a numeral */
              if (nonLevel == 0)
              {
                 clevel = atoi(optarg);
                 if (clevel < 1 || clevel > 400)nonLevel++;
                 ilevel = clevel;      /* if there is no movie then F4 still goes there */
              }
           }
           else nonLevel++;
           if (nonLevel)
           {
              printf("\nLevel numbers must be numeric, ranging from 1 to 400\n\n");
              exit(1);
           }
           break;
       case '?':
       case 'h':
       default:
           printf ("\n"
                   "SDL Scavenger command line options:\n\n"
                   "-h, --help    Show this help text and exit.\n\n"
                   "-c file, --config file\n"
                   "              Use alternate file for scavenger configuration.\n"
                   "              See scavrc in your ~/.scavenger directory for the\n"
                   "              proper config file format.\n\n"
                   "-w, --window  Run scavenger in a window instead of full screen.\n\n"
                   "-l 125,\n"
                   "--level 125   Start the game on level 125. Press F4 when the\n"
                   "              game starts to jump to this level.  The maximum\n"
                   "              level number is 400, but only 200 levels are\n"
                   "              predefined.  Levels 201 through 400 are available\n"
                   "              for user defined levels.\n\n"
                   "-v, --version Show the scavenger version and exit.\n\n"
                   "-s, --stuck   Play scavenger with the pre-solved movies included\n"
                   "              If you are convinced that a level is impossible, use\n"
                   "              this option to see how the Masters do it. This option\n"
                   "              can be used with the -l option to go straight to the\n"
                   "              level you are stuck on.  See if you can best the score,\n"
                   "              or playing time of the Masters!\n\n");
           exit(0);
       } /* end of option switch */
   } /* end of option while loop */
#endif

   finddata();

   opengfx(argc,argv);
	 if (SoundEnable)
	 {
		 if (soundopen())
		 {
				SDL_Quit();
				scavfree();
				exit(4);
		 }
	 }

   getconfig();
   animinit();
   editinit();
   fontinit();
   err=getenv(ENVUSER);
   if(err)
      strncpy(playername,err,16);
   else
      strcpy(playername,"anonymous");
   sprintf(temp,"%s/%s/%s",localname,localdirname,PLAYERNAME);
   file=open(temp,O_RDONLY);
   if(file!=-1)
   {
      read(file,playername,16);
      close(file);
   }
   for(i=0;i<16;i++) smap[i]=0;
   smap[BRICK]=1;
   smap[CEMENT]=1;
   smap[HIDDEN]=1;
   smap[FAKE]=1;
   smap[DUGBRICK]=1;
   for(i=0;i<LEVELSIZE;i++) randoms[i]=rand() & 3;

   for(i=0;i<MAXSPRITES;i++) spritelist[i].spriteflags=0;
   markpoint=marks;

   dumpgfx();
   for(i=0;i<NUMGFX;i++)
   {
      err=getgfx(i);
      if(err)
      {
         puts(err);
         return 1;
      }
      createinout(i);
   }
   getcolors();
   getfigures();

   for(i=0;i<640;i++)
      xcomp[i]=(i-XOFF+2*TX+(TX/2))/TX;
   for(i=0;i<480;i++)
   {
      ycomp[i]=(i-YOFF+TY+(TY/2))/TY;
      ycomp2[i]=ycomp[i]*28;
   }
   for(i=0;i<640;i++)
   {
      j=(i+TX-(XOFF%TX)) % TX;
      if(j==0) centerx[i]=0;
      else if(j<TX/2) centerx[i]=-2;
      else centerx[i]=2;
   }
   for(i=0;i<480;i++)
   {
      j=(i+TY-(YOFF%TY)) % TY;
      if(j==0) centery[i]=0;
      else if(j<TY/2) centery[i]=-2;
      else centery[i]=2;
   }

   changesprites();

   initdemo();

   pulseon();

   while(!iterate());

   pulseoff();

   if (SoundEnable) soundclose();
   if(testval>=0) eprintf("Testval=%lx\n",testval);
   exit(0);
}

void createhidden(int at)
{
struct entity *enent;

   rotnum++;
   numenemies++;
   enent=entities+numenemies;
   enent->enx=XCONV(at);
   enent->eny=YCONV(at);
   enent->ensprite=newsprite();
   enent->enat=levelbuff+at;
   enent->enflags=HIDDENTYPE | HOLDING | TRAPPED;
   enent->enwhat=3;
   enent->enacount=0;
   enent->entimer=0;
   enent->enat=enent->enloc1=at+levelbuff;
   movings[at]|=enent->enmask=0x80>>numenemies;
}


void newdig(uchar *at)
{
int i,j;
struct dig *adig;
int x,y;

   i=at-levelbuff;

   digsound=makesound(1);

   for(j=0;j<hiddennum;j++)
   {
      if(i==hiddens[j])
      {
         hiddennum--;
         hiddens[j]=hiddens[hiddennum];
         if(!hiddennum || (randcount&1)) /* 50/50 chance to find hidden each time but last */
         {
            hiddennum=0;
            createhidden(i);
         }
      }
   }
   x=XCONV(i);
   y=YCONV(i);
   adig=diggings;
   for(i=0;i<MAXDIG;i++)
      if(adig->digtimer==0) break;
      else adig++;
   if(i==MAXDIG) return;
   adig->digx=x;
   adig->digy=y;
   adig->digat=at;
   adig->digtimer=-1;
   adig->digsprite=0;
}

int onenemy(struct entity *pl, int what)
{
struct entity *en;
int i;
int px,py;
int dx,dy;

   en=entities+1;
   px=pl->enx;
   py=pl->eny;

   i=numenemies;
   while(i--)
   {
      dx=en->enx-px;
      dy=en->eny-py;
      if(dx<0) dx=-dx;
      if(dy<=28 && dy>=16 && dx<18)
      {
         if(!centery[pl->eny] && (what==3 || what==4))
         {
            pl->entimer=0;
            pl->enflags|=HELDSTABLE;
            return 1;
         }
         if(dy<=24) return 1;
      }
      en++;
   }
   i=movings[28+COMPXY(px,py)-levelbuff]&0x7f;
   if(i)
   {
      en=entities+1;
      while(!(i&en->enmask)) en++;
      if(py+24==en->eny) return 1;
   }

   return 0;   
}

void fix(uchar *where)
{
uchar v;
uchar ch;
   ch=*where;
   if(ch==BORDER) return;
   addmodify(where-levelbuff,12*randoms[where-levelbuff]);
   v=smap[*(where-28)];
   v|=smap[*(where-29)]<<1;
   v|=smap[*(where-1)]<<2;
   if(v) addmodifyq(where-levelbuff,SHADOWFIGS+v);
   if(*where!=EMPTY) addmodifyq(where-levelbuff,
      ch!=HAT ? ch+12*randoms[where-levelbuff] : HATFIGS);
}

void doplayer(struct entity *pl, int what)
{
uchar *at;
uchar ch;
uchar *oldat;
uchar stillheld=0;
int cy;
int flags;

   if(pl->enflags & FALLING)
      pl->enflags |= OLDFALLING;
   else
      pl->enflags &= 0xffff-OLDFALLING;
   if(recording && mpoint<mend)
   {
      if(*mpoint)
      {
         if(what==*(mpoint+1) && *mpoint!=255)
            ++*mpoint;
         else
         {
            mpoint+=2;
            *mpoint=1;
            mpoint[1]=what;
         }
      } else
      {
         *mpoint=1;
         mpoint[1]=what;
      }
   }
   oldat=COMPXY(pl->enx,pl->eny);
   cy=centery[pl->eny];
   if(pl->enflags & DIGGING)  /* suspend player while digging */
   {
      pl->enx+=centerx[pl->enx];
      pl->eny+=cy;
      pl->entimer++;
      if(pl->entimer==DIGTIME)
      {
         pl->enflags&=0xffff-DIGGING;
      } else
      {
         what=0;
         goto dpdone;
      }
   }

   if((pl->enflags & HELDSTABLE) && pl->entimer++ <HELDLIMIT && what==pl->endir) stillheld++;
   if(!ISSTABLE(*COMPXY(pl->enx,pl->eny+TY/2)) &&
      *COMPXY(pl->enx,pl->eny)!=3 &&
      !(*oldat==RAIL && cy==0 && what!=2) &&
      !(pl->enflags&DIGGING) && !onenemy(pl,what) && !stillheld)
   {
      what=0;
      pl->enflags|=FALLING;
   } else pl->enflags&=0xffff-FALLING;
   switch(what)
   {
   case 0:
      if(pl->enflags & FALLING)
      {
         pl->eny+=2;
         pl->enx+=centerx[pl->enx];
      }
      break;
   case 1:
      if(!numgold && pl->eny==YOFF && *COMPXY(pl->enx,pl->eny)==3)
      {
         wonflag++;
         return;
      }
      if(ISENTERABLE(*COMPXY(pl->enx,pl->eny-TY/2-2)) &&
         (*COMPXY(pl->enx,pl->eny)==3 || *COMPXY(pl->enx,pl->eny+TY/2-2)==3) )
      {
         pl->eny-=2;
         pl->enx+=centerx[pl->enx];
      } else what=0;
      break;
   case 2:
      ch=*COMPXY(pl->enx,pl->eny+TY/2);
      if(ISENTERABLE(ch) || ch==5)
      {
         pl->eny+=2;
         pl->enx+=centerx[pl->enx];
      } else what=0;
      break;
   case 3:
      if(pl->enflags & HELDSTABLE && pl->entimer==0)
         pl->endir=3;
      if(ISENTERABLE(*COMPXY(pl->enx-TX/2-2,pl->eny)))
      {
         pl->enx-=2;
         pl->eny+=cy;
      } else what=0;
      break;
   case 4:
      if(pl->enflags & HELDSTABLE && pl->entimer==0)
         pl->endir=4;
      if(ISENTERABLE(*COMPXY(pl->enx+TX/2,pl->eny)))
      {
         pl->enx+=2;
         pl->eny+=cy;
      } else what=0;
      break;
   case 5:
   case 6:
      at=COMPXY(pl->enx,pl->eny);
      at+= what==5 ? -1 : 1;
      if(*(at+28)==1 && (*at==0 || *at==DUGBRICK) && !(pl->enflags & FALLING) && !(at[(movings-levelbuff)]&0x7f))
      {
         newdig(at+28);
         pl->enflags|=DIGGING;
         pl->entimer=0;
         pl->enwhat=what;  /* start digging animation */
         pl->enacount=0;
         break;
      } else what=0;
      what=0;
      break;
   }
dpdone:
   at=COMPXY(pl->enx,pl->eny);
   if(*at==BRICK) lostflag++;
   if((*at==GOLD || *at==HAT) && centerx[pl->enx]==0 && centery[pl->eny]==0)
   {
      makesound(2);
      if(*at==GOLD)
      {
         *at=EMPTY;
         if(flashat!=at)
         {
            score+=250;
         }
         else
         {
            score+=8000;
            gotflashing = 1;
            puttile(32,440,11+(12*randoms[at-levelbuff])); /* mark flashing as gotten */
						copyupxysize(32,440,TX,TY);
            sprintf(statuswant,"+8000 Flashing ");
            statustext(statuswant,SDELAY);
         }
         mtflag++;
         fix(at);
         decgold();
         if(flashat)
         {
            flashat=0;
            SPRITEOFF(flashsprite);
         }
      } else
      {
         *at=EMPTY;
         score+=10000;
         gothidden = 1;
         puttile(56,440,76); /* mark hidden as gotten */
				 copyupxysize(56,440,TX,TY);
         sprintf(statuswant,"+10000 Hidden  ");
         statustext(statuswant,SDELAY);
         mtflag++;
         fix(at);
      }
   }
   if(at!=oldat)
   {
      calced=0;
      movings[oldat-levelbuff]&=0xff-pl->enmask;
      movings[at-levelbuff]|=pl->enmask;
   }
   if(movings[at-levelbuff]&0x7f) lostflag++;
   if((pl->enflags & DIGGING) && pl->enwhat>=5) {
      if (++pl->enacount >= 12) {   /* digging animation */
         pl->enwhat-=2;    /* digging animation done */
         pl->enacount=0;
         goto dpdone2;
      }
   } else if (what) pl->enacount++;
   else pl->enacount=0;
   if(pl->enacount>=24) pl->enacount=0;
   if(what) pl->enwhat=what;
dpdone2:
   flags=pl->enflags;
   if((flags&FALLING) && !(flags&OLDFALLING)) fallsound=makesound(0);
   if(!(flags&FALLING) && (flags&OLDFALLING)) stopsound(fallsound);
}

void addmodify (int where, int what)
{
int x,y;
   x=XCONV(where);
   y=YCONV(where);
   mark(x,y);
   puttile(x,y,what);
}

void addmodifyq (int where, int what)
{
   puttile(XCONV(where),YCONV(where),what);
}

void decgold()
{
int i;
   numgold--;
   if(numgold) return;
   puttile(80,440,3); /* mark ladders as gotten */
   copyupxysize(80,440,TX,TY);  //copyupxysize (indicator tiles area)
	 statustext("SAFE TO EXIT",SDELAY);
   for(i=0;i<LEVELSIZE;i++)
   {
      if(levelback[i]==ESCAPE)
      {
         levelbuff[i]=LADDER;
         addmodify(i,LADDER + 12*randoms[i]);
      }
   }
   rethink();
}

void dodiggings()
{
int i;
struct dig *adig;
int time;
struct entity *en;
uchar ch;

   if((!playing) || freezing) return;
   adig=diggings;
   for(i=0;i<MAXDIG;i++,adig++)
   {
      if(adig->digtimer)
      {
         time= ++adig->digtimer;
         if(!time) time=++adig->digtimer;
         if(time<DIGTIME/2)
         {
            if(*(adig->digat-28)==BRICK || movings[adig->digat-levelbuff-28])
            {
               stopsound(digsound);

               *adig->digat=BRICK;
               if(adig->digsprite)
                  SPRITEOFF(adig->digsprite);
               adig->digsprite=0;
               entities[0].enflags &=0xffff-DIGGING;
               adig->digtimer=0;
               continue;
            }
         }
         if(time==1 || time==DIGLIFE-DIGTIME)
         {
            if(time==1) *adig->digat=CEMENT;
            adig->digsprite=newsprite();
            if(time!=1) addmodify(adig->digat-levelbuff,BRICK + 12*randoms[adig->digat-levelbuff]);
         } else if(time==DIGTIME+1 || time==DIGLIFE)
         {
            SPRITEOFF(adig->digsprite);
            adig->digsprite=0;
            if(time==DIGLIFE)
            {
               adig->digtimer=0;
               *adig->digat=BRICK;
               closebrick(adig->digat);
               if((ch=(movings[adig->digat-levelbuff] & 0x7f)))
               {
                  en=entities+1;
                  while(!(ch & en->enmask)) en++;
                  killenemy(en);
               }
            } else
            {
               if(movings[adig->digat-levelbuff] & 0x7f)
               {
                  *adig->digat=CEMENT;
               } else
               {
                  *adig->digat=DUGBRICK;
                  openbrick(adig->digat);
               }
               addmodify(adig->digat-levelbuff,DIGFIGS+6);
            }
         }
      }
   }
}

void rethink()
{
int i,j,b1,b2,sb;
uchar ch1,ch2;
uchar *p,*p2;

   p=levelbuff+30;
   for(i=0;i<LX;i++)
   {
      cantascend[i]=1;
      cantdescend[i]=enterable[i]=stable[i]=0;
      p2=p;
      for(j=1;j<=LY;j++)
      {
         sb=bits[j];
         ch1=*p2;
         b1=bits[ch1];
         ch2=*(p2+28);
         b2=bits[ch2];
         if(b1 & (FEMPTY | FLADDER | FRAIL | FESCAPE | FGOLD | FFLASHING | FHAT | FDUGBRICK)) enterable[i]|=sb;
         if(ch1!=3) cantascend[i]|=sb;
         if(b2 & (FBRICK | FCEMENT | FFAKE | FDUGBRICK | FBORDER)) cantdescend[i]|=sb;
         if((b1 & (FRAIL | FLADDER)) || (b2 & (FBRICK | FCEMENT | FLADDER | FFAKE | FHIDDEN | FDUGBRICK | FBORDER)))
               stable[i]|=sb;
         p2+=28;
      }
      p++;
   }
   enterable[-1]=0;
   enterable[LX]=0;
   calced=0;
}

void openbrick(uchar *where)
{
int i;
   i=where-levelbuff-2;
   enterable[i%28]|=bits[i/28];
   calced=0;
}

void closebrick(uchar *where)
{
int i;
   i=where-levelbuff-2;
   enterable[i%28]&=0xffff-bits[i/28];
   calced=0;
}

void recalc()
{
int px,py;
int i,j,t;

   calced=1;
   px=xcomp[entities[0].enx]-2;
   py=ycomp[entities[0].eny];
   belowplayer=-bits[py];
   aboveplayer=(bits[py]<<1)-1;
   for(i=0;i<LX;i++)
   {
      j=i;
      if(i<px) j++;
      if(i>px) j--;
      t=stable[i] & stable[j] & enterable[j];
      upgoal[i]=(t & aboveplayer) | cantascend[i];
      downgoal[i]=(t & belowplayer) | cantdescend[i];
   }
}

int findbest(int expos, int eypos)
{
int px,py;
int ex,ey;
int i;
int b1;

   px=xcomp[entities[0].enx]-2;
   py=ycomp[entities[0].eny];
   ex=xcomp[expos]-2;
   ey=ycomp[eypos];
   b1=bits[ey];
   if(py==ey)
   {
      if(px==ex) return 0;
      i=ex;
      if(i<px)
      {
         i++;
         while(enterable[i] & stable[i] & b1)
         {
            if(i==px) return 4;
            i++;
         }
      } else
      {
         i--;
         while(enterable[i] & stable[i] & b1)
         {
            if(i==px) return 3;
            i--;
         }
      }
   }
   belowenemy=(-b1)<<1;
   aboveenemy=b1-1;
   bestdist=100;
   mask=0xffff;
   bestdir=0;
   if(!(cantascend[ex]&b1))
   {
      thisdir=1;
      if(!uprate(upgoal[ex] & aboveenemy,0)) goto foundbest;
   }
   if(!(cantdescend[ex]&b1))
   {
      thisdir=2;
      if(!downrate(downgoal[ex] & belowenemy & mask,0)) goto foundbest;
   }
   thisdir=3;
   i=ex;
   while(enterable[--i]&b1)
   {
      if(!(cantdescend[i]&b1))
         if(!downrate(downgoal[i] & belowenemy,ex-i)) break;
      if(!(stable[i]&b1)) break;
      if(!(cantascend[i]&b1))
         if(!uprate(upgoal[i] & aboveenemy,ex-i)) break;
   }
   thisdir=4;
   i=ex;
   while(enterable[++i]&b1)
   {
      if(!(cantdescend[i]&b1))
         if(!downrate(downgoal[i] & belowenemy,i-ex)) break;
      if(!(stable[i]&b1)) break;
      if(!(cantascend[i]&b1))
         if(!uprate(upgoal[i] & aboveenemy,i-ex)) break;
   }
foundbest:
   return bestdir;
}

int downrate(unsigned int d0, unsigned int delta)
{
unsigned int ax;
   if(!d0) return 1;
   ax=((d0-1) ^ d0) & d0;

   ax&=mask;
   if(!ax) return 1;
   if(ax & aboveplayer)
   {
      if((mask=-(ax+ax) & aboveplayer))
         return bestdir=thisdir;
      mask=(aboveplayer>>1)+1;
      if(delta<bestdist)
      {
         bestdist=delta;
         bestdir=thisdir;
      }
      return 0;
   } else
   {
      mask=ax-1;
      return bestdir=thisdir;
   }
}

int uprate(unsigned int d0, unsigned int delta)
{
unsigned int ax;
   if(!d0) return 1;
   ax=0x8000;
   while(!(ax & d0)) ax>>=1;

   ax&=mask;
   if(!ax) return 1;
   if(ax & aboveplayer)
   {
      if((mask=-(ax+ax) & aboveplayer))
         return bestdir=thisdir;
      mask=(aboveplayer>>1)+1;
      if(delta<bestdist)
      {
         bestdist=delta;
         bestdir=thisdir;
      }
      return 0;
   } else
   {
      mask=ax-1;
      return bestdir=thisdir;
   }
}

void doenemies()
{
struct entity *en;
int what,want;
int i,j,k;
uchar rotbyte;
uchar *oldat,*at;
uchar ch,ch2;
uchar moved;

   if(!calced) recalc();
   if(!numenemies) return;
   rotbyte=rotbytes[rotnum];
   rotnum-=8;
   if(rotnum<0) rotnum+=24;
   en=entities+1;
   for(i=0;i<numenemies;(rotbyte>>=1),(en++),i++)
   {
#define TRAPTIME 130
#define LIFTTIME1 12
#define LIFTTIME2 7
      if(rotbyte&1)
      {
         moved=0;
         what=0;
         oldat=COMPXY(en->enx,en->eny);
         want=findbest(en->enx,en->eny);
         en->enflags &=0xffff-FALLING;
         if(en->enflags & TRAPPED)
         {
            k=en->enflags;
            if(((k&HIDDENTYPE) && (k&HOLDING)) || !(k&HIDDENTYPE))
               en->entimer++;
            j=en->entimer;
            if(j<TRAPTIME-LIFTTIME1-LIFTTIME2) goto testdead;
            if(j==TRAPTIME)
            {
               en->enflags &= 0xffff-TRAPPED;
               if(*en->enloc1==CEMENT)
               {
                  *en->enloc1=DUGBRICK;
                  openbrick(en->enloc1);
               }
            }
            else
               if(j<TRAPTIME-LIFTTIME2)
               {
                  j=(en->enloc1-levelbuff)-28;
                  if(levelbuff[j]==1 || (movings[j]&(0x7f-en->enmask)) ||
                        (!findbest(XCONV(j),YCONV(j)) && !(movings[j]&0x80)))
                  {
                     en->entimer--;
                     what=0;
                  } else what=1;
                  goto doit;
               } else
               {
                  what=want;
                  goto doit;
               }
         }
         if(en->enflags & DEAD)
         {
            what=0;

            if(!en->entimer)
            {
               if(en->enflags & HIDDENTYPE)
               {
                  rotnum--;
                  numenemies--;
                  movings[oldat-levelbuff]&=0xffff-en->enmask;
                  if(*(oldat-28)==HAT)
                  {
                     *(oldat-28)=EMPTY;
                     fix(oldat-28);
                  }
                  SPRITEOFF(en->ensprite);
                  continue;
               }
               if(en->enflags & HOLDING)
               {
                  en->enflags &=0xffff-HOLDING;
                  decgold();
               }
               k=randcount;
               at=levelbuff+30+k;
               for(;;)
               {
                  if(!*at) break;
                  k++;at++;
                  if(k==LX) {k=0;at-=LX;}
               }
               en->enx=XCONV(at-levelbuff);
               en->eny=YCONV(at-levelbuff);
            }
            j=en->entimer++;
            if(j==DEADTIME) en->enflags &=0xffff-DEAD;
            else goto doit;
         }
         if(!ISSTABLE(*COMPXY(en->enx,en->eny+TY/2)) && *oldat!=3 &&
                  !(*COMPXY(en->enx,en->eny+TY/2-1)==4 && centery[en->eny]==0))
         {
            what=0;
            en->enflags |=FALLING;
         }
         else
            what=want;

doit:
         switch(what)
         {
         case 1:
            if(ISENTERABLE(*COMPXY(en->enx,en->eny-TY/2-2)))
            {
               en->enx+=centerx[en->enx];
               en->eny-=2;
               moved++;
            } else what=0;
            break;
         case 0:
            if(!(en->enflags & FALLING))
               break;
         case 2:
            en->enx+=centerx[en->enx];
            en->eny+=2;
            moved++;
            if(*oldat==DUGBRICK && centerx[en->enx]==0 && centery[en->eny]==0)
            {
               en->enflags|=TRAPPED;
               if(!(en->enflags & HIDDENTYPE))
               {
                  if (!(playflags & HASTRAPPED))
                  {
                     score -= 10000;   /* Trapping Penalty */
                     sprintf(statuswant,"-10000 Trapping");
                     statustext(statuswant,SDELAY);
         						 puttile(104,440,90); /* mark Trapping Penalty */
                     copyupxysize(104,440,TX,TY);  //copyupxysize
                     mtflag++;
                  }
                  playflags|=HASTRAPPED;
               }
               en->entimer=0;
               *oldat=CEMENT;
               en->enloc1=oldat;
               closebrick(oldat);
               if(en->enflags & HOLDING)
               {
                  en->enflags &=0xffff-HOLDING;
                  if(*(oldat-28)==EMPTY)
                  {
                     *(oldat-28)=(en->enflags & HIDDENTYPE) ? HAT : GOLD;
                     fix(oldat-28);
                  } else decgold();
               }
            }
            break;
         case 3:
            ch2=movings[oldat-levelbuff];
            ch=(ch2&(en->enmask-1)) | (movings[COMPXY(en->enx-TX/2,en->eny)-levelbuff] & (0xff-ch2));
            if(!(ch & (0x7f-en->enmask)))
            {
               en->enx-=2;
               moved++;
               if(!(en->enflags & TRAPPED))
                  en->eny+=centery[en->eny];
            } else what=0;
            break;
         case 4:
            ch2=movings[oldat-levelbuff];
            ch=(ch2&(en->enmask-1)) | (movings[COMPXY(en->enx+TX/2,en->eny)-levelbuff] & (0xff-ch2));
            if(!(ch & (0x7f-en->enmask)))
            {
               en->enx+=2;
               moved++;
               if(!(en->enflags & TRAPPED))
                  en->eny+=centery[en->eny];
            } else what=0;
            break;
         }
testdead:
         if(what) en->enwhat=what;
         at=COMPXY(en->enx,en->eny);
/*
         if(*at==1)
         {
            killenemy(en);
         }
*/
         if(oldat!=at)
         {
            movings[oldat-levelbuff]&=0xff-en->enmask;
            movings[at-levelbuff]|=en->enmask;
            if(*oldat==DUGBRICK && at==oldat+28 && (en->enflags & HOLDING))
            {
               en->enflags &=0xffff-HOLDING;
               if(!(en->enflags&HIDDENTYPE)) decgold();
            }
         }
         if(moved && !centerx[en->enx] && !centery[en->eny])
         {
            if((en->enflags & (HOLDING|HIDDENTYPE))==HOLDING)
            {
               if(en->enholdcount) en->enholdcount--;
               if(*at==EMPTY && !en->enholdcount)
               {
                  ch=*(at+28);
                  if(ch==BRICK || ch==DUGBRICK || ch==LADDER || ch==CEMENT || ch==BORDER)
                  {
                     en->enflags&=0xffff-HOLDING;
                     *at=GOLD;
                     fix(at);
                  }
               }
            } else
            {
               if(*at==GOLD && at!=flashat && !(en->enflags&HIDDENTYPE))
               {
                  *at=EMPTY;
                  en->enflags|=HOLDING;
                  fix(at);
                  en->enholdcount=randcount;
               }
            }
         }
      if(what) en->enacount++;
      else en->enacount=0;
      if(en->enacount>=24) en->enacount=0;
      }
   }
}

void killenemy(struct entity *en)
{
   if(en->enflags & DEAD) return;
   en->enflags &=0xffff-TRAPPED;
   en->enflags |=DEAD;
   if(!(en->enflags&HIDDENTYPE))
   {
      if (!(playflags & HASKILLED))
      {
         score -= 10000;  /* Killing Penalty */
         sprintf(statuswant,"-10000 Killing ");
         statustext(statuswant,SDELAY);
         puttile(104,440,89); /* mark Killing Penalty */
         copyupxysize(104,440,TX,TY); //copyupxysize
         mtflag++;
      }
      playflags|=HASKILLED;
      playflags|=HASTRAPPED;
   }
   en->entimer=0;
}

void movement()
{
int what;

   if(!playing) return;

   if(!recording)
   {
      what=*(mpoint+1);
      --*mpoint;
      if(!*mpoint) mpoint+=2;
   } else
   {
      what=0;
      if(checkpressed(digleftkey)) what=5;
      else if(checkpressed(digrightkey)) what=6;
      else if(checkpressed(upkey)) what=1;
      else if(checkpressed(downkey)) what=2;
      else if(checkpressed(leftkey)) what=3;
      else if(checkpressed(rightkey)) what=4;
   }
   if(freezing & !what) return;
   freezing=0;
   randcount++;
   if(randcount>=24) randcount=0;
   doplayer(entities,what);
   doenemies();

}

void mark(int x,int y)
{
   if(markpoint==marks+MARKMAX)
      needwhole=1;
   else
   {
      *markpoint++=x;
      *markpoint++=y;
   }
}

void domarks()
{
int *ip,x,y;
   ip=marks;
   while(ip<markpoint)
   {
      x=*ip++;
      y=*ip++;
      copyupxy(x,y);
   }
   markpoint=marks;
}

void paintmode3()
{
uchar ttt[64];

   restoresprites();
   clear();
   pty=130;
   lefttext(VERSION);
   lefttext("");
   sprintf(ttt,"PLAYER:%s",playername);
   lefttext(ttt);
   lefttext("");
   lefttext("SPACE     START GAME AT FIRST UNSOLVED LEVEL");
   lefttext("F2        GRAPHICS EDITOR");
   lefttext("F3        LEVEL EDITOR");
   lefttext("F4        PLAY LEVEL 1, OR -L LEVEL");
   lefttext("F5        CHANGE PLAYER NAME");
   lefttext("KP_MINUS  GO TO PREVIOUS LEVEL");
   lefttext("KP_PLUS   GO TO NEXT LEVEL");
   lefttext("F10       REMAP MOVEMENT KEYS");
   lefttext("ESC       TOGGLE DEMO/PLAY MODES");
   lefttext("F         TOGGLE FULLSCREEN MODE");
   lefttext("ALT-X     EXIT GAME");
}

void tomode3()
{
   fadeout();
   paintmode3();
   copyup();
   fadein();
}

void query(uchar *txt, int maxlen, uchar *str)
{
uchar ttt[80];
uchar ttt2[80];
char numshift[]=")!@#$%^&*("; /* Ascii translation for shifted number keys */
int j,k;
int ch=0;
int ascval=0;
char changed;

   strcpy(ttt,str);
   k=strlen(ttt);
   strcat(ttt,txt);
   j=strlen(txt);
   changed=1;
   for(;;)   /* loop till escape or enter pressed */
   {
      if(changed)
      {
         sprintf(ttt2,"%s~ ",ttt);
         writestring(ttt2,140,468,whitecolor);
         copyup();
         changed=0;
      }
      SDL_WaitEvent(NULL);
      resetinput();
      scaninput();
      if (anydown())
         ch = firstdown();
      if(!ch) continue;
      if((ch==SDLK_x) && (checkpressed(SDLK_RALT) || checkpressed(SDLK_LALT))) exit(0);
      if((ch==SDLK_ESCAPE) || (ch==SDLK_RETURN) || (ch==SDLK_KP_ENTER)) break;
      ascval = 0; /* Translate font defined keys into ASCII codes */
      if(checkpressed(SDLK_RSHIFT) || checkpressed(SDLK_LSHIFT))
      {
         if((ch >= SDLK_0) && (ch <= SDLK_9))
            ascval = numshift[ch - SDLK_0]; /* Translate shifted numbers */
         else if(ch == SDLK_EQUALS) ascval = '+';
         else if(ch == SDLK_SEMICOLON) ascval = ':';
         else if(ch == SDLK_SLASH) ascval = '?';
         else if(ch == SDLK_PERIOD) ascval = '>';
         else if(ch == SDLK_COMMA) ascval = '<';
         else if(ch == SDLK_SPACE) ascval = ' ';
      }
      else
      {
         if (ch == SDLK_MINUS) ascval = '-';
         else if(ch == SDLK_SPACE) ascval = ' ';
         else if(ch == SDLK_SLASH) ascval = '/';
         else if(ch == SDLK_EQUALS) ascval = '=';
         else if(ch == SDLK_BACKSLASH) ascval = '\\';
         else if(ch == SDLK_PERIOD) ascval = '.';
         else if(ch == SDLK_COMMA) ascval = ',';
         else if((ch >= SDLK_0) && (ch <= SDLK_9))
            ascval = '0' + (ch - SDLK_0); /* and  0-9 for names */
      }
      /* Check Alphabet characters. a-z and A-Z */
      if((ch >= SDLK_a) && (ch <= SDLK_z))
         ascval = 'A' + (ch - SDLK_a); /* Shift doesn't matter for A-Z in our font.*/
      if(ch==SDLK_BACKSPACE)
      {
         if(j)
         {
            j--;
            ttt[k+j]=0;
            changed=1;
         }
      } else if(ascval && j<maxlen)
      {
         ttt[k+j]=ascval;
         j++;
         ttt[k+j]=0;
         changed=1;
      }
      ch=0;  /* done with this character */
   }
   if((ch==SDLK_RETURN) || (ch==SDLK_KP_ENTER))
   {
      strcpy(txt,ttt+k);
      sprintf(ttt2,"%-72s","");
      writestring(ttt2,0,468,whitecolor);
   }
}

int remapkey(char *str,int *key)
{
char ttt[128];
int code;
   ptx = 140;
   sprintf(ttt,"Press %s:",str);
   texthere(ttt);
   copyup();
   for(;;)
   {
                resetinput();
      SDL_WaitEvent(NULL);
      scaninput();
      if(!anydown()) continue;
      code=firstdown();
      break;
   }
   if(code==SDLK_ESCAPE) return 1;
   *key=code;
   sprintf(ttt,"%x",code);
   texthere(ttt);
   pty+=16;
   copyup();
   return 0;
}

void remapkeys()
{
   int cancelmap=0;
   int oldup=upkey;
   int olddown=downkey;
   int oldleft=leftkey;
   int oldright=rightkey;
   int olddigleft=digleftkey;
   int olddigright=digrightkey;
   clear();
   pty=160;
   ptx=140;
   texthere("Remapping keys, press Escape to cancel");
   pty+=32;
   cancelmap =                 remapkey("key for moving up",&upkey);
   if (!cancelmap) cancelmap = remapkey("key for moving down",&downkey);
   if (!cancelmap) cancelmap = remapkey("key for moving left",&leftkey);
   if (!cancelmap) cancelmap = remapkey("key for moving right",&rightkey);
   if (!cancelmap) cancelmap = remapkey("key for digging left",&digleftkey);
   if (!cancelmap) cancelmap = remapkey("key for digging right",&digrightkey);
   if (!cancelmap)
   {
      makercname(temp);     /* no cancel save changes */
      makercfile(temp);
   }
   else
   {
      upkey=oldup;          /* cancel pressed so restore original keys */
      downkey=olddown;
      leftkey=oldleft;
      rightkey=oldright;
      digleftkey=olddigleft;
      digrightkey=olddigright;
   }
}

void getplayername()
{
	 NameEntryMode = 1; //Disable the P pause function during name entry
   query(playername,16,"Enter name:");
	 NameEntryMode = 0;	//Re-enable the P pause function
}

/* loads the first level without a movie or level 1 if thay all have movies */
void findlevel()
{
int err;

   clevel=1;
   for(;;)
   {
      err=getresource(1+((clevel-1)<<1),movie,20);
      if(err<=0) break;
      clevel++;
   }
   if(!loadlevel(clevel))
   {
      clevel=1;
      loadlevel(clevel);
   }
}

void mode3() /* menu */
{

   if(checkdown(SDLK_F1) || checkdown(SDLK_SPACE)) /* F1 or space*/
   {
      fadeout();
      findlevel();
      mode=mode1;
      startgame();
   } else
   if(checkdown(SDLK_F4)) /* F4 */
   {
      mode=mode1;
      clevel=ilevel;
      loadlevel(clevel);
      startgame();
   } else
   if(checkdown(SDLK_ESCAPE)) /* ESC */
   {
      initdemo();
   } else
   if(checkdown(SDLK_F2)) /* F2 */
   {
      endplay();
      mode=mode2;
      toanim();
   } else
   if(checkdown(SDLK_F5)) /* F5 */
   {
      getplayername();
      sprintf(temp,"%s/%s/%s",localname,localdirname,PLAYERNAME);
      file=open(temp,O_WRONLY|O_CREAT|O_TRUNC|O_BINARY,0600);

      if(file!=-1)
      {
         write(file,playername,16);
         close(file);
      }
      tomode3();
   } else
   if(checkdown(SDLK_F10)) /* F10 */
   {
      remapkeys();
      tomode3();
   } else
   if(checkdown(SDLK_F3)) /* f3 */
   {
      endplay();
      toedit();
   }
   if (checkdown(SDLK_f)) /* f */
      switchfullscreen();
}

void mode0() /* demo mode */
{
	 uchar ttt[64];
   if(clevel && checkdown(SDLK_F12))/*Touchup Demo but not for level zero*/
   {
   		sprintf(ttt,"PLAYER:%s",playername);
      pty=YOFF+16*TY;
      centertext("                          "); /* space clear player name */
      pty=YOFF+16*TY;
      centertext(ttt);
			copyup();											//Update the screen
      if (*mpoint == 0)mpoint+=2;   /*Handle case where count is zero*/
      savempoint = mpoint;          /*Remember mpoint*/
      savewhatcount=*mpoint;        /*Remember what count*/
      /*Reload the movie to restore the what counts prior to the current mpoint*/
      getresource (1 + ((clevel-1) << 1), movie, MOVIEMAX+20);
      mpoint=savempoint;
      *mpoint=(*mpoint - savewhatcount); /* Deduct off unused what count */
      if(*mpoint != 0)mpoint+=2;    /*Unless unused record after current mpoint*/
      *mpoint=0;                    /*After mpoint zero out what count and*/
      mpoint[1]=0;                  /*what value*/
      freezing=1;                   /*Freeze till next action key*/
      recording=1;                  /*Now recording*/
      mode=mode1;                   /*Now running game not demo*/
   } else
   if(checkdown(SDLK_ESCAPE)) /* Escape */
   {
      fadeout();
      endplay();
      mode=mode1;
      erasetile(32,440); /* unmark flashing */
      erasetile(56,440); /* unmark hidden */
      erasetile(80,440); /* unmark ladders */
      erasetile(104,440); /* unmark penalties */
      startgame();
   } else
   if(checkdown(SDLK_SPACE)) /* spacebar */
   {
      fadeout();
      endplay();
      tomode3();
      mode=mode3;
   } else
   if(checkdown(SDLK_F1)) /* F1 */
   {
      fadeout();
      endplay();
      mode=mode1;
      findlevel();
      startgame();
   } else
   if(checkdown(SDLK_F2)) /* f2 */
   {
      fadeout();
      endplay();
      mode=mode2;
      toanim();
   } else
   if(checkdown(SDLK_F3)) /* f3 */
   {
      fadeout();
      endplay();
      toedit();
   } else
   if(checkdown(SDLK_F4)) /* F4 */
   {
      fadeout();
      endplay();
      mode=mode1;
      clevel=ilevel;
      loadlevel(clevel);
      startgame();
   } else
   if(clevel > 0 && (checkdown(SDLK_F7) || checkdown(SDLK_KP_MINUS) ||checkdown(SDLK_MINUS))) /* f7 */
   {
      quiet();
      fadeout();
      endplay();
      clevel--;
      initdemo();
   } else
   if(wonflag || checkdown(SDLK_F8) || checkdown(SDLK_KP_PLUS) || checkdown(SDLK_EQUALS)) /* f8 */
   {
      quiet();
      if(wonflag) /* only make sound if won */
      {
         makesound(3);
         waitsound();
      }
      fadeout();
      endplay();
      clevel++;
      initdemo();
   }
}

void mode1() /* playing game */
{
   if(checkdown(SDLK_q) || checkdown(SDLK_ESCAPE)) /* q or escape */
   {
      fadeout();
      endplay();
      initdemo();
   } else
   if(checkdown(SDLK_F2)) /* F2 */
   {
      fadeout();
      endplay();
      mode=mode2;
      toanim();
   } else
   if(checkdown(SDLK_F3)) /* f3 */
   {
      fadeout();
      endplay();
      toedit();
   } else
   if (clevel > 0 && (checkdown(SDLK_F7) || checkdown(SDLK_KP_MINUS) || checkdown(SDLK_MINUS)))/* f7 */
   {
      quiet();
      clevel -= 2;
      nextlevel(wonflag);
   }
   else if(wonflag || checkdown(SDLK_F8) || checkdown(SDLK_KP_PLUS) || checkdown(SDLK_EQUALS))/* f8 */
   {
      quiet();
      if (wonflag)
      {
         makesound(3);
         waitsound();
      }
      nextlevel(wonflag);
   }
   else if(lostflag || checkdown(SDLK_k) || checkdown(SDLK_LSHIFT)) /* k */
   {
      quiet();
      if (lostflag) /* only make sound if lost */
      {
         makesound(4);
         waitsound();
      }
      samelevel();
   }
}

extern void csline(uchar *put, int line);
extern unsigned char currentmap[768];

void capturescreen()
{
uchar name[16];
int i;

   i=0;
   for(;;)
   {
      sprintf(name,"cap%03d.lbm",i++);
      file=open(name,O_RDONLY);
      if(file!=-1) close(file);
      else break;
   }

   writeiff(name,IXSIZE,IYSIZE,csline,currentmap);
}

int makesound(int num)
{
	if (SoundEnable)
	{
  	playsound(num);
	}
 	return num;
}

void stopsound(int num)
{
	if (SoundEnable)
  	StopSound(num);
}

void quiet()
{
	if (SoundEnable)
		StopAllSounds();
}

void waitsound()
{
	if (SoundEnable)
	{
  	WaitForSound();
	}
}
