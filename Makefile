.SUFFIXES: .cxx

SOURCES = main.cpp raytracer.cxx

include graphics/include.mk
include math/include.mk
include mm/include.mk
include primitives/include.mk

OBJS := ${SOURCES:.cpp=.o}
OBJS := ${OBJS:.cxx=.o}
CXXFLAGS = 
LDFLAGS = 

CPP = g++
BIN = ./raytracer
IMAGEVIEWER = eog

all: $(BIN)

clean: 
	rm -f $(OBJS) $(BIN)

run: all
	$(BIN)
	$(IMAGEVIEWER) render.tga

$(BIN): $(OBJS)
	$(CPP) $(LDFLAGS) $(OBJS) -o $(BIN)

.cpp.o:
	$(CPP) $(CXXFLAGS) -o $@ -c $<

.cxx.o:
	$(CPP) $(CXXFLAGS) -o $@ -c $<

deps: 
	makedepend $(SOURCES)

# DO NOT DELETE

main.o: header.hpp /usr/include/math.h /usr/include/features.h
main.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
main.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
main.o: /usr/include/bits/huge_val.h /usr/include/bits/mathdef.h
main.o: /usr/include/bits/mathcalls.h /usr/include/SDL/SDL.h
main.o: /usr/include/SDL/SDL_main.h /usr/include/SDL/SDL_stdinc.h
main.o: /usr/include/SDL/SDL_config.h /usr/include/SDL/SDL_config-i386.h
main.o: /usr/include/SDL/SDL_platform.h /usr/include/sys/types.h
main.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
main.o: /usr/include/time.h /usr/include/endian.h /usr/include/bits/endian.h
main.o: /usr/include/sys/select.h /usr/include/bits/select.h
main.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
main.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
main.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
main.o: /usr/include/wchar.h /usr/include/bits/stdio_lim.h
main.o: /usr/include/bits/sys_errlist.h /usr/include/stdlib.h
main.o: /usr/include/alloca.h /usr/include/string.h /usr/include/strings.h
main.o: /usr/include/inttypes.h /usr/include/stdint.h
main.o: /usr/include/bits/wchar.h /usr/include/ctype.h /usr/include/iconv.h
main.o: /usr/include/SDL/begin_code.h /usr/include/SDL/close_code.h
main.o: /usr/include/SDL/SDL_audio.h /usr/include/SDL/SDL_error.h
main.o: /usr/include/SDL/SDL_endian.h /usr/include/SDL/SDL_mutex.h
main.o: /usr/include/SDL/SDL_thread.h /usr/include/SDL/SDL_rwops.h
main.o: /usr/include/SDL/SDL_cdrom.h /usr/include/SDL/SDL_cpuinfo.h
main.o: /usr/include/SDL/SDL_events.h /usr/include/SDL/SDL_active.h
main.o: /usr/include/SDL/SDL_keyboard.h /usr/include/SDL/SDL_keysym.h
main.o: /usr/include/SDL/SDL_mouse.h /usr/include/SDL/SDL_video.h
main.o: /usr/include/SDL/SDL_joystick.h /usr/include/SDL/SDL_quit.h
main.o: /usr/include/SDL/SDL_loadso.h /usr/include/SDL/SDL_timer.h
main.o: /usr/include/SDL/SDL_version.h mm/mmgr.h mm/nommgr.h errors.hpp
main.o: graphics/color.hpp header.hpp graphics/bitmap.hpp math/vector3.hpp
main.o: math/ray3d.hpp primitives/primitive.hpp primitives/sphere.hpp
main.o: primitives/scene.hpp raytracer.hpp
raytracer.o: header.hpp /usr/include/math.h /usr/include/features.h
raytracer.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
raytracer.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
raytracer.o: /usr/include/bits/huge_val.h /usr/include/bits/mathdef.h
raytracer.o: /usr/include/bits/mathcalls.h /usr/include/SDL/SDL.h
raytracer.o: /usr/include/SDL/SDL_main.h /usr/include/SDL/SDL_stdinc.h
raytracer.o: /usr/include/SDL/SDL_config.h /usr/include/SDL/SDL_config-i386.h
raytracer.o: /usr/include/SDL/SDL_platform.h /usr/include/sys/types.h
raytracer.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
raytracer.o: /usr/include/time.h /usr/include/endian.h
raytracer.o: /usr/include/bits/endian.h /usr/include/sys/select.h
raytracer.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
raytracer.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
raytracer.o: /usr/include/bits/pthreadtypes.h /usr/include/stdio.h
raytracer.o: /usr/include/libio.h /usr/include/_G_config.h
raytracer.o: /usr/include/wchar.h /usr/include/bits/stdio_lim.h
raytracer.o: /usr/include/bits/sys_errlist.h /usr/include/stdlib.h
raytracer.o: /usr/include/alloca.h /usr/include/string.h
raytracer.o: /usr/include/strings.h /usr/include/inttypes.h
raytracer.o: /usr/include/stdint.h /usr/include/bits/wchar.h
raytracer.o: /usr/include/ctype.h /usr/include/iconv.h
raytracer.o: /usr/include/SDL/begin_code.h /usr/include/SDL/close_code.h
raytracer.o: /usr/include/SDL/SDL_audio.h /usr/include/SDL/SDL_error.h
raytracer.o: /usr/include/SDL/SDL_endian.h /usr/include/SDL/SDL_mutex.h
raytracer.o: /usr/include/SDL/SDL_thread.h /usr/include/SDL/SDL_rwops.h
raytracer.o: /usr/include/SDL/SDL_cdrom.h /usr/include/SDL/SDL_cpuinfo.h
raytracer.o: /usr/include/SDL/SDL_events.h /usr/include/SDL/SDL_active.h
raytracer.o: /usr/include/SDL/SDL_keyboard.h /usr/include/SDL/SDL_keysym.h
raytracer.o: /usr/include/SDL/SDL_mouse.h /usr/include/SDL/SDL_video.h
raytracer.o: /usr/include/SDL/SDL_joystick.h /usr/include/SDL/SDL_quit.h
raytracer.o: /usr/include/SDL/SDL_loadso.h /usr/include/SDL/SDL_timer.h
raytracer.o: /usr/include/SDL/SDL_version.h mm/mmgr.h mm/nommgr.h errors.hpp
raytracer.o: graphics/color.hpp header.hpp graphics/bitmap.hpp
raytracer.o: math/vector3.hpp math/ray3d.hpp primitives/primitive.hpp
raytracer.o: primitives/sphere.hpp primitives/scene.hpp raytracer.hpp
graphics/color.o: header.hpp
graphics/bitmap.o: header.hpp
math/vector3.o: header.hpp
math/ray3d.o: header.hpp
mm/mmgr.o: /usr/include/stdio.h /usr/include/features.h
mm/mmgr.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
mm/mmgr.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
mm/mmgr.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
mm/mmgr.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
mm/mmgr.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
mm/mmgr.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
mm/mmgr.o: /usr/include/endian.h /usr/include/bits/endian.h
mm/mmgr.o: /usr/include/sys/select.h /usr/include/bits/select.h
mm/mmgr.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
mm/mmgr.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
mm/mmgr.o: /usr/include/alloca.h /usr/include/assert.h /usr/include/string.h
mm/mmgr.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
mm/mmgr.o: /usr/include/bits/confname.h /usr/include/getopt.h mm/mmgr.h
mm/mmgr.o: mm/nommgr.h
primitives/primitive.o: header.hpp
primitives/sphere.o: header.hpp
primitives/scene.o: header.hpp
