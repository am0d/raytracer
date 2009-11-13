#include <gtest/gtest.h>

#include "../math/vector3.hpp"
#include "../math/ray3d.hpp"

namespace {
    TEST (Ray3dTest, Nothing) {

    }
}

int main (int argc, char* argv[]) {
    ::testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS ();
}
