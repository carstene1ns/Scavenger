How to build sdlscav under Windows
==================================

Install the latest development SDL library for WIN32 from libsdl.org.
At this time the file is called SDL-devel-1.2.14-VC6.zip.

If you are using MS Visual C++ .NET 2003, open the solution file sdlscav-win32
and build it. This will eventually generate sdlscav-win32-install.msi.

If you are using MS Visual C++ 6.0, use the project in sdlscav_vc6. It willonly generate an executable.

For both compilers, there is a Debug and Release target.
