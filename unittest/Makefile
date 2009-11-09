TESTS = bitmap_test color_test vector3_test

CPP = c++
CXXFLAGS = -g -lgtest -Wall -pedantic 

tests: $(TESTS)
	unittest/bitmap_test
	unittest/color_test
	unittest/vector3_test

test_clean:
	rm -f unittest/{$(TESTS)}

bitmap_test: unittest/bitmap_test.cpp graphics/bitmap.hpp graphics/bitmap.cxx graphics/color.hpp graphics/color.cxx
	$(CPP) $(CXXFLAGS) -o unittest/bitmap_test unittest/bitmap_test.cpp graphics/bitmap.cxx graphics/color.cxx

color_test: unittest/color_test.cpp graphics/color.hpp graphics/color.cxx
	$(CPP) $(CXXFLAGS) -o unittest/color_test unittest/color_test.cpp graphics/color.cxx

vector3_test: unittest/vector3_test.cpp math/vector3.hpp math/vector3.cxx
	$(CPP) $(CXXFLAGS) -o unittest/vector3_test unittest/vector3_test.cpp math/vector3.cxx
