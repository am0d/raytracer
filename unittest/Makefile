TESTS = unittest/bitmap_test unittest/color_test unittest/vector3_test unittest/ray3d_test

CPP = c++
CXXFLAGS = -g -lgtest -Wall -pedantic -ansi -Warray-bounds -Wclobbered -Wconversion -Wdeprecated -Weffc++ -Wenum-compare -Wextra -Wreorder -Wold-style-cast -Wabi

tests: $(TESTS)
	unittest/bitmap_test
	unittest/color_test
	unittest/vector3_test
	unittest/ray3d_test

test_clean:
	rm -f $(TESTS)

unittest/bitmap_test: unittest/bitmap_test.cpp graphics/bitmap.o graphics/color.o
	$(CPP) $(CXXFLAGS) -o unittest/bitmap_test unittest/bitmap_test.cpp graphics/bitmap.cxx graphics/color.cxx

unittest/color_test: unittest/color_test.cpp graphics/color.o
	$(CPP) $(CXXFLAGS) -o unittest/color_test unittest/color_test.cpp graphics/color.o

unittest/vector3_test: unittest/vector3_test.cpp math/vector3.o
	$(CPP) $(CXXFLAGS) -o unittest/vector3_test unittest/vector3_test.cpp math/vector3.o

unittest/ray3d_test: unittest/ray3d_test.cpp math/vector3.o math/ray3d.o
	$(CPP) $(CXXFLAGS) -o unittest/ray3d_test unittest/ray3d_test.cpp math/vector3.o math/ray3d.o
