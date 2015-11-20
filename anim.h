/* SCAVENGER David Ashley dash@xdr.com SDL ver Barry Mead barrymead@cox.net */
/* License GPL.  See COPYING for details of GPL License */
/*  anim.h created by Marcus Brinkmann <Marcus.Brinkmann@ruhr-uni-bochum.de> */
/* $Author$    $Date$   $Id$   $Revision$ */

#ifndef ANIM_H
#define ANIM_H

#define COLORS 1
#define BOXES 2
#define BLOWUP 3
#define DRAWFUNC 4
#define RGB 5
#define SHOWCOLOR 6
#define FILLSPACE 64




extern void mode2(); /* animator */
extern void getsquare0(char *dest,int num);
extern void getsquare(char *dest,int num);
extern void putsquare(int num,char *source);
extern void showcolors();
extern void invert1(int which);
extern void colorsel(int num, int col);
extern void boxsel(int num, int col);
extern char fixblow(uchar *where);
extern void makebrush(uchar *sqr,int x1, int y1, int x2, int y2);
extern void flipx();
extern void flipy();
extern void copysquare(char *dest,char *source);
extern void rot90();
extern void paintbrush(uchar *sqr,int x, int y, int type);
extern void animrect(uchar *sqr,int x1, int y1, int x2, int y2, int type);
extern void animline(uchar *sqr,int x1, int y1, int x2, int y2, int type);
extern void animfill(uchar *sqr,int x, int y, int color);
extern void boxflipx();
extern void boxflipy();
extern void boxrot90();
extern void crosshair(uchar *sqr, int x, int y);
extern void outline(uchar *sqr,int x1, int y1, int x2, int y2);
extern int whichfunc(int x, int y);
extern int findcurs();
extern void changecolor(int nc);
extern void newanimmode(int m);
extern void coords(int x,int y);
extern void animprocess();
extern void rgbsel(int r, int g, int b, int col);
extern void paintboxes();
extern void paintanim();
extern void animinit();
extern void toanim();
extern void push();
extern void pop();
extern void lout(int32_t val);
extern void wout(int val);
extern void bout(uchar val);
extern void picline(char *put,int line);
extern void savegfx();
extern int writeiff(uchar *name,int width, int height, void (*fetch)(),uchar *colors);
extern void gather(uchar *to,uchar *from,int len,int bit);
extern void pack(uchar *take, int rb);
extern void dpout(uchar *pnt2,int d1, int d2, int d5);

#endif
