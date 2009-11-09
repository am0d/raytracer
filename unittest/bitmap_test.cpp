#include <gtest/gtest.h>

#include "../graphics/bitmap.hpp"
#include "../graphics/color.hpp"
#include "../errors.hpp"

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

        Color pixel;
        // don't test every pixel - too slow
        // just test a sample of them
        for (int y=0; y<bitmap.getHeight(); y+=5) {
            for (int x=0; x<bitmap.getWidth(); x+=5) {
                pixel = bitmap.getPixel (x, y);
                EXPECT_FLOAT_EQ (0.0, pixel.getR());
                EXPECT_FLOAT_EQ (0.0, pixel.getG());
                EXPECT_FLOAT_EQ (0.0, pixel.getB());
            }
        }

        // test to make sure invalid size is no problem
        bitmap = Bitmap (-1, -1);
        EXPECT_GT (bitmap.getWidth(), 0);
        EXPECT_GT (bitmap.getHeight(), 0);
    }

    TEST(BitmapTest, BoundsAreAlwaysChecked) {
        Bitmap bitmap;
        Color pixel;

        EXPECT_EQ (E_OUT_OF_RANGE, bitmap.putPixel (
                    bitmap.getWidth(), 0, pixel));
        EXPECT_EQ (E_OUT_OF_RANGE, bitmap.putPixel (
                    0, bitmap.getHeight(), pixel));
        EXPECT_EQ (E_OUT_OF_RANGE, bitmap.putPixel (
                    -1, 0, pixel));
        EXPECT_EQ (E_OUT_OF_RANGE, bitmap.putPixel (
                    0, -1, pixel));
    }

    TEST(BitmapTest, PixelsAreSetCorrectly) {
        Bitmap bitmap (100, 100);
        Color blue (0.0, 0.0, 1.0);
        Color pixel;

        for (int y=0; y<bitmap.getHeight(); y+=10) {
            for (int x=0; x<bitmap.getWidth(); x+=10) {
                bitmap.putPixel (x, y, blue);
                pixel = bitmap.getPixel (x, y);
                EXPECT_FLOAT_EQ (blue.getR(), pixel.getR());
                EXPECT_FLOAT_EQ (blue.getG(), pixel.getG());
                EXPECT_FLOAT_EQ (blue.getB(), pixel.getB());
            }
        }
    }
}

int main (int argc, char* argv[]) {
    ::testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS();
}

