/* SCAVENGER by David Ashley dash@.com SDL ver by Barry Mead barrymead@cox.net
   License GPL.  See COPYING for details of GPL License 
   $Author$    $Date$   $Id$   $Revision$ */

#include "scav.h"

char dirlist[]="data";

char soundactive=0;

#define NUM_SOUNDS 5
#define SNDSAMPLESIZE 512

int soundworking=0;

// New version of sound routines starts here


#include "SDL.h"
#include "SDL_audio.h"

//============================================================================
//Globals
//----------------------------------------------------------------------------
struct stat Exists;								//Used to see if file exists
struct sample {										//Holds SDL sample structures
	Uint8 *data;
	Uint32 dpos;
	Uint32 dlen;
} sounds[NUM_SOUNDS];							//One for each unique scavenger sound

SDL_AudioCVT cvt[NUM_SOUNDS];			//Converted wav data 1 for each sound

//============================================================================
// soundopen
// This routine opens the SDL sound system and reads each of the sound wav
// files into converted audio buffers that are ready to play
// returns 0 for success 1 for failure
//----------------------------------------------------------------------------
int soundopen(void)
{
	int i,num;
	void playsound(int num);													 //Forward Reference
	void mixaudio(void *unused, Uint8 *stream, int len); //Forward Reference
    char *soundnames[NUM_SOUNDS]=
		{"fall.wav","dig.wav","pop.wav","victory.wav","death.wav"};
	char file[256];
	Uint8 *data;
	Uint32 dlen;
	SDL_AudioSpec fmt;
  SDL_AudioSpec wave;
	/* Set 8-bit mono audio at 11Khz */
	fmt.freq = 11025;
	fmt.format = AUDIO_U8;
	fmt.channels = 1;
	fmt.samples = SNDSAMPLESIZE;        /* A good value for games */
	fmt.callback = mixaudio;
	fmt.userdata = NULL;

	/* Open the audio device for playing scavenger sounds */
	if ( SDL_OpenAudio(&fmt, NULL) < 0 )
	{
		fprintf(stderr, "Unable to open audio: %s\n", SDL_GetError());
		return 1;
	}
	//Expand each of the files into a full path name and preload them
	//into converted audio structures
	for (num = 0; num < NUM_SOUNDS; num++)
	{
		//Expand each file name into multiple path combinations
		//of the standard places on the system. 
		//I.E. .scavenger/file,  /usr/local/games/file, file ... etc
		for(i=0;;i++)									//Check all paths
		{
			if(!expandpath(file,soundnames[num],i))		//Expand to full path name
			{	//If all paths have been tried and file is still not found error exit
				fprintf(stderr, "Paths exhausted for file %s\n",file);
    		SDL_CloseAudio();
				soundworking=0;								//Silent mode can't play sounds
				return 1; 										//paths exhausted
			}
			if (0==stat(file,&Exists)) break;	//If file exists exit loop
		}
		// Use standard SDL library to load standard format wave file. 
		if ( SDL_LoadWAV(file, &wave, &data, &dlen) == NULL )
		{ //If the format was bad exit with an error message
			fprintf(stderr, "Couldn't load %s: %s\n", file, SDL_GetError());
    	SDL_CloseAudio();
			soundworking=0;									//Silent mode can't play sounds
			return 1; 											//Sound file not found
		}
		//Use standard SDL lirary to convert wave file to usable audio data
		SDL_BuildAudioCVT(&cvt[num], wave.format, wave.channels, wave.freq,
			AUDIO_U8, 1, 11025);
		cvt[num].buf = malloc(dlen*cvt[num].len_mult);	
		memcpy(cvt[num].buf, data, dlen*cvt[num].len_mult);//copy the data
		cvt[num].len = dlen;
		SDL_ConvertAudio(&cvt[num]);			//Convert to usable audio data
		SDL_FreeWAV(data);								//Done with wave file
	}
	soundworking=1;											//All sounds loaded sound will work
	SDL_PauseAudio(0);
	return 0;														//Normal return
}		

//============================================================================
// WaitForSound 
// This routine delays the program until all of the active sounds
// have been played to the end.
//----------------------------------------------------------------------------
void WaitForSound(void)
{
	char Waiting = 1;
	int i;
	while (Waiting == 1)
	{	
		SDL_Delay(100);								//Saves CPU for other threads
		Waiting = 0;
		for(i=0;i<NUM_SOUNDS;i++)			//Check all active sound structures
			if (sounds[i].dpos != sounds[i].dlen) Waiting = 1;	//Done?
	}																//If any aren't done check again
}

//============================================================================
// soundclose
// This routine shuts down the SDL sound system gracefully
//----------------------------------------------------------------------------
void soundclose(void)
{
	if (soundworking)								//Only shut down if it is running
	{
		WaitForSound();								//Let sounds finish
    SDL_CloseAudio();							//Then shut down the SDL Audio system,
		soundworking=0;								//and remember that it is now off.
	}
}

//============================================================================
// mixaudio
// This routine is the callback function that is activated by the SDL
// sound system to put more sound data into the sample buffer
//----------------------------------------------------------------------------
void mixaudio(void *unused, Uint8 *stream, int len)
{
	int i;
	Uint32 amount;
	for ( i=0; i<NUM_SOUNDS; ++i )	//Check each active sound
	{
		amount = (sounds[i].dlen-sounds[i].dpos);
		if ( amount > len ) amount = len; 
		SDL_MixAudio(stream, &sounds[i].data[sounds[i].dpos],amount,SDL_MIX_MAXVOLUME);
		sounds[i].dpos += amount;
	}
}


void StopSound(int num);				//Forward Reference

//============================================================================
// playsound
// This routine plays the sound selected by the number num.
// Valid values for num are 0 to NUM_SOUNDS-1
//----------------------------------------------------------------------------
void playsound(int num)
{

	if (!soundworking) return;		//Exit early if sound disabled
	if ((num < 0) || (num >= NUM_SOUNDS)) return; //Exit early invalid sound num
	// If the sound is still busy kill it
	if (sounds[num].dpos != sounds[num].dlen) StopSound(num);
	/* Put the sound data in the slot (it starts playing immediately) */
	SDL_LockAudio();											//Prevents timing collisions
	sounds[num].data = cvt[num].buf;			//The sound starts here,
	sounds[num].dlen = cvt[num].len_cvt;	//and has this much length.
	sounds[num].dpos = 0;									//Start playing at beginning of sound.
	SDL_UnlockAudio();										//Safe to start playing now
}

//============================================================================
// StopSound
// This routine stops a selected sound from playing now (truncates it)
// Valid values for num are 0 to NUM_SOUNDS
//----------------------------------------------------------------------------
void StopSound(int num)
{
	SDL_LockAudio();											//Prevents timing collisions
	sounds[num].dlen = 0;									//The sound now has no length,
	sounds[num].dpos = 0;									//and starts at beginning.
	SDL_UnlockAudio();										//Safe to resume mixing sounds
}

//============================================================================
// StopAllSounds
// This routine stops all of the sounds at once from sound 0 to NUM_SOUNDS.
//----------------------------------------------------------------------------
void StopAllSounds(void)
{
	int i;
	for (i=0; i<NUM_SOUNDS; i++)					//Stop all of the sounds using
		StopSound(i);												//existing StopSound function
}




