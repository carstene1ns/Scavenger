/* SCAVENGER David Ashley dash@.com SDL ver Barry Mead barrymead@cox.net */
/* License GPL.  See COPYING for details of GPL License */
/* $Author$    $Date$   $Id$   $Revision$ */

#include "scav.h"

uchar editlevel[LEVELSIZE];
int edittype;

int typemap[]={SDLK_F1,SDLK_F2,SDLK_F3,SDLK_F4,SDLK_F5,SDLK_F6,
               SDLK_F7,SDLK_F8,SDLK_F9,SDLK_F10,SDLK_F11,SDLK_F12};
int numpadmap[]={SDLK_KP0,SDLK_KP1,SDLK_KP2,SDLK_KP3,SDLK_KP4,
                 SDLK_KP5,SDLK_KP6,SDLK_KP7,SDLK_KP8,SDLK_KP9};
int numbermap[]={SDLK_0,SDLK_1,SDLK_2,SDLK_3,SDLK_4,SDLK_5,
                 SDLK_6,SDLK_7,SDLK_8,SDLK_9};
uchar ewant[80];
uchar emark;
uchar erepaint;
uchar emodified;
int numkey=0;
int etime;

int edownx,edowny,edownwhere,edownb;


void filllevel(uchar *p, int val)
{
int i,j;

	for(j=0;j<17;j++)
		for(i=0;i<28;i++)
		{
			if(j>0 && j<16 && i>1 && i<26)
				*p++=val;
			else
				*p++=BORDER;
		}
}

void editinit()
{

	filllevel(editlevel,EMPTY);
	edittype=BRICK;
	etime=emark=0;
	emodified=0;
}

uchar *checks()
{
int i,j;
int hist[16];
uchar ch;

	
	for(i=0;i<16;i++) hist[i]=0;

	for(i=0;i<LEVELSIZE;i++)
	   hist[levelbuff[i]]++;
	if(hist[HERO]!=1)
		return "level must have exactly 1 player";
	if(hist[ENEMY]>5)
		return "level cannot have more than 5 enemies";
   if (checkpressed(SDLK_RALT))
   {
      if ((hist[FLASHING] < 0) || (hist[FLASHING] > 3)) /* Right ALT allows all legal values */
         return "number of flashing berries must be 0 to 3";
   }
   else
   {
	   if(hist[FLASHING]!=0 && hist[FLASHING]!=3)
		   return "level must have exactly 0 or 3 flashing objects";
   }
   if (checkpressed(SDLK_RALT))
   {
      if((hist[HIDDEN] < 0) || (hist[HIDDEN] > 3))
         return "number of hidden ememies must be 0 to 3";
   }
   else
   {
	   if(hist[HIDDEN]!=0 && hist[HIDDEN]!=3)
		   return "level must have exactly 0 or 3 hidden enemies";
   }
	if(hist[ESCAPE] && !hist[GOLD] && !hist[FLASHING])
		return "if you have escape ladders, you must have at least 1 object";
	j=0;
	for(i=0;i<24;i++)
	{
		ch=levelbuff[i+30];
		if(ch==EMPTY || ch==HERO || ch==ENEMY)
			j++;
	}
	if(!j)
		return "there must be at least 1 empty space on the top row";
	return 0;
}


void ebox0(int which)
{
int x,y;
	x=ETYPEX+which*ETYPESPACE;
	y=ETYPEY;
	drawbox(x,y,25,ACOLOR);
	needwhole=1;
}

void ebox1(int which)
{
int x,y;
	x=ETYPEX+which*ETYPESPACE;
	y=ETYPEY;
	drawbox(x,y,25,BCOLOR);
	needwhole=1;
}

void paintedit()
{
int i;
	clear();
	paintlevel();
	puteinfo();
	for(i=0;i<12;i++)
	{
		puttile(i*ETYPESPACE+ETYPEX+1,ETYPEY+1,i);
	}
	ebox1(edittype);
	copyup();
}

void toedit()
{
int i;
   if(clevel==0) clevel=1;
	fadeout();
	restoresprites();
   if(!loadlevel(clevel))
		filllevel(levelbuff,0);
	emodified=0;
	for(i=0;i<LEVELSIZE;i++)
		editlevel[i]=levelbuff[i];
	paintedit();
	fadein();
	mode=mode4;
   SDL_ShowCursor(SDL_ENABLE);
	etime=0;
	erepaint=2;
}

void mode4() /* level editor */
{
int i,j;
uchar *p;
int got;
uchar buff[16];
uchar tlevel[180],*p1,*p2;

	if(checkdown(SDLK_ESCAPE) || checkdown(SDLK_SPACE)) /* esc */
	{
      numkey=0;
      if(clevel==0)clevel=1;
      if (!loadlevel(clevel))
      {
         clevel=1;
         loadlevel(clevel);
      }
		fadeout();
		restoresprites();
		clear();
		for(i=0;i<LEVELSIZE;i++)
			editlevel[i]=levelbuff[i];
      mode=mode1;
		startgame();
	} else
	if(checkdown(SDLK_LEFT)) /* left arrow */
	{
      numkey=0;
		if(clevel>1)
		{
			clevel--;
			etime=1;
		}
	} else
	if(checkdown(SDLK_RIGHT)) /* right arrow */
	{
      numkey=0;
      if(clevel<(MAXLEVELS))
      {
		   clevel++;
		   etime=1;
      }
	} else
   if(checkdown(SDLK_UP)) /* up arrow */
   {
      numkey=0;
      if(clevel<(MAXLEVELS-9))
      {
         clevel+=10;
         etime=1;
      }
   } else
   if(checkdown(SDLK_DOWN)) /* down arrow */
   {
      numkey=0;
      if(clevel>10)
      {
         clevel-=10;
         etime=1;
      }
   }
   if(checkdown(SDLK_PAGEUP)) /* Page Up */
   {
      numkey=0;
      if(clevel<(MAXLEVELS-99))
      {
         clevel+=100;
         etime=1;
      }
   }
   if(checkdown(SDLK_PAGEDOWN)) /* Page Down */
   {
      numkey=0;
      if(clevel>100)
      {
         clevel-=100;
         etime=1;
      }
   }
   for (i=0; i <= 9; i++)
	  if((checkdown(numpadmap[i]) || checkdown(numbermap[i])) && !emodified) /* #0-9 */
	  {
        if((i==0) && (numkey==0)) break; /* leading zeros do nothing */
        if(numkey==0)
        {
           numkey=1;
           clevel=i;
        }
        else
            clevel=(clevel*10)+i;
       if (clevel > (MAXLEVELS))
       {
          clevel = 1;
          numkey = 0;
       }
       etime=1;
       break;
	  };
	if(checkdown(SDLK_KP_PLUS) || checkdown(SDLK_EQUALS))
   {
      if(emodified)
         centermsg("Save or load before changing levels");
      else
      {
         if(clevel < (MAXLEVELS))
         {
            clevel++;
            etime=1;
            if(!loadlevel(clevel))
               filllevel(levelbuff,0);
            emodified=0;
            erepaint=2;
         }
      }
	} else
	if(checkdown(SDLK_KP_MINUS) || checkdown(SDLK_MINUS))
   {
      if(emodified)
         centermsg("Save or load before changing levels");
      else
      {
         numkey=0;
         if(clevel>1)
         {
            clevel--;
            etime=1;
            if(!loadlevel(clevel))
               filllevel(levelbuff,0);
            emodified=0;
            erepaint=2;
         }
      }
	} else
	if(checkdown(SDLK_l) || checkdown(SDLK_KP_ENTER) || checkdown(SDLK_RETURN)) /* l */
	{
      numkey=0;
      if(clevel==0)clevel=1;
		if(emodified && !(checkpressed(SDLK_LALT) || checkpressed(SDLK_RALT)))
			centermsg("use alt-l to load over modified level");
		else
      {
			if(!loadlevel(clevel))
		      filllevel(levelbuff,0);
         puteinfo();
			emodified=0;
			erepaint=2;
      }
	}
	if(checkdown(SDLK_w)) /* w */
	{
      numkey=0;
		if((p=checks()))
		{
			centermsg(p);
		} else
		{
			i=1;
			if(clevel==0)
			{
				i=0;
				centermsg("cannot write level 0");
			}
			if(i && 
                           !(checkpressed(SDLK_LALT) || checkpressed(SDLK_RALT)))
			{
				got=getresource((clevel-1)<<1,buff,16);
				if(got>0)
				{
					close(file);
					centermsg("use alt-w to overwrite existing level");
					i=0;
				}
			}
			if(i)
			{
				p1=levelbuff+30;
				p2=tlevel;
				for(j=0;j<15;j++)
				{
					for(i=0;i<12;i++)
					{
						*p2++ = (*p1<<4) | p1[1];
						p1+=2;
					}
					p1+=4;
				}
				if(putresource((clevel-1)<<1,tlevel,180))
					centermsg("could not write level");
				else if(putresource(((clevel-1)<<1)+1,levelbuff,0))
					centermsg("could not delete movie");
				else    {
					centermsg("level saved");
                                        emodified=0;
                                        }
			}
		}
	}
}

int efindcurs()
{
int i,j;

	if(curx>=XOFF && curx<XOFF+TX*LX && cury>=YOFF && cury<YOFF+TY*LY)
		return ELEVEL;
	if(cury>=ETYPEY && cury<ETYPEY+24 && curx>=ETYPEX)
	{
		i=(curx-ETYPEX)/ETYPESPACE;
		j=(curx-ETYPEX)%ETYPESPACE;
		if(i>=0 && i<12 && j<24)
			return ETYPES;
	}
	return 0;
}


void centermsg(uchar *from)
{
int i,j,k;
uchar *to=ewant;

	i=strlen(from);
	j=(72-i)/2;
	k=72-i-j;
	while(j--) *to++=' ';
	while((*to++=*from++));
	to--;
	while(k--) *to++=' ';
	*to=0;
	emark=1;
}
uchar *einfo()
{
int i;
	sprintf(temp,"LEVEL %04d  L=LOAD W=WRITE ESC=EXIT 0-9 CHANGE LEVEL KP +- UP/DN LEVEL",clevel);
	i=strlen(temp);
	while(i<72)
		temp[i++]=' '; /* space fill to constant 72 character length */
	temp[i]=0;
	return temp;
}
void puteinfo()
{
	strcpy(ewant,einfo());
	writestring(einfo(),TEXTX,TOPTEXTY,whitecolor);
   writestring("F1 - F12 ->",30,457,whitecolor);
	needtoptext=1;
}
void editprocess()
{
int where;
int x,y;
int i,j;
uchar *at;

	if(mode!=mode4) return;

	if(emark)
	{
		writestring(ewant,TEXTX,TOPTEXTY,whitecolor);
		needtoptext=1;
		emark=0;
		etime=120;
	}
	if(etime)
	{
		etime--;
		if(etime==0)
		{
         puteinfo();
		}
	}
	if((checkpressed(SDLK_LALT) || checkpressed(SDLK_RALT)) && 
           checkdown(SDLK_f)) /* alt-f */
	{
      numkey=0;
		filllevel(levelbuff,edittype);
		erepaint=2;
	}
	if(erepaint)
	{
		erepaint--;
		paintlevel();
		copyup();
	}
	where=efindcurs();
	if(mbuttons2)
	{
      numkey=0;
		edownx=curx;
		edowny=cury;
		edownb=mbuttons2;
		edownwhere=efindcurs();
		if(edownwhere==ETYPES)
		{
			i=(curx-ETYPEX)/ETYPESPACE;
			if(edittype!=i)
			{
				ebox0(edittype);
				edittype=i;
				ebox1(edittype);
			}
		}
	}
	if(mbuttons)
	{
      numkey=0;
		if(edownwhere==ELEVEL && where==ELEVEL)
		{
			j=(edownb&1) ? edittype : EMPTY;
			x=(curx-XOFF)/TX;
			y=(cury-YOFF)/TY;
			at=levelbuff+30+y*28+x;

			if(*at!=j)
			{
				*at=j;
				fix(at);
				fix(at+1);
				fix(at+28);
				fix(at+29);
				emodified=1;
			}
		}
	}
	for(i=0;i<12;i++)
	{
		if(checkpressed(typemap[i]))
		{
         numkey=0;
			if(edittype!=i)
			{
				ebox0(edittype);
				edittype=i;
				ebox1(edittype);
			}
		}
	}
}
