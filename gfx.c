/* SCAVENGER David Ashley dash@.com SDL ver Barry Mead barrymead@cox.net */
/* License GPL.  See COPYING for details of GPL License */
/* $Author$    $Date$   $Id$   $Revision$ */

#include "scav.h"

#define KEYMAX 128

extern int NameEntryMode;
SDL_Surface *thescreen;
SDL_Color mySDLcolorMap[256];
int usedcolors=0;
uint32_t videoflags;
unsigned char *videomem;
int stride;
unsigned char *block64=NULL;
unsigned char *storageblock=NULL;
unsigned char *figureblock=NULL;
unsigned char mustlock=0,locked=0;

unsigned char blackcolor,whitecolor;

int pressedcodes[KEYMAX],downcodes[KEYMAX],numpressed=0,numdown=0;
int mousex,mousey,mouseb,mousebd;

unsigned char mymap[768],currentmap[768];

void drawstring(char * strng, ...){}
void colormapon(void){}
void colormapoff(void){}

void dumpgfx(void);   /* prototype */
void opengfx(int argc, char **argv)
{
	int i;

	dumpgfx();

	block64=malloc(65536);
	storageblock=malloc(BLOCKX*BLOCKY*128);
	figureblock=malloc(BLOCKX*BLOCKY*12*32);
	if(!block64 || !storageblock || !figureblock)
	{
		printf("No memory\n");
		exit(50);
	}

	if ( SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO) < 0 )
	{
		fprintf(stderr, "Couldn't initialize SDL: %s\n",SDL_GetError());
		exit(1);
	}
	atexit(scavcleanup);  /* Take care of SDL_Quit from now on */

	// search icon file in LIBPATH
	for(i=0;;)
	{
		if(!expandpath(temp,"scav.bmp",i))
		{
			temp[ 0 ] = '\0';
			break;
		}
		if ( open(temp,O_RDONLY|O_BINARY)!=-1 )
			break;
		++i;
	}
	// icon found?
	if ( temp[0]!='\0' )
		SDL_WM_SetIcon(SDL_LoadBMP(temp), NULL);
	SDL_WM_SetCaption( "SdlScavenger", "SdlScavenger" );

	videoflags = SDL_SWSURFACE|SDL_HWPALETTE|ScavFullScreen;
	thescreen = SDL_SetVideoMode(IXSIZE, IYSIZE, 8, videoflags);
	if ( thescreen == NULL )
	{
		fprintf(stderr, "Couldn't set display mode: %s\n",
							SDL_GetError());
		exit(5);
	}
	stride=thescreen->pitch;
	videomem=thescreen->pixels;
	mustlock=SDL_MUSTLOCK(thescreen);
	locked=0;
	SDL_ShowCursor(SDL_DISABLE);
#ifdef JOYSTICK_SUPPORT
	if ( SDL_InitSubSystem(SDL_INIT_JOYSTICK) < 0 )
	{
		fprintf(stderr, "Couldn't initialize SDL Joystick SubSystem: %s\n",SDL_GetError());
	}
	else
	{
		if ( SDL_NumJoysticks()==0 )
		{
			fprintf( stderr, "No joystick/joypad found !\n" );
		}
		else
		{
			int ScanJoy;
			for( ScanJoy=0; ScanJoy<SDL_NumJoysticks(); ScanJoy++ )
			{
				if ( SDL_JoystickOpen(ScanJoy)==NULL )
					fprintf( stderr, "Failed to open this joystick/joypad (%d)...\n", ScanJoy );
			}
			SDL_JoystickEventState(SDL_ENABLE);
		}
	}
#endif
}
void switchfullscreen( void )
{
	SDL_WM_ToggleFullScreen( thescreen );
}

void markkey(int code,int status)
{
int i;
int *ip;

	if(status)
	{
		if(numdown<KEYMAX)
			downcodes[numdown++]=code;
		ip=pressedcodes;
		i=numpressed;
		while(i)
			if(*ip++==code) break;
			else i--;
		if(!i && numpressed<KEYMAX)
			pressedcodes[numpressed++]=code;
	} else
	{
		i=numpressed;
		ip=pressedcodes;
		while(i)
			if(*ip++==code)
			{
				*--ip=pressedcodes[--numpressed];
				break;
			} else i--;
	}

}

void pollinput(void)
{
	SDL_PollEvent(0);
}

/* Reset the number of input events */
void resetinput(void)
{
   numdown=0;
   mousebd=0;
}

#define SYSJOY_RANGE 3280
int scaninput(void)
{
SDL_Event event;
int key,mod;
int bs=0;
int quit=0;

	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_KEYDOWN:
			key=event.key.keysym.sym;
			mod=event.key.keysym.mod;
			markkey(key,1);
			break;
		case SDL_KEYUP:
			key=event.key.keysym.sym;
			mod=event.key.keysym.mod;
			markkey(key,0);
			if(key == SDLK_PAUSE || (key == SDLK_p && NameEntryMode == 0)) paused^=1;
			break;
		case SDL_MOUSEBUTTONUP:
			bs=~(1<<(event.button.button-1));
			mousex=event.button.x;
			mousey=event.button.y;
			mouseb&=bs;
			break;
		case SDL_MOUSEBUTTONDOWN:
			bs=1<<(event.button.button-1);
			mousex=event.button.x;
			mousey=event.button.y;
			mouseb|=bs;
			mousebd|=bs;
			break;
		case SDL_MOUSEMOTION:
			mousex=event.motion.x;
			mousey=event.motion.y;
			break;
		case SDL_USEREVENT:
			if (gottimer < 1)gottimer++;
			break;
#ifdef JOYSTICK_SUPPORT
		case SDL_JOYAXISMOTION:
			if ((event.jaxis.axis%2) == 0) {  /* left-right */
				if (event.jaxis.value < -SYSJOY_RANGE) {  /* left */
					markkey(leftkey,1);
					markkey(rightkey,0);
				}
				else if (event.jaxis.value > SYSJOY_RANGE) {  /* right */
					markkey(rightkey,1);
					markkey(leftkey,0);
				}
				else {  /* center */
					markkey(leftkey,0);
					markkey(rightkey,0);
				}
			}
			if ((event.jaxis.axis%2) == 1) {  /* up-down */
				if (event.jaxis.value < -SYSJOY_RANGE) {  /* up */
					markkey(upkey,1);
					markkey(downkey,0);
				}
				else if (event.jaxis.value > SYSJOY_RANGE) {  /* down */
					markkey(downkey,1);
					markkey(upkey,0);
				}
				else {  /* center */
					markkey(upkey,0);
					markkey(downkey,0);
				}
			}
			break;
		case SDL_JOYBUTTONDOWN:
		case SDL_JOYBUTTONUP:
			{
				int state = (event.type==SDL_JOYBUTTONDOWN)?1:0;
				switch( event.jbutton.button )
				{
					case 0: markkey(digleftkey,state); break;
					case 1: case 2: markkey(digrightkey,state); break;
					default: markkey(SDLK_SPACE,state); break;
				}
			}	
			break;
#endif
		case SDL_QUIT:
			quit = 1;
			break;
		}
	}
	return quit;
}
void createinout(int num)
{
gfxset *gs;
uchar *p;
int i,j,counts[256];
uchar red,green,blue;
int cnt;

	gs=gfxsets+num;
	p=gs->gs_pic;
	for(i=0;i<256;i++) counts[i]=0;
	i=64000;
	while(i--)
		counts[*p++]++;
	cnt=0;
	gs->gs_inout[0]=0;
	for(i=1;i<256;i++)
	{
		if(counts[i])
		{
			cnt++;
			p=gs->gs_colormap+i+i+i;
			red=*p++;
			green=*p++;
			blue=*p++;
			p=mymap+3;
			for(j=1;j<usedcolors;j++,p+=3)
			{
				if(red==*p && green==p[1] && blue==p[2])
				{
					gs->gs_inout[i]=j;
					break;
				}
			}
			if(j==usedcolors)
			{
				*p++=red;
				*p++=green;
				*p++=blue;
				gs->gs_inout[i]=usedcolors;
				if(usedcolors<255)
					usedcolors++;
			}
		}
	}
}
int checkpressed(int code)
{
int *p,i;
	i=numpressed;
	p=pressedcodes;
	while(i--)
		if(*p++==code) return 1;
	return 0;
}
int checkdown(int code)
{
int *p,i;
	i=numdown;
	p=downcodes;
	while(i--)
		if(*p++==code) return 1;
	return 0;
}
int anydown(void)
{
	return numdown;
}
int firstdown(void)
{
	return *downcodes;
}

void gfxlock(void)
{
	if(locked || !mustlock) return;
	if ( SDL_LockSurface(thescreen) < 0 )
	{
		fprintf(stderr, "Couldn't lock display surface: %s\n",
							SDL_GetError());
	}
	locked=1;
}
void gfxunlock(void)
{
	if(!locked || !mustlock) return;
	SDL_UnlockSurface(thescreen);
	locked=0;
}
void copyup(void)
{
	gfxunlock();
	SDL_UpdateRect(thescreen, 0, 0, 0, 0);
}
void clear(void)
{
int i;
unsigned char *p;

	gfxlock();
	p=videomem;
	for(i=0;i<IYSIZE;++i)
	{
		memset(p,0,IXSIZE);
		p+=stride;
	}
}
int bestmatch(unsigned char *map,int r,int g,int b)
{
int best=-1;
int bestdist=0;
int i,j,k;

	for(i=0;i<256;++i)
	{
		k=r-*map++;
		j=k*k;
		k=g-*map++;
		j+=k*k;
		k=b-*map++;
		j+=k*k;
		if(best==-1 || j<bestdist)
		{
			best=i;
			bestdist=j;
		}
	}
	return best;
}

void loadmap(unsigned char *map)
{
int i;
unsigned char *p;

	p=map;
	for(i=0;i<256;++i)
	{
		mySDLcolorMap[i].r=*p++;
		mySDLcolorMap[i].g=*p++;
		mySDLcolorMap[i].b=*p++;
	}
	memcpy(currentmap,map,768);
	SDL_SetColors(thescreen,mySDLcolorMap,0,256);
	blackcolor=bestmatch(map,0,0,0);
	whitecolor=bestmatch(map,255,255,255);
}
void getcolors(void)
{
	loadmap(mymap);
}
void copyupxysize(int x,int y,int xsize,int ysize)
{
	gfxunlock();
	SDL_UpdateRect(thescreen,x,y,xsize,ysize);
}
void copyupxy(int x,int y)
{
	gfxunlock();
	SDL_UpdateRect(thescreen,x,y,BLOCKX,BLOCKY);
}

void erasetile(int destx,int desty)
{
int i,j;
unsigned char *p;
	gfxlock();
	p=videomem+desty*stride+destx;
	for(i=0;i<BLOCKY;++i)
	{
		for(j=0;j<BLOCKX;++j)
		{
			*p=0;
			++p;
		}
		p+=stride-BLOCKX;
	}
}
void puttile(int destx,int desty,int source)
{
int i,j;
unsigned char *p,*p2;
	gfxlock();
	p=videomem+desty*stride+destx;
	p2=figureblock+source*BLOCKX*BLOCKY;
	for(i=0;i<BLOCKY;++i)
	{
		for(j=0;j<BLOCKX;++j)
		{
			if(*p2) *p=*p2;
			++p2;
			++p;
		}
		p+=stride-BLOCKX;
	}
}
void drawsquare(int destx,int desty,unsigned char *source)
{
int i;
unsigned char *p;
	gfxlock();
	p=videomem+desty*stride+destx;
	for(i=0;i<BLOCKY;++i)
	{
		memcpy(p,source,BLOCKX);
		source+=BLOCKX;
		p+=stride;
	}
}

void store(int x,int y,int which)
{
int i;
unsigned char *p,*p2;

	gfxlock();
	p=videomem+y*stride+x;
	p2=storageblock+BLOCKX*BLOCKY*which;
	for(i=0;i<BLOCKX;++i)
	{
		memcpy(p2,p,BLOCKX);
		p+=stride;
		p2+=BLOCKX;
	}
}
void restore(int x,int y,int which)
{
int i;
unsigned char *p,*p2;

	gfxlock();
	p=videomem+y*stride+x;
	p2=storageblock+BLOCKX*BLOCKY*which;
	for(i=0;i<BLOCKX;++i)
	{
		memcpy(p,p2,BLOCKX);
		p+=stride;
		p2+=BLOCKX;
	}
}
void gfxfetch(int num,int source, int dest)
{
unsigned char *p,*p2,pixel;
gfxset *gs;
int dx,dy;
uchar *map1;

	gs=gfxsets+num;
	map1=gs->gs_inout;
	p=gs->gs_pic+BLOCKX*(source%12)+320*BLOCKY*(source/12);
	p2=figureblock+dest*BLOCKX*BLOCKY;
	for(dy=0;dy<BLOCKY;dy++)
	{
		for(dx=0;dx<BLOCKX;dx++)
		{
			pixel=*p++;
			if(pixel) pixel=map1[pixel];
			*p2++=pixel;
		}
		p+=320-BLOCKX;
	}
}
void getfigures(void)
{
int i;
	for(i=0;i<12*32;i++)
		gfxfetch(i/96,i%96,i);
}
unsigned char fmap[128];
void fontinit(void)
{
uchar *p=(uchar*)"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.:!?~/\\*-,>< =+#()";
int i;
	for(i=0;i<128;i++) fmap[i]=48;  /* undefined chars show as spaces */
	i=0;
	while(*p)
	{  /* put font letter code 0 - 53 in upper and lower case ascii points of fmap all others = 48 */
		fmap[tolower(*p)]=fmap[*p++]=i++;
	}
}
void writechar(int x,int y,uchar ch,unsigned char color) /* Added Color here */
{
int ch2;
int j,k,u,v,n;
unsigned char *p,*p2,*tp,*tp2;

	gfxlock();
	ch2=fmap[ch];
	v=ch2/9;
	u=ch2%9;
	n=5*12+9+12*(v>>1)+u/3;
	p2=figureblock+n*BLOCKX*BLOCKY;
	if(v&1) p2+=BLOCKX*BLOCKY>>1;
	p2+=u%3 << 3;
	p=videomem+y*stride+x;
	for(j=0;j<BLOCKY>>1;++j)
	{
      
      k = BLOCKX/3;
      tp = p; /* Temporary pointers */
      tp2 = p2;
      /* Replaced the memcpy with a color version */
      while (k--)
      {
         if (*tp2++)
            *tp++=color;
         else
            *tp++=blackcolor;
      } 
      /*memcpy(p,p2,BLOCKX/3);*/
		p+=stride;
		p2+=BLOCKX;
	}
}

void drawfillrect(int x,int y,int size,int color)
{
unsigned char *p;
int j;

	gfxlock();
	p=videomem+y*stride+x;
	for(j=0;j<size;++j)
	{
		memset(p,color,size);
		p+=stride;
	}
}
void drawbox(int x,int y,int size,int color)
{
unsigned char *p;
int j;

	gfxlock();
	if(color==ACOLOR)
		color=blackcolor;
	else if(color==BCOLOR)
		color=whitecolor;
	p=videomem+y*stride+x;
	memset(p,color,size+1);
	p+=stride;
	for(j=0;j<size-1;++j)
	{
		*p=color;
		p[size]=color;
		p+=stride;
	}
	memset(p,color,size+1);
}
void drawbox2(int x,int y,int sizex,int sizey,int color)
{
unsigned char *p;
int j;

	gfxlock();
	if(color==ACOLOR)
		color=blackcolor;
	else if(color==BCOLOR)
		color=whitecolor;
	p=videomem+y*stride+x;
	memset(p,color,sizex+1);
	p+=stride;
	for(j=0;j<sizey-1;++j)
	{
		*p=color;
		p[sizex]=color;
		p+=stride;
	}
	memset(p,color,sizex+1);
}
int getmousex(void)
{
	return mousex;
}
int getmousey(void)
{
	return mousey;
}
void bigpixel(int x,int y,int color)
{
	drawfillrect(x,y,8,color);
}

/* Now invert can handle color in menu icons */
void invert(int x,int y)
{
unsigned char *p;
int i,j;

	gfxlock();
	p=videomem+y*stride+x;
	for(j=0;j<11;++j)
	{
		for(i=0;i<11;++i)
		{
         if (*p == whitecolor)
            *p=blackcolor;      /* only invert black to white */
         else if (*p == blackcolor)
            *p=whitecolor; /* or white to black */
         p++;
			/* *p++^=0xff; */
		}
		p+=stride-11;
	}
}
int checkbutton(int button)
{
	return mouseb & (1<<(button-1));
}
int checkbuttondown(int button)
{
	return mousebd & (1<<(button-1));
}
void dumpgfx(void)
{
	mymap[0]=0;
	mymap[1]=0;
	mymap[2]=0;
	usedcolors=1;
}
void csline(uchar *put, int line)
{
	memcpy(put,videomem+line*stride,IXSIZE);
}
