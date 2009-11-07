#include <gtest/gtest.h>

#include "../graphics/color.hpp"

namespace {
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

    }
}

int main (int argc, char* argv[]) {
    ::testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS();
}
