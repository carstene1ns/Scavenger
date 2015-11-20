/* SCAVENGER David Ashley dash@xdr.com SDL ver Barry Mead barrymead@cox.net */
/* License GPL.  See COPYING for details of GPL License */
/* $Author$    $Date$   $Id$   $Revision$ */

#ifndef EDIT_H
#define EDIT_H

#define ETYPEX 128
#define ETYPEY 450
#define ETYPESPACE 32

#define ETYPES 1
#define ELEVEL 2


extern void filllevel(uchar *p, int val);
extern void editinit();
extern uchar *checks();
extern void ebox0(int which);
extern void ebox1(int which);
extern void paintedit();
extern void toedit();
extern void mode4(); /* level editor */
extern int efindcurs();
extern void centermsg(uchar *from);
extern uchar *einfo();
extern void puteinfo();
extern void editprocess();

#endif
