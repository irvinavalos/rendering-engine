#include <doctest/doctest.h>
#include "rendering/colors.h"

TEST_SUITE("Colors") {
    TEST_CASE("Adding colors") {
        Color c1{0.9, 0.6, 0.75};
        Color c2{0.7, 0.1, 0.25};

        CHECK(c1 + c2 == Color(1.6, 0.7, 1.0));
    }

    TEST_CASE("Subtracting colors") {
        Color c1{0.9, 0.6, 0.75};
        Color c2{0.7, 0.1, 0.25};

        CHECK(c1 - c2 == Color(0.2, 0.5, 0.5));
    }

    TEST_CASE("Multiplying a color by a scalar") {
        Color c{0.2, 0.3, 0.4};

        CHECK(c * 2 == Color(0.4, 0.6, 0.8));
    }

    TEST_CASE("Multiplying colors") {
        Color c1{1.0, 0.2, 0.4};
        Color c2{0.9, 1, 0.1};

        CHECK(c1 * c2 == Color(0.9, 0.2, 0.04));
    }
}
