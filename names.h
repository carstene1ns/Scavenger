/* SCAVENGER David Ashley dash@xdr.com SDL ver Barry Mead barrymead@cox.net */
/* License GPL.  See COPYING for details of GPL License */
/* $Author$    $Date$   $Id$   $Revision$ */

#ifndef NAMES_H
#define NAMES_H

#ifndef LIBPATH
#if defined(__WIN32__) || defined(WIN32)
#define LIBPATH "data"
#else
#define LIBPATH "data:/usr/local/games/scavenger"
#endif
#endif

#ifndef LOCALDIRNAME
#if defined(__WIN32__) || defined(WIN32)
#define LOCALDIRNAME "scav"
#else
#define LOCALDIRNAME ".scavenger"
#endif
#endif

#define RCNAME "scavrc"
#define LEVELSNAME "levels.scl"
#define MASTERNAME "masters.scl"
#define NEWLEVELSNAME "levels.new"
#define PLAYERNAME "player.nam"
#define ENVHOME "HOME"
#define ENVUSER "USER"

#endif
