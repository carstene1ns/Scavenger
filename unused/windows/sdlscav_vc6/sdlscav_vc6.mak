# Microsoft Developer Studio Generated NMAKE File, Based on sdlscav_vc6.dsp
!IF "$(CFG)" == ""
CFG=sdlscav_vc6 - Win32 Debug
!MESSAGE No configuration specified. Defaulting to sdlscav_vc6 - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "sdlscav_vc6 - Win32 Release" && "$(CFG)" != "sdlscav_vc6 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "sdlscav_vc6.mak" CFG="sdlscav_vc6 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "sdlscav_vc6 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "sdlscav_vc6 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "sdlscav_vc6 - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\sdlscav_vc6.exe"


CLEAN :
	-@erase "$(INTDIR)\anim.obj"
	-@erase "$(INTDIR)\edit.obj"
	-@erase "$(INTDIR)\gfx.obj"
	-@erase "$(INTDIR)\scav.obj"
	-@erase "$(INTDIR)\sound.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\sdlscav_vc6.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /GX /O2 /I "c:\SDL-1.2.14\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\sdlscav_vc6.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\sdlscav_vc6.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib sdl.lib sdlmain.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\sdlscav_vc6.pdb" /machine:I386 /out:"$(OUTDIR)\sdlscav_vc6.exe" /libpath:"c:\sdl-1.2.14\lib" 
LINK32_OBJS= \
	"$(INTDIR)\anim.obj" \
	"$(INTDIR)\edit.obj" \
	"$(INTDIR)\gfx.obj" \
	"$(INTDIR)\scav.obj" \
	"$(INTDIR)\sound.obj"

"$(OUTDIR)\sdlscav_vc6.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "sdlscav_vc6 - Win32 Debug"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\sdlscav_vc6.exe"


CLEAN :
	-@erase "$(INTDIR)\anim.obj"
	-@erase "$(INTDIR)\edit.obj"
	-@erase "$(INTDIR)\gfx.obj"
	-@erase "$(INTDIR)\scav.obj"
	-@erase "$(INTDIR)\sound.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\sdlscav_vc6.exe"
	-@erase "$(OUTDIR)\sdlscav_vc6.ilk"
	-@erase "$(OUTDIR)\sdlscav_vc6.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /I "c:\SDL-1.2.14\include" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\sdlscav_vc6.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /mktyplib203 /win32 
RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\sdlscav_vc6.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib sdl.lib sdlmain.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\sdlscav_vc6.pdb" /debug /machine:I386 /out:"$(OUTDIR)\sdlscav_vc6.exe" /pdbtype:sept /libpath:"c:\sdl-1.2.14\lib" 
LINK32_OBJS= \
	"$(INTDIR)\anim.obj" \
	"$(INTDIR)\edit.obj" \
	"$(INTDIR)\gfx.obj" \
	"$(INTDIR)\scav.obj" \
	"$(INTDIR)\sound.obj"

"$(OUTDIR)\sdlscav_vc6.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("sdlscav_vc6.dep")
!INCLUDE "sdlscav_vc6.dep"
!ELSE 
!MESSAGE Warning: cannot find "sdlscav_vc6.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "sdlscav_vc6 - Win32 Release" || "$(CFG)" == "sdlscav_vc6 - Win32 Debug"
SOURCE=..\..\anim.c

"$(INTDIR)\anim.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\edit.c

"$(INTDIR)\edit.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\gfx.c

"$(INTDIR)\gfx.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\scav.c

"$(INTDIR)\scav.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\sound.c

"$(INTDIR)\sound.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

