/* SCAVENGER by David Ashley  dash@.com SDL ver Barry Mead barrymead@cox.net */
/* License GPL.  See COPYING for details of GPL License */
/* $Author$    $Date$   $Id$   $Revision$ */

#include "scav.h"

void drawstring(char *, ...);
void colormapon(void);
void colormapoff(void);

int animcolor,animbox;
int animbcolor,cbrush;
int animboxx,animboxy;
int animdown,animdownx,animdowny;
int animmode,lastanimmode;
uchar asquare[TILEMAX],bsquare[TILEMAX],tsquare[TILEMAX];
uchar savesquare[TILEMAX],tsquare2[TILEMAX];
int workingon=0;

int brushes[]=
{
1,0,0,
4,0,0,1,0,0,1,1,1,
9,-1,-1,0,-1,1,-1,-1,0,0,0,1,0,-1,1,0,1,1,1,
16,-1,-1,0,-1,1,-1,2,-1,-1,0,0,0,1,0,2,0,-1,1,0,1,1,1,2,1,-1,2,0,2,1,2,2,2,
21,-1,-1,0,-1,1,-1,-1,0,0,0,1,0,-1,1,0,1,1,1,
  -1,-2,0,-2,1,-2,-2,-1,-2,0,-2,1,2,-1,2,0,2,1,-1,2,0,2,1,2,
37,-1,-1,0,-1,1,-1,-1,0,0,0,1,0,-1,1,0,1,1,1,
  -1,-2,0,-2,1,-2,-2,-1,-2,0,-2,1,2,-1,2,0,2,1,-1,2,0,2,1,2,
  -2,-2,2,-2,-2,2,2,2,
  -1,-3,0,-3,1,-3,-3,-1,-3,0,-3,1,3,-1,3,0,3,1,-1,3,0,3,1,3
};

int bsx,bsy;
int bhx,bhy;
uchar userbrush[TILEMAX];
uchar btransp;

uchar tainted=0;

int coordx=-1,coordy=-1;

int wfile;
int32_t stack[8];
int sp=0;
int32_t ppos;

int oldbuttons;
int lastwhere;
int trapdown;
int dbx,dby;

char *descriptions[4]={
"background",
"hero",
"main enemy",
"hidden enemy"
};

void farlefttext(uchar *txt)
{
int ptx;
uchar ch;

	ptx=60;
	while ((ch=*txt++))
	{
		writechar(ptx,pty,ch ,whitecolor);
		ptx+=8;
	}
	pty+=16;
}

void drawanimmenu(void)
{
   pty=250;
   farlefttext("ESCAPE   EXIT ANIMATOR");
   farlefttext("SHIFT S  SAVE CHANGES");
   farlefttext("SHIFT L  RELOAD LAST SAVE");
   farlefttext(" ALT 1   FIXTURES");
   farlefttext(" ALT 2   HERO POSES");
   farlefttext(" ALT 3   ENEMY POSES");
   farlefttext(" ALT 4   HIDDEN POSES");
   farlefttext("  U      UNDO LAST EDIT");
   farlefttext("  X      MIRROR X");
   farlefttext("  Y      MIRROR Y");
   farlefttext("  Z      ROTATE 90 CW");
   farlefttext("D F B R  DRAW,FILL,BOX,RECT");
   farlefttext(", . L    GET COLOR,DOT,LINE");
   ptx=RGBX +5;
   pty=RGBY - 18;
   texthere("R G B");
}

void mode2() /* animator */
{
int i;
/* uchar *cm; */

	if(checkdown(SDLK_ESCAPE)) /* esc */
	{
		fadeout();
		restoresprites();
		clear();
		copyup();
		colormapoff();
		dumpgfx();
		for(i=0;i<NUMGFX;i++) createinout(i);
		getcolors();
		getfigures();

		initdemo();
	}
	if(checkdown(SDLK_s) && (checkpressed(SDLK_LSHIFT) || checkpressed(SDLK_RSHIFT))) /* shift-s */
		savegfx();
	if((checkpressed(SDLK_LALT) || checkpressed(SDLK_RALT)) &&
      (checkdown(SDLK_1) || checkdown(SDLK_2) ||
       checkdown(SDLK_3) || checkdown(SDLK_4)))
	{
		if(checkdown(SDLK_1)) i=0;
		else if(checkdown(SDLK_2)) i=1;
		else if(checkdown(SDLK_3)) i=2;
		else i=3;
		fadeout();
		restoresprites();
		workingon=i;
		getsquare(asquare,animbox);
		paintanim();
		storesprites();
		drawsprites();
      drawanimmenu();
		fadein();
		copyup();
	}
}

void getsquare0(char *dest,int num)
{
uchar *source;
gfxset *gs;
int i,j;
	gs=gfxsets;
	source=gs->gs_pic+24*(num%12)+320*24*(num/12);
	for(j=0;j<24;j++)
	{
		for(i=0;i<24;i++)
			*dest++=*source++;
		source+=320-24;
	}
}


void getsquare(char *dest,int num)
{
uchar *source;
gfxset *gs;
int i,j;
	gs=gfxsets+workingon;
	source=gs->gs_pic+24*(num%12)+320*24*(num/12);
	for(j=0;j<24;j++)
	{
		for(i=0;i<24;i++)
			*dest++=*source++;
		source+=320-24;
	}
}

void putsquare(int num,char *source)
{
uchar *dest;
gfxset *gs;
int i,j;
	gs=gfxsets+workingon;
	dest=gs->gs_pic+24*(num%12)+320*24*(num/12);
	for(j=0;j<24;j++)
	{
		for(i=0;i<24;i++)
			*dest++=*source++;
		dest+=320-24;
	}
}


void showcolors()
{
int ch;
int i,j;

	for(j=0;j<5;j++)
		for(i=0;i<5;i++)
		{
			ch=animbcolor;
			if(i>0 && i<4 && j>0 && j<4) ch=animcolor;
			bigpixel(SHOWCOLORX+(i<<3)+1,SHOWCOLORY+(j<<3)+1,ch);
		}
}


void invert1(int which)
{
	invert(DRAWFUNCX+(which&1)*12,DRAWFUNCY+(which>>1)*12);
}


void colorsel(int num, int col)
{
int x,y;
	x=COLORSX+12*(num&15);
	y=COLORSY+12*(num>>4);
	drawbox(x,y,12,col);
}

void boxsel(int num, int col)
{
int x,y;
	x=BOXESX+25*(num%12);
	y=BOXESY+25*(num/12);
	drawbox(x,y,25,col);
}

char fixblow(uchar *where)
{
int i,j,x,y;
uchar *p,ch;
char changed=0;

	p=bsquare;
	for(j=0;j<TY;j++)
	{
		for(i=0;i<TX;i++)
		{
			ch=*where++;
			if(ch==*p++) continue;
			changed=1;
			*(p-1)=ch;
			x=BLOWUPX+1+(i<<3);
			y=BLOWUPY+1+(j<<3);
			bigpixel(x,y,ch);
		}
	}
	return changed;
}


void makebrush(uchar *sqr, int x1, int y1, int x2, int y2)
{
int i,j;
uchar *p;

	p=userbrush;
	if(x2<x1) {i=x1;x1=x2;x2=i;}
	if(y2<y1) {i=y1;y1=y2;y2=i;}
	btransp=animbcolor;

	bsx=x2-x1+1;
	bsy=y2-y1+1;
	for(j=y1;j<=y2;j++)
		for(i=x1;i<=x2;i++)
			*p++=sqr[24*j+i];
	bhx=bsx>>1;
	bhy=bsy>>1;
}

void flipx()
{
int j;
uchar *p1,*p2,*p3,ch;

	p1=userbrush;
	for(j=0;j<bsy;j++)
	{
		p2=p1;
		p3=p2+bsx-1;
		while(p2<p3)
		{
			ch=*p2;
			*p2++=*p3;
			*p3--=ch;
		}
		p1+=bsx;
	}
}

void flipy()
{
int i;
uchar *p1,*p2,ch;
	p1=userbrush;
	p2=p1+bsx*(bsy-1);
	while(p1<p2)
	{
		for(i=0;i<bsx;i++)
		{
			ch=*p1;
			*p1++=*p2;
			*p2++=ch;
		}
		p2-=bsx+bsx;
	}
}

void copysquare(char *dest,char *source)
{
	memcpy(dest,source,TILEMAX);
}

void rot90()
{
int i,j;
uchar *p1;
	p1=userbrush;
	copysquare(temp,userbrush);
	for(i=0;i<bsx;i++)
		for(j=bsy-1;j>=0;j--)
			*p1++=temp[j*bsx+i];
	i=bsx;
	bsx=bsy;
	bsy=i;
	j=bhx;
	bhx=bhy;
	bhy=j;

}

void paintbrush(uchar *sqr, int x, int y, int type)
{
int *p;
int t;
int tx,ty;
int i,j;
uchar ch,ch2;
uchar *p2;
int color;

	color=(type&2) ? animbcolor : animcolor;

	if(cbrush)
	{
		p=brushes;
		t=cbrush;
		while(--t) p+=*p * 2 + 1;
		t=*p++;
		while(t--)
		{
			tx=x + *p++;
			ty=y + *p++;
			if(tx>=0 && tx<24 && ty>=0 && ty<24)
				sqr[ty*24+tx]=color;
		}
	} else
	{
		x-=bhx;
		y-=bhy;
		p2=userbrush;
		for(j=0;j<bsy;j++)
		{
			ty=y+j;
			for(i=0;i<bsx;i++)
			{
				tx=x+i;
				ch2=ch=*p2++;
				if(type&2) ch=animbcolor;
				if(tx>=0 && tx<24 && ty>=0 && ty<24 && ch2!=btransp)
					sqr[ty*24+tx]=ch;
			}
		}
	}
}

void animrect(uchar *sqr, int x1, int y1, int x2, int y2, int type)
{
int i,j,color;
	color=(type&2) ? animbcolor : animcolor;
	if(x2<x1) {i=x1;x1=x2;x2=i;}
	if(y2<y1) {i=y1;y1=y2;y2=i;}
	for(j=y1;j<=y2;j++)
		for(i=x1;i<=x2;i++)
			sqr[j*24+i]=color;
}

void animline(uchar *sqr, int x1, int y1, int x2, int y2, int type)
{
int err,dx,dy,dxa,dya;
	dx=x2-x1;
	dy=y2-y1;

	dxa=ABS(dx);
	dya=ABS(dy);
	dx=SGN(dx);
	dy=SGN(dy);
	if(dxa>dya)
	{
		dya+=dya;
		err=dya-dxa;
		dxa+=dxa;
		while(x1!=x2)
		{
			paintbrush(sqr,x1,y1,type);
			x1+=dx;
			if(err<0)
				err+=dya;
			else
			{
				err+=dya-dxa;
				y1+=dy;
			}
		}
	} else if(dxa<dya)
	{
		dxa+=dxa;
		err=dxa-dya;
		dya+=dya;
		while(y1!=y2)
		{
			paintbrush(sqr,x1,y1,type);
			y1+=dy;
			if(err<0)
				err+=dxa;
			else
			{
				err+=dxa-dya;
				x1+=dx;
			}
		}
	} else
	{
		while(x1!=x2)
		{
			paintbrush(sqr,x1,y1,type);
			x1+=dx;
			y1+=dy;
		}
	}
	paintbrush(sqr,x1,y1,type);
}

void animfill(uchar *sqr, int x, int y, int color)
{
int list[FILLSPACE];
int wcolor;
int *put,*take,*end;
int z;

	z=y*24+x;
	wcolor=sqr[z];
	if(wcolor==color) return;
	sqr[z]=color;
	put=list;
	*put++=z;
	take=list;
	end=list+FILLSPACE;
	while(take!=put)
	{
		z=*take++;
		if(take==end) take=list;
		x=z%24;
		y=z/24;
		if(x && sqr[z-1]==wcolor)
		{
			*put++=z-1;
			if(put==end) put=list;
			sqr[z-1]=color;
		}
		if(y && sqr[z-24]==wcolor)
		{
			*put++=z-24;
			if(put==end) put=list;
			sqr[z-24]=color;
		}
		if(x<23 && sqr[z+1]==wcolor)
		{
			*put++=z+1;
			if(put==end) put=list;
			sqr[z+1]=color;
		}
		if(y<23 && sqr[z+24]==wcolor)
		{
			*put++=z+24;
			if(put==end) put=list;
			sqr[z+24]=color;
		}
	}
}

void boxflipx()
{
int j;
uchar ch,*p1,*p2;
	for(j=0;j<24;j++)
	{
		p1=asquare+j*24;
		p2=p1+23;
		while(p1<p2)
		{
			ch=*p1;
			*p1++=*p2;
			*p2--=ch;
		}
	}
}

void boxflipy()
{
int i;
uchar ch,*p1,*p2;
	p1=asquare;
	p2=p1+23*24;
	while(p1<p2)
	{
		for(i=0;i<24;i++)
		{
			ch=*p1;
			*p1++=*p2;
			*p2++=ch;
		}
		p2-=48;
	}
}

void boxrot90()
{
int i,j;
uchar *p1,*p2;

	p1=temp;
	p2=asquare;
	i=24*24;
	while(i--)
		*p1++=*p2++;
	p1=asquare;
	p2=temp+23*24;
	for(i=0;i<24;i++)
	{
		for(j=0;j<24;j++)
		{
			*p1++=*p2;
			p2-=24;
		}
		p2+=24*24+1;
	}
}

void crosshair(uchar *sqr, int x, int y)
{
int i;
	for(i=0;i<24;i++)
	{
		sqr[24*y+i]^=0xff;
		if(i!=y)
			sqr[24*i+x]^=0xff;
	}
}

void outline(uchar *sqr, int x1, int y1, int x2, int y2)
{
int i;
	if(x2<x1) {i=x1;x1=x2;x2=i;}
	if(y2<y1) {i=y1;y1=y2;y2=i;}
	for(i=x1;i<=x2;i++)
	{
		sqr[y1*24+i]^=0xff;
		if(y2!=y1)
			sqr[y2*24+i]^=0xff;
	}
	for(i=y1+1;i<y2;i++)
	{
		sqr[i*24+x1]^=0xff;
		if(x2!=x1)
			sqr[i*24+x2]^=0xff;
	}

}


int whichfunc( int x, int y)
{
	x=curx-x;
	y=cury-y;
	x/=12;
	y/=12;
	return y*2+x;
}

int findcurs()
{
	if(curx>=COLORSX && curx<COLORSX+192 && cury>=COLORSY && cury<COLORSY+192)
		return COLORS;
	if(curx>=BOXESX && curx<BOXESX+300 && cury>=BOXESY && cury<BOXESY+200)
		return BOXES;
	if(curx>=DRAWFUNCX && curx<DRAWFUNCX+24 && cury>=DRAWFUNCY && cury<DRAWFUNCY+84)
		return DRAWFUNC;
	if(curx>BLOWUPX && curx<=BLOWUPX+192 && cury>BLOWUPY && cury<=BLOWUPY+192)
		return BLOWUP;
	if(curx>=RGBX && curx<RGBX+48 && cury>=RGBY && cury<RGBY+128)
		return RGB;
	if(curx>SHOWCOLORX && curx<=SHOWCOLORX+40 && cury>SHOWCOLORY && cury<=SHOWCOLORY+40)
		return SHOWCOLOR;
	return 0;
}

void changecolor(int nc)
{
int a;
uchar *cm;

	cm=(gfxsets+workingon)->gs_colormap;
	if(animcolor==nc) return;
	colorsel(animcolor,ACOLOR);
	a=animcolor*3;
	rgbsel(cm[a],cm[a+1],cm[a+2],ACOLOR);
	animcolor=nc;
	colorsel(animcolor,BCOLOR);
	a=animcolor*3;
	rgbsel(cm[a],cm[a+1],cm[a+2],BCOLOR);
	showcolors();
	needwhole=1;
}

void newanimmode(int m)
{
	if(m!=animmode)
	{
		if(animmode) invert1(animmode);
		animmode=m;
		invert1(animmode);
		needwhole=1;
	}
}



void coords(int x,int y)
{
	writechar(BLOWUPX+80,BLOWUPY-16,x<99 ? x/10+'0' : ' ',whitecolor);
	writechar(BLOWUPX+88,BLOWUPY-16,x<99 ? x%10+'0' : ' ',whitecolor);
	writechar(BLOWUPX+104,BLOWUPY-16,y<99 ? y/10+'0' : ' ',whitecolor);
	writechar(BLOWUPX+112,BLOWUPY-16,y<99 ? y%10+'0' : ' ',whitecolor);
}


void animprocess()
{
int a,b,c,i;
int where;
int bx=0,by=0;
uchar *cm;
int cxwant,cywant;

	if(mode!=mode2) return;

	where=findcurs();
	if(where==BLOWUP)
	{
		bx=(curx-BLOWUPX-1)>>3;
		by=(cury-BLOWUPY-1)>>3;
		if(mbuttons && animdown==BLOWUP)
		{
			cxwant=ABS(dbx-bx)+1;
			cywant=ABS(dby-by)+1;
		}
		else
		{
			cxwant=bx;
			cywant=by;
		}
	} else
		cxwant=cywant=99;

	if(cxwant!=coordx || cywant!=coordy)
	{
		needwhole=1;
		coords(cxwant,cywant);
		coordx=cxwant;
		coordy=cywant;
	}


	if((mbuttons2&3) && trapdown)
	{
		switch(trapdown)
		{
		case PICKCOLOR1:
			if(where==BLOWUP)
				changecolor(bsquare[bx+by*24]);
			needwhole=1;
			break;
		case PICKCOLOR2:
			if(where==BLOWUP)
				animbcolor=bsquare[bx+by*24];
			showcolors();
			needwhole=1;
			break;
		}
		trapdown=0;
		animdown=0;
	} else
	if((mbuttons2&3) && !trapdown)
	{
		animdown=where;
		animdownx=curx;
		animdowny=cury;
		dbx=bx;
		dby=by;
		if(where==BLOWUP) copysquare(savesquare,asquare);
		switch(where)
		{
		case DRAWFUNC:
			a=whichfunc(DRAWFUNCX,DRAWFUNCY);
			if(a>=8 && a<=13 && a-7!=cbrush)
			{
				if(cbrush)
					invert1(cbrush+7);
				cbrush=a-7;
				invert1(cbrush+7);
				needwhole=1;
				if(animmode!=6 && animmode!=1)
					newanimmode(6);
			} else if(a==0) /* undo function */
			{
				copysquare(tsquare2,asquare);
				copysquare(asquare,savesquare);
				copysquare(savesquare,tsquare2);
				tainted=1;
			} else if(a==7)
			{
				copysquare(savesquare,asquare);
				for(i=0;i<TILEMAX;i++)
					asquare[i]=animbcolor;
				tainted=1;
			} else if(a>=1 && a<=6)
			{
				if(a==2 && animmode!=2)
					lastanimmode=animmode;
				newanimmode(a);
			}
			break;
		case SHOWCOLOR:
			trapdown=(mbuttons2&1) ? PICKCOLOR1 : PICKCOLOR2;
			tainted=1;
			break;
		case BLOWUP:
			if(animmode==4)
			{
				animfill(asquare,bx,by,(mbuttons2&1) ? animcolor : animbcolor);
				tainted=1;
			}
			break;
		}
	}
	if(animmode==2 && animdown==BLOWUP && !mbuttons && oldbuttons && where==BLOWUP && bx>=0 && bx<24 && by>=0 && by<24)
	{
		if(cbrush) {invert1(cbrush+7);needwhole=1;}
		cbrush=0;
		makebrush(asquare,dbx,dby,bx,by);
		if(oldbuttons&2)
		{
			animrect(asquare,dbx,dby,bx,by,oldbuttons);
			tainted=1;
		}
		if(lastanimmode==1 || lastanimmode==6)
			newanimmode(lastanimmode);
		else
			newanimmode(6);
	}
	if(where==COLORS && animdown==COLORS && mbuttons)
	{
		if(mbuttons&1)
		{
			changecolor((curx-COLORSX)/12 + (((cury-COLORSY)/12)<<4));
		} else
		{
			animbcolor=(curx-COLORSX)/12 + (((cury-COLORSY)/12)<<4);
			showcolors();
			needwhole=1;
		}
	}
	if(where==BOXES && animdown==BOXES && ((mbuttons&1) || (mbuttons2&2)))
	{
		a=(curx-BOXESX)/25;
		b=(cury-BOXESY)/25;
		c=a+12*b;
		if(animbox!=c)
		{
			needwhole=1;
			boxsel(animbox,BCOLOR);
			animbox=c;
			animboxx=BOXESX+a*25+1;
			animboxy=BOXESY+b*25+1;
			boxsel(animbox,ACOLOR);
			getsquare(asquare,animbox);
			fixblow(asquare);
			copysquare(savesquare,asquare);
		}
	}

	if(where==BOXES && animdown==BOXES && (oldbuttons&2) && !(mbuttons&2))
	{
		a=(curx-BOXESX)/25;
		b=(cury-BOXESY)/25;
		c=a+12*b;
		if(animbox!=c)
		{
			needwhole=1;
			boxsel(animbox,BCOLOR);
			animbox=c;
			animboxx=BOXESX+a*25+1;
			animboxy=BOXESY+b*25+1;
			boxsel(animbox,ACOLOR);
			getsquare(savesquare,animbox);
			putsquare(animbox,asquare);
			drawsquare(animboxx,animboxy,asquare);
		}
	}

	if(animdown==RGB && mbuttons)
	{
		a=animcolor*3;
		c=a+(animdownx-RGBX)/16;
		b=(RGBY+127-cury)*2;
		if(b<0) b=0;
		if(b>255) b=255;
		cm=(gfxsets+workingon)->gs_colormap;
		if(cm[c]!=b)
		{
			needwhole=1;
			cm[c]=b;
			paintanim();
         drawanimmenu();
/*
			rgbsel(cm[a],cm[a+1],cm[a+2],ACOLOR);
			cm[c]=b;
			rgbsel(cm[a],cm[a+1],cm[a+2],BCOLOR);
			palette(cm);
*/
		}
	}
	if(animdown==BLOWUP && where==BLOWUP && mbuttons)
	{
		switch(animmode)
		{
		case 1: /* line */
			copysquare(asquare,savesquare);
			animline(asquare,dbx,dby,bx,by,mbuttons);
			tainted=1;
			break;
		case 3: /* rect */
			copysquare(asquare,savesquare);
			animrect(asquare,dbx,dby,bx,by,mbuttons);
			tainted=1;
			break;
		case 6: /* draw */
			paintbrush(asquare,bx,by,mbuttons);
			tainted=1;
			break;
		case 2: /* brush */
			copysquare(tsquare,asquare);
			outline(tsquare,dbx,dby,bx,by);
			if(fixblow(tsquare))
				needwhole=1;
			drawsquare(animboxx,animboxy,tsquare);
			break;
		}
	}
/******/
	if((where==BLOWUP || lastwhere==BLOWUP) && (animmode==2 || animmode==3) && !mbuttons && !trapdown)
	{
		copysquare(tsquare,asquare);
		if(bx>=0 && bx<TX && by>=0 && by<TY)
			crosshair(tsquare,bx,by);
		if(fixblow(tsquare))
			needwhole=1;
		drawsquare(animboxx,animboxy,tsquare);
	}
	if((where==BLOWUP || lastwhere==BLOWUP) && (animmode==6 || animmode==1) && !mbuttons && !trapdown)
	{
		copysquare(tsquare,asquare);

		if(bx>=0 && bx<TX && by>=0 && by<TY)
			paintbrush(tsquare,bx,by,0);
		if(fixblow(tsquare))
			needwhole=1;
		drawsquare(animboxx,animboxy,tsquare);
	}

	if(checkdown(SDLK_LEFTBRACKET) ||
           checkdown(SDLK_RIGHTBRACKET)) /* [ or ] */
	{
		if(checkdown(SDLK_LEFTBRACKET))
			a=animcolor-1;
		else
			a=animcolor+1;
		changecolor(a&0xff);
	}
	if(checkdown(SDLK_u)) /* u */
	{
		copysquare(tsquare2,asquare);
		copysquare(asquare,savesquare);
		copysquare(savesquare,tsquare2);
		tainted=1;
	}
	if(checkdown(SDLK_v) && animmode!=1) /* v keep for legacy users */
		newanimmode(1);
	if(checkdown(SDLK_x)) /* x */
	{
		if(!cbrush)
			flipx();
		else
		{
			boxflipx();
			tainted=1;
		}
	}
	if(checkdown(SDLK_y)) /* y */
	{
		if(!cbrush)
			flipy();
		else
		{
			boxflipy();
			tainted=1;
		}
	}
	if(checkdown(SDLK_z)) /* z */
	{
		if(!cbrush)
			rot90();
		else
		{
			boxrot90();
			tainted=1;
		}
	}
	if(checkdown(SDLK_b)) /* b */
	{
		if(checkpressed(SDLK_LSHIFT) ||
                   checkpressed(SDLK_RSHIFT)) /* shift B*/
		{
			if(cbrush)
			{
				invert1(cbrush+7);
				needwhole=1;
				cbrush=0;
			}
		} else
		if(animmode!=2)
		{
			lastanimmode=animmode;
			newanimmode(2);
		}
	}
	if(checkdown(SDLK_f)) {newanimmode(4);tainted=1;} /* f */
	if(checkdown(SDLK_r)) newanimmode(3); /* r */
	if(checkdown(SDLK_l)) /* L */
   { 
      if (checkpressed(SDLK_LSHIFT) || checkpressed(SDLK_RSHIFT)) /* shift L */
      {
         getgfx(workingon);
         loadmap((gfxsets+workingon)->gs_colormap);
         paintboxes();
         getsquare(asquare,animbox);
         copysquare(tsquare,asquare);
         fixblow(asquare);
         needwhole=1;
      }
      else
         newanimmode(1);  /* unshifted L */
   }

	if((checkdown(SDLK_KP_MINUS) || checkdown(SDLK_MINUS)) && cbrush && cbrush>1) /* - or KP -*/
	{
		invert1(cbrush+7);
		cbrush--;
		invert1(cbrush+7);
		needwhole=1;
	}
	if((checkdown(SDLK_KP_PLUS) || checkdown(SDLK_EQUALS)) && cbrush && cbrush<6) /* = or KP +*/
	{
		invert1(cbrush+7);
		cbrush++;
		invert1(cbrush+7);
		needwhole=1;
	}
	if(checkdown(SDLK_PERIOD)) /* . */
	{
      if (cbrush != 1)
      {
         if(cbrush)
            invert1(cbrush+7);
         needwhole=1;
         cbrush=1;
		   invert1(cbrush+7);
      }
		if(animmode!=1 && animmode!=6) newanimmode(6);
	}
	if(checkdown(SDLK_d)) /* d */
		newanimmode(6);
	if(checkdown(SDLK_COMMA)) /* , */
	{
		trapdown=PICKCOLOR1;
		tainted=1;
	}
	if(tainted)
	{
		putsquare(animbox,asquare);
		if(fixblow(asquare))
			needwhole=1;
		drawsquare(animboxx,animboxy,asquare);
		tainted=0;
	}
	oldbuttons=mbuttons;
	lastwhere=where;
}

void rgbsel(int r, int g, int b, int col)
{
	r=RGBY+126-(r>>1);
	g=RGBY+126-(g>>1);
	b=RGBY+126-(b>>1);
	drawbox2(RGBX+4,r,7,1,col);
	drawbox2(RGBX+20,g,7,1,col);
	drawbox2(RGBX+36,b,7,1,col);
}
void paintboxes()
{
int i,j;
	for(j=0;j<8;j++)
	{
		for(i=0;i<12;i++)
		{
			getsquare(tsquare,j*12+i);
			drawsquare(i*25+BOXESX+1,j*25+BOXESY+1,tsquare);
		}
	}
	fixblow(asquare);
}


void paintanim()
{
int i,j,x,y,c;
uchar *cm;
uchar ttt[128];

	memset(bsquare,0,TILEMAX);
	cm=(gfxsets+workingon)->gs_colormap;
	loadmap(cm);
	clear();
	i=animcolor*3;
	rgbsel(cm[i],cm[i+1],cm[i+2],BCOLOR);

	sprintf(ttt,"%s artwork: %s",descriptions[workingon],
		gfxnames[workingon]);
	drawstring(ttt,4,4,255);

	c=0;
	for(j=0;j<16;j++)
	{
		y=COLORSY+j*12+1;
		for(i=0;i<16;i++)
		{
			x=COLORSX+i*12+1;
			drawfillrect(x,y,11,c++);
		}
	}
	drawbox(SHOWCOLORX,SHOWCOLORY,41,BCOLOR);

	for(j=0;j<8;j++)
		for(i=0;i<12;i++)
			drawbox(BOXESX+25*i,BOXESY+25*j,25,BCOLOR);
	drawbox(BLOWUPX,BLOWUPY,193,BCOLOR);

	colorsel(animcolor,BCOLOR);
	boxsel(animbox,ACOLOR);
	paintboxes();
	for(i=0;i<4;i++)
	{
		getsquare0(tsquare,BUTTONFIGS+i);
		drawsquare(DRAWFUNCX,DRAWFUNCY+TY*i,tsquare);
	}
	if(cbrush) invert1(cbrush+7);
	drawbox2(RGBX,RGBY-2,16,130,BCOLOR);
	drawbox2(RGBX+16,RGBY-2,16,130,BCOLOR);
	drawbox2(RGBX+32,RGBY-2,16,130,BCOLOR);

	if(animmode) invert1(animmode);
	showcolors();
}

void animinit()
{
	animcolor=1;
	animbcolor=0;
	cbrush=1;
	animmode=6;
	animbox=0;
	animboxx=BOXESX+1;
	animboxy=BOXESY+1;
	bsx=bsy=0;
}

void toanim()
{
/* int i; */

	fadeout();
	restoresprites();
	lastwhere=0;
	animdown=0;
	trapdown=0;
	getsquare(asquare,animbox);
/*
	for(i=0;i<TILEMAX;i++)
		bsquare[i]=0;
*/
	getsquare(asquare,animbox);
	copysquare(savesquare,asquare);
	colormapon();
	coordx=coordy=-1;
	paintanim();
   drawanimmenu();
	copyup();
	fadein();
   SDL_ShowCursor(SDL_ENABLE);
}


void push()
{
	stack[sp++]=ppos;
	lout(0L);
}

void pop()
{
	int32_t loc,save;
	if(ppos&1) bout(0);
	save=ppos;
	loc=stack[--sp];
	lseek(wfile,loc,0);
	lout(save-loc-4);
	lseek(wfile,save,0);
	ppos=save;
}

void lout(int32_t val)
{
	uchar buff4[4];

	buff4[0]=val>>24;
	buff4[1]=val>>16;
	buff4[2]=val>>8;
	buff4[3]=val;
	write(wfile,buff4,4);
	ppos+=4;
}

void wout(int val)
{
uchar buff2[2];
	buff2[0]=val>>8;
	buff2[1]=val;;
	write(wfile,buff2,2);
	ppos+=2;
}

void bout(uchar val)
{
	write(wfile,&val,1);
	ppos++;
}

void picline(char *put,int line)
{
	memcpy(put,(gfxsets+workingon)->gs_pic+320*line,320);
}

void savegfx()
{
uchar ttt[256];

	sprintf(ttt,"%s/%s/%s",localname,localdirname,gfxnames[workingon]);
	writeiff(ttt,320,200,picline,(gfxsets+workingon)->gs_colormap);
}

int writeiff(uchar *name, int width, int height, void (*fetch)(), uchar *colors)
{
int depth=8;
int i,j;
uchar trow[640];
uchar plane[128];
int rb;

	sp=0;
	rb=(width+7)>>3;
	ppos=0;
	wfile=open(name,O_WRONLY|O_CREAT|O_TRUNC|O_BINARY,0600);
	if(!wfile) return 1;
	lout(FORM);
	push();
	lout(ILBM);

	lout(BMHD);
	push();
	wout(width);
	wout(height);
	lout(0L); /* offsets */
	bout(depth); /* depth */
	bout(0); /* masking */
	bout(1); /* compression */
	bout(0); /* pad */
	wout(0); /* transparent */
	wout(0); /* aspect */
	wout(width); /* pagex */
	wout(height); /* pagey */
	pop();

	lout(CMAP);
	push();
	j=3<<depth;
	for(i=0;i<j;i++)
	{
		bout(colors[i]);
	}
	pop();

	lout(BODY);
	push();

	for(j=0;j<height;j++)
	{
		fetch(trow,j);
		for(i=0;i<depth;i++)
		{
			gather(plane,trow,rb,i);
			pack(plane,rb);
		}
	}

	pop();

	pop();

	close(wfile);
	return 0;
}

void gather(uchar *to,uchar *from,int len,int bit)
{
uchar mask;
int i;
uchar j,k;

	mask=1<<bit;
	while(len--)
	{
		i=8;
		j=128;
		k=0;
		while(i--)
		{
			if(*from++ & mask)
				k|=j;
			j>>=1;
		}
		*to++=k;
	}
} 


void pack(uchar *take, int rb)
{
int d0,d1,d2,d4,d5;
uchar *pnt=take;
uchar *pnt2;

	d4=rb;
/*pack1:*/
	d5=*pnt++;
	d4--;
p1:
	d1=0;
	pnt2=pnt-1;
p2:
	d2=1;
p3:
	d4--;
	if(d4<0) goto pout2;
	d0=*pnt++;
	if(d0!=d5) goto notsame;
	d2++;
	goto p3;
notsame:
	if(!d1) goto noliteral;
	if(d2>=3) goto n2;
n1:
	d5=d0;
	d1+=d2;
	goto p2;
noliteral:
	if(d2<2) goto n1;
n2:
	dpout(pnt2,d1,d2,d5);
	d5=d0;
	goto	p1;
pout2:
	if(d2<3) {d1+=d2;d2=1;}
	dpout(pnt2,d1,d2,d5);
}

void dpout(uchar *pnt2, int d1, int d2, int d5)
{
	if(d1)
	{
		bout(d1-1);
		while(d1--)
			bout(*pnt2++);
	}
	if(d2!=1)
	{
		bout(1-d2);
		bout(d5);
	}
}

