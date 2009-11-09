#include <gtest/gtest.h>

#include "../graphics/bitmap.hpp"
#include "../graphics/color.hpp"

namespace {
    TEST(BitmapTest, DefaultConstructorCreatesUsableBitmap) {
        Bitmap bitmap = Bitmap ();
        EXPECT_GT (bitmap.getWidth(), 0);
        EXPECT_GT (bitmap.getHeight(), 0);
        
        Color pixel = bitmap.getPixel (0, 0);
        EXPECT_FLOAT_EQ (0.0, pixel.getR());
        EXPECT_FLOAT_EQ (0.0, pixel.getG());
        EXPECT_FLOAT_EQ (0.0, pixel.getB());
    }

    TEST(BitmapTest, AlternateConstructorSetsCorrectSize) {
        Bitmap bitmap = Bitmap (640, 480);
        EXPECT_EQ (640, bitmap.getWidth());
        EXPECT_EQ (480, bitmap.getHeight());
    }
}

int main (int argc, char* argv[]) {
    ::testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS();
}

