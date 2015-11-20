
/* License GPL.  See COPYING for details of GPL License */
/* $Author$    $Date$   $Id$   $Revision$ */

#ifndef SCAV_H
#define SCAV_H


#define JOYSTICK_SUPPORT


#ifdef WIN32
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>
#include <direct.h>

/* Define types that windows doesn't know about */
typedef unsigned char uchar;

typedef unsigned char uint8_t;
typedef LONG int32_t;
typedef ULONG uint32_t;

#else
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <getopt.h>
#include <stdint.h>

#define O_BINARY 0

#endif

typedef unsigned char uchar;

#include "SDL.h"
#include "gfx.h"
#include "sound.h"
#include "names.h"
#include "anim.h"
#include "edit.h"
#include "sound.h"
#include "names.h"
#include "gfx.h"
#include "edit.h"
#include "anim.h"
#define SDELAY 120 /* 2 seconds in 60ths of a second */
#define BLOCKX 24
#define BLOCKY 24

#define IXSIZE 640
#define IYSIZE 480

#define DEMO 0
#define SAVESOUND 0
#define NUMGFX 4
#define NUM_SOUNDS 5

#define EMPTY 0
#define BRICK 1
#define CEMENT 2
#define LADDER 3
#define RAIL 4
#define FAKE 5
#define ESCAPE 6
#define GOLD 7
#define ENEMY 8
#define HERO 9
#define HIDDEN 10
#define FLASHING 11
#define HAT 12
#define EXITDOOR 13
#define DUGBRICK 14
#define BORDER 15

#define FEMPTY 1
#define FBRICK 2
#define FCEMENT 4
#define FLADDER 8
#define FRAIL 16
#define FFAKE 32
#define FESCAPE 64
#define FGOLD 128
#define FENEMY 256
#define FHERO 512
#define FHIDDEN 1024
#define FFLASHING 2048
#define FHAT 4096
#define FEXITDOOR 8192
#define FDUGBRICK 16384
#define FBORDER 32768


#define FORM 0x464f524dL
#define ILBM 0x494c424dL
#define PBM  0x50424d20L
#define CMAP 0x434d4150L
#define BODY 0x424f4459L
#define BMHD 0x424d4844L

#define ABS(x) ((x)<0 ? -(x) : (x))
#define SGN(x) ((x)<0 ? -1 : ((x)==0 ? 0 : 1))

#define LEVELSIZE 476

#define BGFIGS 0
#define HATFIGS 76
#define SHADOWFIGS 48
#define POINTERFIGS 60
#define DIGFIGS 62
#define FLASHFIGS 56
#define BUTTONFIGS 84
#define BORDERFIGS 72

#define XOFF 32
#define YOFF 60


#define LX 24
#define LY 15
#define TX 24
#define TY 24
#define TILEMAX (TX*TY)

#define COLORSEL 0
#define BOXSEL 1
#define FIXBLOW 2
#define RESTORE 3
#define SHOWCOLORS 4
#define INVERT1 5
#define RGBSEL 6
#define COORDS 7
#define PUTTILE 8
#define EBOX0 9
#define EBOX1 10
#define WRITESTRING 11
#define DRAWSQUARE 12

#define COLORSX 396
#define COLORSY 256
#define BOXESX 64
#define BOXESY 32
#define ACOLOR 256
#define BCOLOR 257
#define BLOWUPX 380
#define BLOWUPY 32
#define DRAWFUNCX 592
#define DRAWFUNCY 32
#define SHOWCOLORX 592
#define SHOWCOLORY 184
#define RGBX 300
#define RGBY 300
#define PICKCOLOR1 1
#define PICKCOLOR2 2

/* enflags */
#define FALLING 1
#define DIGGING 2
#define HELDSTABLE 4
#define DEAD 8
#define HOLDING 16
#define TRAPPED 32
#define HIDDENTYPE 64
#define PLAYER 128
#define OLDFALLING 256

#define DEADTIME 20
#define DIGTIME 24
#define DIGLIFE 360
#define MAXDIG 20

#define MOVIEMAX 4096
#define HASTRAPPED 1
#define HASKILLED 2
#define MAXLEVELS 400
#define MARKMAX 128

#define TCOLOR 255

#define HELDLIMIT 6


#define FADERATE 8

#define MAXSPRITES 16
/* sprite flags */
#define SPRITEACTIVE 0x80
#define SPRITESTORING 1
#define SPRITEOFF(x) (x)->spriteflags&=0xffff-SPRITEACTIVE


#define COMPXY(x,y) (levelbuff+xcomp[x]+ycomp2[y])
#define XCONV(i) (((i)%28)*TX+XOFF-TX*2)
#define YCONV(i) (((i)/28)*TY+YOFF-TY)

#define TEXTX XOFF
#define TOPTEXTY (YOFF-36)
#define BOTTOMTEXTY (YOFF+15*24+24)

#define ISENTERABLE(x) (bits[x] & (FEMPTY|FLADDER|FRAIL|FGOLD|FENEMY|FHERO|FFLASHING|FDUGBRICK|FHAT))
#define ISSTABLE(x) (bits[x] & (FBRICK|FCEMENT|FLADDER|FHIDDEN|FBORDER))

#define MAXBYTES 128

#define INUM 300
#define SPACE 16
#define RAD 4

#define readbyte() myci()
#define IBUFFLEN 1024














struct entity
{
	int	enx;
	int	eny;
	struct sprite *ensprite;
	uchar *enat;
	int	enflags;
	int	endir;
	int	entimer;
	uchar *enloc1;
	uchar	enwhat;
	uchar	enmask;
	uchar enholdcount;
	uchar	enacount;
};

struct dig
{
	int	digx;
	int	digy;
	uchar *digat;
	struct sprite *digsprite;
	int	digtimer;
};

struct sprite
{
	int	spriteflags;
	int	spritex;
	int	spritey;
	int	spritefig;
};

typedef struct
{
	uchar gs_colormap[768];
	uchar gs_inout[256];
	uchar *gs_pic;
} gfxset;











extern char demolevel0[];
extern char demomovie0[];
extern uchar rotbytes[];
extern int keylist[];
extern int xcolors[256];



extern uint32_t ScavFullScreen;
extern int marks[MARKMAX],*markpoint;
extern char libname[256];
extern char localname[256];
extern char localdirname[256];
extern char resourcename[256];
extern char rcname[256];

extern uchar playername[20];
extern uchar bestname[20];
extern int fallsound;
extern int digsound;
extern uchar needwhole,needtoptext,needbottomtext;

extern int xpos,ypos;
extern int hc;

extern int upkey,downkey,leftkey,rightkey,digleftkey,digrightkey;

extern int hiddens[3],hiddennum;
extern int ilevel;
extern int file;
extern int pty;
extern int ptx;
extern char gfxname0[256];
extern char gfxname1[256];
extern char gfxname2[256];
extern char gfxname3[256];
extern char *gfxnames[4];

extern uchar movie[MOVIEMAX+2+20];
extern uchar *mpoint;
extern uchar *mend;
extern int time1,time2;
extern int playflags;

extern gfxset gfxsets[NUMGFX];

extern void *configtab[];

extern uchar toptext[72];
extern uchar bottomtext[72];
extern uchar topwant[73];
extern uchar bottomwant[73];
extern uchar mtflag;
extern uchar paused;

extern int oldmode;
extern int wnum;
extern int rowbytes;
extern int gran,gran64;
extern int cwin;
extern int seed;
extern int figseg;
extern uchar colormap[768];
extern int mousex,mousey;
extern int numenemies;
extern int numgold;
extern int cframe;
extern int clevel;
extern int bright;
extern uchar temp[1024];

extern void (*mode)();
extern void scavfree(void);
extern void scavcleanup(void);
extern uchar playing;
extern uchar recording;
extern uchar wonflag;
extern uchar lostflag;
extern uchar freezing;
extern uchar randcount,randcount2;
extern uchar smap[16];
extern int mbuttons,mbuttons2;
extern int curx,cury;

extern int rotnum;

/*void mode0(),mode1(),mode2(),mode3(),mode4();*/

extern uchar levelbuff[LEVELSIZE];
extern uchar levelback[LEVELSIZE];
extern uchar movings[LEVELSIZE];
extern uchar randoms[LEVELSIZE];
extern int xcomp[640];
extern int ycomp[480];
extern int ycomp2[480];
extern int centerx[640];
extern int centery[480];

extern int cantascend[LX];
extern int cantdescend[LX];
extern int enterableo[LX+2];
extern int *enterable;
extern int stable[LX];
extern int upgoal[LX];
extern int downgoal[LX];
extern int bits[];
extern uchar calced;

extern int bestdir,bestdist,aboveenemy,belowenemy,mask,thisdir,aboveplayer,belowplayer;


extern struct sprite spritelist[MAXSPRITES];

extern uchar *flashat;
extern int flashx,flashy;
extern int flashtimer;
extern struct sprite *flashsprite;

extern struct entity entities[8];

extern struct dig diggings[MAXDIG];


extern int skips[192];

extern int mickeyx,mickeyy;
extern int mx,my;
extern int gottimer;
extern int offscreen;
extern int vp;
extern int tileseg;

extern uchar *wantiff;

extern uchar *picloc,*picput;
extern int bmw,bmh,byteswide,depth;
extern int ihand,ileft;
extern uchar *itake;
extern uchar ibuff[IBUFFLEN];












extern uchar *getgfx();


extern int rbs();
extern int myci();


extern uchar *doiff(uchar *name);
extern void debit(uchar *lines, int numb, int deep);
extern int fixbyte(char *take,int bit,int deep);
extern void unpack(int len, uchar *where);
extern int getresource(int num,char *put,int len);
extern int putresource(int num,uchar *take,int len);


extern int loadlevel(int num);
extern int scavrand();
extern void paintlevel();
extern void dectime();
extern void fixtext();
extern void writestring(uchar *str, int x, int y, int color);
extern void storesprites();
extern void restoresprites();
extern void drawsprites();
extern struct sprite *newsprite();
extern void initplay();
extern void maketext();
extern void initdemo();
extern void startgame();
extern void spritesoff();
extern void texthere(uchar *txt);
extern void lefttext(uchar *txt);
extern void centertext(uchar *txt);
extern void nextlevel(int type);
extern void samelevel();
extern void endplay();
extern int whichfig(struct entity *en);
extern void changesprites();
extern void fadein();
extern void fadeout();
extern int iterate();
extern uchar *getgfx(int num);
extern void setint(char *ip,int *op);
extern void setstring(char *ip,char *op);


extern void getconfig();
extern void remslash(char *str);
extern int dupfile(char *src, char *dest);
extern void finddata();
extern void makercname (char *str);
extern int makercfile(char *str);
extern void thandler(int val);
//extern int main(int argc, char *argv[]);
extern void createhidden(int at);
extern void newdig(uchar *at);


extern int onenemy(struct entity *pl, int what);

extern void fix(uchar *where);
extern void doplayer(struct entity *pl, int what);
extern void addmodify(int where, int what);
extern void addmodifyq(int where, int what);
extern void decgold();
extern void dodiggings();
extern void rethink();
extern void openbrick(uchar *where);
extern void closebrick(uchar *where);


extern void recalc();
extern int findbest(int expos, int eypos);
extern int downrate(unsigned int d0, unsigned int delta);
extern int uprate(unsigned int d0, unsigned int delta);
extern void doenemies();
extern void killenemy(struct entity *en);
extern void movement();
extern void mark(int x,int y);
extern void domarks();
extern void paintmode3();
extern void tomode3();


extern void query(uchar *txt, int maxlen, uchar *str);
extern int remapkey(char *str, int *key);
extern void remapkeys();
extern void getplayername();
extern void findlevel();
extern void mode3() /* menu */;
extern void mode0() /* demo mode */;
extern void mode1() /* playing game */;
extern void csline(uchar *put, int line);
extern void csline(uchar *put, int line);
extern void capturescreen();
extern int makesound(int num);
extern void stopsound(int num);
extern void quiet();
extern void waitsound();
extern void eprintf(char *format, ...);
extern int expandpath(char *put,char *name,int num);
#endif
