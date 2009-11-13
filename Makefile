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
main.o: /usr/include/bits/typesizes.h /usr/include/stdlib.h
main.o: /usr/include/sys/types.h /usr/include/endian.h
main.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
main.o: /usr/include/sys/select.h /usr/include/bits/select.h
main.o: /usr/include/bits/sigset.h /usr/include/sys/sysmacros.h
main.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h errors.hpp
main.o: graphics/color.hpp graphics/bitmap.hpp graphics/color.hpp errors.hpp
main.o: math/vector3.hpp math/ray3d.hpp header.hpp primitives/primitive.hpp
main.o: primitives/sphere.hpp primitives/scene.hpp raytracer.hpp
raytracer.o: raytracer.hpp graphics/color.hpp graphics/bitmap.hpp
raytracer.o: graphics/color.hpp errors.hpp primitives/scene.hpp header.hpp
raytracer.o: math/ray3d.hpp
graphics/color.o: graphics/color.hpp
math/vector3.o: /usr/include/math.h /usr/include/features.h
math/vector3.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
math/vector3.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
math/vector3.o: /usr/include/bits/huge_val.h /usr/include/bits/mathdef.h
math/vector3.o: /usr/include/bits/mathcalls.h math/vector3.hpp
math/ray3d.o: header.hpp
primitives/primitive.o: header.hpp
primitives/sphere.o: header.hpp
primitives/scene.o: header.hpp
