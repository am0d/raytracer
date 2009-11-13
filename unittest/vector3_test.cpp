#include <gtest/gtest.h>

#include "../math/vector3.hpp"

namespace {
    TEST (Vector3Test, CanSetComponentValues) {
        Vector3 vector;

        vector.setX (-3.14);
        EXPECT_FLOAT_EQ (-3.14, vector.getX());
        vector.setX (3.14);
        EXPECT_FLOAT_EQ (3.14, vector.getX());

        vector.setY (-3.14);
        EXPECT_FLOAT_EQ (-3.14, vector.getY());
        vector.setY (3.14);
        EXPECT_FLOAT_EQ (3.14, vector.getY());

        vector.setZ (-3.14);
        EXPECT_FLOAT_EQ (-3.14, vector.getZ());
        vector.setZ (3.14);
        EXPECT_FLOAT_EQ (3.14, vector.getZ());
    }

    TEST (Vector3Test, DotProductTest) {
        Vector3 v1 (-10, 5, 2.5);
        Vector3 v2 (2, 3, -1);
        float dotProduct = v1.dotProduct(v2);

        EXPECT_FLOAT_EQ (-7.5, dotProduct);
    }

    TEST (Vector3Test, AssignmentOperatorTest) {
        Vector3 v1 (-10, 5, 2.5);
        Vector3 v2 = v1;

        EXPECT_FLOAT_EQ (v1.getX(), v2.getX());
        EXPECT_FLOAT_EQ (v1.getY(), v2.getY());
        EXPECT_FLOAT_EQ (v1.getZ(), v2.getZ());
    }

    TEST (Vector3Test, AdditionOperatorTest) {
        Vector3 v1 (-10, 5, 2.5);
        Vector3 v2 (5, 2.43, -3.6);
        Vector3 v3 = v1 + v2;

        EXPECT_FLOAT_EQ (v3.getX(), v1.getX() + v2.getX());
        EXPECT_FLOAT_EQ (v3.getY(), v1.getY() + v2.getY());
        EXPECT_FLOAT_EQ (v3.getZ(), v1.getZ() + v2.getZ());
    }

    TEST (Vector3Test, SubtractionOperatorTest) {
        Vector3 v1 (-10, 5, 2.5);
        Vector3 v2 (5, 2.43, -3.6);
        Vector3 v3 = v1 - v2;

        EXPECT_FLOAT_EQ (v3.getX(), v1.getX() - v2.getX());
        EXPECT_FLOAT_EQ (v3.getY(), v1.getY() - v2.getY());
        EXPECT_FLOAT_EQ (v3.getZ(), v1.getZ() - v2.getZ());
    }

    TEST (Vector3Test, MultiplyOperatorTest) {
        Vector3 v1 (-10, 5, 2.5);
        Vector3 v3 = v1 * 3.0;

        EXPECT_FLOAT_EQ (v3.getX(), v1.getX() * 3.0);
        EXPECT_FLOAT_EQ (v3.getY(), v1.getY() * 3.0);
        EXPECT_FLOAT_EQ (v3.getZ(), v1.getZ() * 3.0);
    }
}

int main (int argc, char* argv[]) {
    ::testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS ();
}
