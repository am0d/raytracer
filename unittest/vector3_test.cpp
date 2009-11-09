#include <gtest/gtest.h>

#include "../math/vector3.hpp"

namespace {
    TEST(Vector3Test, CanSetComponentValues) {
        Vector3 vector;

        vector.setX (-3.14);
        EXPECT_FLOAT_EQ (-3.14, vector.getX());
        vector.setX (3.14);
        EXPECT_FLOAT_EQ (3.14, vector.getX());
    }
}

int main (int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
