.SUFFIXES: .cxx

SOURCES = $(wildcard src/*.cpp)

OBJS := ${SOURCES:.cpp=.o}
CXXFLAGS = -g -Wall -pedantic -ansi -Warray-bounds -Wclobbered -Wconversion -Wdeprecated -Weffc++ -Wenum-compare -Wextra -Wreorder -Wold-style-cast -Wabi
LDFLAGS = 

CPP = g++
BIN = bin/raytracer
IMAGEVIEWER = eog

all: $(BIN) 

clean: 
	rm -f $(OBJS) $(BIN)

run: $(BIN)
	$(BIN)
	$(IMAGEVIEWER) render.tga

$(BIN): $(OBJS)
	$(CPP) $(LDFLAGS) $(OBJS) -o $(BIN)

.cpp.:
	$(CPP) $(CXXFLAGS) -o $@ -c $<

deps: 
	makedepend $(SOURCES)

# DO NOT DELETE

src/bitmap.o: /usr/include/string.h /usr/include/features.h
src/bitmap.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
src/bitmap.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
src/bitmap.o: /usr/include/xlocale.h src/bitmap.hpp src/color.hpp
src/bitmap.o: src/errors.hpp
src/sphere.o: src/sphere.hpp src/primitive.hpp src/color.hpp src/vector3.hpp
src/sphere.o: src/ray3d.hpp
src/color.o: src/color.hpp
src/scene.o: src/scene.hpp src/primitive.hpp src/color.hpp src/vector3.hpp
src/scene.o: src/ray3d.hpp
src/ray3d.o: src/ray3d.hpp src/vector3.hpp
src/raytracer.o: src/raytracer.hpp src/color.hpp src/bitmap.hpp
src/raytracer.o: src/errors.hpp src/scene.hpp src/primitive.hpp
src/raytracer.o: src/vector3.hpp src/ray3d.hpp
src/vector3.o: /usr/include/math.h /usr/include/features.h
src/vector3.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
src/vector3.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
src/vector3.o: /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h
src/vector3.o: /usr/include/bits/huge_vall.h /usr/include/bits/inf.h
src/vector3.o: /usr/include/bits/nan.h /usr/include/bits/mathdef.h
src/vector3.o: /usr/include/bits/mathcalls.h src/vector3.hpp
src/main.o: src/raytracer.hpp src/color.hpp src/bitmap.hpp src/errors.hpp
src/main.o: src/scene.hpp src/primitive.hpp src/vector3.hpp src/ray3d.hpp
src/primitive.o: src/primitive.hpp src/color.hpp src/vector3.hpp
src/primitive.o: src/ray3d.hpp
