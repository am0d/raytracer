.SUFFIXES: .cxx

SOURCES = main.cpp raytracer.cxx
TESTS = 

include graphics/include.mk
include math/include.mk
include primitives/include.mk

OBJS := ${SOURCES:.cpp=.o}
OBJS := ${OBJS:.cxx=.o}
CXXFLAGS = -g -Wall -pedantic
LDFLAGS = 

CPP = g++
BIN = ./raytracer
IMAGEVIEWER = eog

all: $(BIN) 
	@$(MAKE) -f unittest/Makefile tests

clean: 
	rm -f $(OBJS) $(BIN)

run: $(BIN)
	$(BIN)
	$(IMAGEVIEWER) render.tga

$(BIN): $(OBJS)
	$(CPP) $(LDFLAGS) $(OBJS) -o $(BIN)

.cpp.:
	$(CPP) $(CXXFLAGS) -o $@ -c $<

.cxx.o:
	$(CPP) $(CXXFLAGS) -o $@ -c $<

%:
	@$(MAKE) -f unittest/Makefile $@
deps: 
	makedepend $(SOURCES)

# DO NOT DELETE

main.o: header.hpp /usr/include/math.h /usr/include/features.h
main.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
main.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
main.o: /usr/include/bits/huge_val.h /usr/include/bits/mathdef.h
main.o: /usr/include/bits/mathcalls.h /usr/include/time.h
main.o: /usr/include/bits/time.h /usr/include/bits/types.h
main.o: /usr/include/bits/typesizes.h /usr/include/SDL/SDL.h
main.o: /usr/include/SDL/SDL_main.h /usr/include/SDL/SDL_stdinc.h
main.o: /usr/include/SDL/SDL_config.h /usr/include/SDL/SDL_config-i386.h
main.o: /usr/include/SDL/SDL_platform.h /usr/include/sys/types.h
main.o: /usr/include/endian.h /usr/include/bits/endian.h
main.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
main.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
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
main.o: /usr/include/SDL/SDL_version.h errors.hpp graphics/color.hpp
main.o: graphics/bitmap.hpp graphics/color.hpp errors.hpp math/vector3.hpp
main.o: header.hpp math/ray3d.hpp primitives/primitive.hpp
main.o: primitives/sphere.hpp primitives/scene.hpp raytracer.hpp
raytracer.o: raytracer.hpp graphics/color.hpp graphics/bitmap.hpp
raytracer.o: graphics/color.hpp errors.hpp primitives/scene.hpp header.hpp
raytracer.o: math/ray3d.hpp
graphics/bitmap.o: graphics/bitmap.hpp graphics/color.hpp errors.hpp
graphics/color.o: graphics/color.hpp
math/vector3.o: header.hpp
math/ray3d.o: header.hpp
primitives/primitive.o: header.hpp
primitives/sphere.o: header.hpp
primitives/scene.o: header.hpp
