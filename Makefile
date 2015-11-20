CC	= gcc
CFLAGS	= -O2 `sdl-config --cflags`

sdlscav:	scav.o gfx.o sound.o edit.o anim.o
	gcc -o sdlscav scav.o gfx.o sound.o edit.o anim.o `sdl-config --libs`
	install -m 0755 -d $$HOME/.scavenger
	install -m 0644 data/*rc $$HOME/.scavenger

scav.o: scav.c scav.h names.h edit.h anim.h gfx.h sound.h

gfx.o:	gfx.c  scav.h

sound.o:	sound.c

edit.o:	edit.c scav.h edit.h gfx.h

anim.o:	anim.c scav.h anim.h gfx.h

clean:
	rm -f *.o sdlscav *~
install:
	install -m 0755 -d /usr/local/games/scavenger
	install -m 0755 -d /usr/local/bin
	install -m 0644 data/*.lbm /usr/local/games/scavenger/
	install -m 0644 data/*.wav /usr/local/games/scavenger/
	install -m 0644 data/*.scl /usr/local/games/scavenger/
	install -m 0755 sdlscav /usr/local/bin/
	install -m 0755 scavsaver /usr/local/bin/

