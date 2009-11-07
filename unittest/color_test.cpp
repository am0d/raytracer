#include <gtest/gtest.h>

#include "../graphics/color.hpp"

namespace {
    TEST(ColorTest, AlternateConstructorSetsColors) {
        Color color (1.0, 1.0, 1.0);

        EXPECT_FLOAT_EQ (color.getR(), 1.0);
        EXPECT_FLOAT_EQ (color.getG(), 1.0);
        EXPECT_FLOAT_EQ (color.getB(), 1.0);
    }

    TEST(ColorTest, SetRedCorrectly) {
        Color color;
        // make sure that the boundaries are correct
        color.setR (1.0f);
        EXPECT_FLOAT_EQ (color.getR(), 1.0f);
        color.setR (0.0f);
        EXPECT_FLOAT_EQ (color.getR(), 0.0f);

        color.setR (0.395f);
        EXPECT_FLOAT_EQ (color.getR(), 0.395f);

        //make sure that we cap in-valid values
        color.setR (-0.1);
        EXPECT_FLOAT_EQ (color.getR(), 0.0f);
        color.setR (1.1f);
        EXPECT_FLOAT_EQ (color.getR(), 1.0f);
    }

    TEST(ColorTest, SetGreenCorrectly) {
        Color color;
        // make sure that the boundaries are correct
        color.setG (1.0f);
        EXPECT_FLOAT_EQ (color.getG(), 1.0f);
        color.setG (0.0f);
        EXPECT_FLOAT_EQ (color.getG(), 0.0f);

        color.setG (0.395f);
        EXPECT_FLOAT_EQ (color.getG(), 0.395f);

        //make sure that we cap in-valid values
        color.setG (-0.1);
        EXPECT_FLOAT_EQ (color.getG(), 0.0f);
        color.setG (1.1f);
        EXPECT_FLOAT_EQ (color.getG(), 1.0f);
    }

    TEST(ColorTest, SetBlueCorrectly) {
        Color color;
        // make sure that the boundaries are correct
        color.setB (1.0f);
        EXPECT_FLOAT_EQ (color.getB(), 1.0f);
        color.setB (0.0f);
        EXPECT_FLOAT_EQ (color.getB(), 0.0f);

        color.setB (0.395f);
        EXPECT_FLOAT_EQ (color.getB(), 0.395f);

        //make sure that we cap in-valid values
        color.setB (-0.1);
        EXPECT_FLOAT_EQ (color.getB(), 0.0f);
        color.setB (1.1f);
        EXPECT_FLOAT_EQ (color.getB(), 1.0f);
    }

    TEST(ColorTest, AssignmentOperatorWorks) {
        Color color1 (0.3, 0.4, 0.5);
        Color color2 = color1;

        EXPECT_FLOAT_EQ (color1.getR(), color2.getR());
        EXPECT_FLOAT_EQ (color1.getG(), color2.getG());
        EXPECT_FLOAT_EQ (color1.getB(), color2.getB());
    }

    TEST(ColorTest, ScaleColorCorrectly) {
        Color color1 (1.0, 1.0, 1.0);
        Color color2;

        color2 = color1 * 0.5;
        EXPECT_FLOAT_EQ (color1.getR()*0.5, color2.getR());
        EXPECT_FLOAT_EQ (color1.getG()*0.5, color2.getG());
        EXPECT_FLOAT_EQ (color1.getB()*0.5, color2.getB());
    }
}

int main (int argc, char* argv[]) {
    ::testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS();
}
