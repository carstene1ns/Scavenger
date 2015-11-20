#include "SDL.h"
#include "SDL_audio.h"

//Globals

#define NUM_SOUNDS 3
struct sample {
	Uint8 *data;
	Uint32 dpos;
	Uint32 dlen;
} sounds[NUM_SOUNDS];

int main()
{
		void PlaySound(char *file);													 //Forward Reference
    void mixaudio(void *unused, Uint8 *stream, int len); //Forward Reference

    SDL_AudioSpec fmt;

    /* Set 16-bit stereo audio at 22Khz */
    fmt.freq = 11025;
    fmt.format = AUDIO_U8;
    fmt.channels = 1;
    fmt.samples = 512;        /* A good value for games */
    fmt.callback = mixaudio;
    fmt.userdata = NULL;

		int i,j=0,k=0;
    /* Open the audio device and start playing sound! */
    if ( SDL_OpenAudio(&fmt, NULL) < 0 ) {
        fprintf(stderr, "Unable to open audio: %s\n", SDL_GetError());
        exit(1);
}
// Open the sound fileis and play them
char *soundnames[]={"fall.wav","dig.wav","pop.wav","victory.wav","death.wav"};
		PlaySound(soundnames[0]);
		PlaySound(soundnames[1]);
		PlaySound(soundnames[2]);
    SDL_PauseAudio(0);
		
		while ((sounds[0].dpos != sounds[0].dlen) ||	
					 (sounds[1].dpos != sounds[1].dlen) ||
					 (sounds[2].dpos != sounds[2].dlen))
		{
			SDL_GetAudioStatus();
		}
    SDL_CloseAudio();
}


void mixaudio(void *unused, Uint8 *stream, int len)
{
    int i;
    Uint32 amount;
    for ( i=0; i<NUM_SOUNDS; ++i ) {
        amount = (sounds[i].dlen-sounds[i].dpos);
        if ( amount > len ) amount = len; 
        SDL_MixAudio(stream, &sounds[i].data[sounds[i].dpos],amount,SDL_MIX_MAXVOLUME);
        sounds[i].dpos += amount;
		}
}

void PlaySound(char *file)
{
    int index;
    SDL_AudioSpec wave;
    Uint8 *data;
    Uint32 dlen;
    SDL_AudioCVT cvt;

    /* Look for an empty (or finished) sound slot */
    for ( index=0; index<NUM_SOUNDS; ++index ) {
        if ( sounds[index].dpos == sounds[index].dlen ) {
            break;
				}
		}
    if ( index == NUM_SOUNDS )
        return;

    /* Load the sound file and convert it to 8-bit mono at 11kHz */
    if ( SDL_LoadWAV(file, &wave, &data, &dlen) == NULL ) {
        fprintf(stderr, "Couldn't load %s: %s\n", file, SDL_GetError());
        return;
		}
    SDL_BuildAudioCVT(&cvt, wave.format, wave.channels, wave.freq, AUDIO_U8, 1, 11025);
    cvt.buf = malloc(dlen*cvt.len_mult);
    memcpy(cvt.buf, data, dlen);
    cvt.len = dlen;
    SDL_ConvertAudio(&cvt);
    SDL_FreeWAV(data);

    /* Put the sound data in the slot (it starts playing immediately) */
    if ( sounds[index].data ) {
        free(sounds[index].data);
		}
    	SDL_LockAudio();
    	sounds[index].data = cvt.buf;
    	sounds[index].dlen = cvt.len_cvt;
    	sounds[index].dpos = 0;
    	SDL_UnlockAudio();
		}
