TESTS = bitmap_test color_test

CPP = c++
CXXFLAGS = -lgtest

tests: bitmap_test color_test
	unittest/bitmap_test
	unittest/color_test

bitmap_test: unittest/bitmap_test.cpp graphics/bitmap.hpp graphics/bitmap.cxx graphics/color.hpp graphics/color.cxx
	$(CPP) $(CXXFLAGS) -o unittest/bitmap_test unittest/bitmap_test.cpp graphics/bitmap.cxx graphics/color.cxx

color_test: unittest/color_test.cpp graphics/color.hpp graphics/color.cxx
	$(CPP) $(CXXFLAGS) -o unittest/color_test unittest/color_test.cpp graphics/color.cxx
