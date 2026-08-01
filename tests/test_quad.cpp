#include <doctest/doctest.h>
#include <cmath>
#include "math/quad.h"
#include "math/point.h"
#include "math/vec3.h"
#include "math/operations.h"

TEST_SUITE("Quad") {
    TEST_CASE("A Quad with w=1.0 is a point") {
        auto q = Quad(4.3, -4.2, 3.1, 1.0);

        CHECK_EQ(q.x(), 4.3);
        CHECK_EQ(q.y(), -4.2);
        CHECK_EQ(q.z(), 3.1);
        CHECK_EQ(q.w(), 1.0);

        CHECK_EQ(q.isPoint(), true);
        CHECK_EQ(q.isVector(), false);
    }

    TEST_CASE("A Quad with w=0.0 is a vector") {
        auto q = Quad(4.3, -4.2, 3.1, 0.0);

        CHECK_EQ(q.x(), 4.3);
        CHECK_EQ(q.y(), -4.2);
        CHECK_EQ(q.z(), 3.1);
        CHECK_EQ(q.w(), 0.0);

        CHECK_EQ(q.isPoint(), false);
        CHECK_EQ(q.isVector(), true);
    }

    TEST_CASE("Point() creates a Quad with w=1.0") {
        auto p = Point(4, -4, 3);

        CHECK(p == Quad(4, -4, 3, 1));
    }

    TEST_CASE("Vec3() creates a Quad with w=1.0") {
        auto v = Vec3(4, -4, 3);

        CHECK(v == Quad(4, -4, 3, 0));
    }

    TEST_CASE("Adding two Quads") {
        Quad q1{3, -2, 5, 1};
        Quad q2{-2, 3, 1, 0};

        CHECK(q1 + q2 == Quad(1, 1, 6, 1));
    }

    TEST_CASE("Adding a point with a vector") {
        Point p{1, 2, 3};
        Vec3 v{1, 2, 3};

        CHECK(p + v == Point(2, 4, 6));
        CHECK(v + p == Point(2, 4, 6));
    }

    TEST_CASE("Subtracting two points") {
        Point p1{3, 2, 1};
        Point p2{5, 6, 7};

        CHECK(p1 - p2 == Vec3(-2, -4, -6));
    }

    TEST_CASE("Subtracting a vector from a point") {
        Point p{3, 2, 1};
        Vec3 v{5, 6, 7};

        CHECK(p - v == Point(-2, -4, -6));
    }

    TEST_CASE("Subtracting two vectors") {
        Vec3 v1{3, 2, 1};
        Vec3 v2{5, 6, 7};

        CHECK(v1 - v2 == Vec3(-2, -4, -6));
    }

    TEST_CASE("Subtracting a vector from the zero vector") {
        Vec3 zero{0, 0, 0};
        Vec3 v{3, 2, 1};

        CHECK(zero - v == Vec3(-3, -2, -1));
    }

    TEST_CASE("Negating a Quad") {
        Quad q{1, -2, 3, -4};

        CHECK(-q == Quad(-1, 2, -3, 4));
    }

    TEST_CASE("Multiplying a Quad by a scalar") {
        Quad q{1, -2, 3, -4};

        CHECK(q * 3.5 == Quad(3.5, -7, 10.5, -14));
    }

    TEST_CASE("Multiplying a Quad by a fraction") {
        Quad q{1, -2, 3, -4};

        CHECK(0.5 * q == Quad(0.5, -1, 1.5, -2));
    }

    TEST_CASE("Dividing a Quad by a scalar") {
        Quad q{1, -2, 3, -4};

        CHECK(q / 2 == Quad(0.5, -1, 1.5, -2));
    }

    TEST_CASE("Computing the magnitude of Vec3(1, 0, 0)") {
        Vec3 v{1, 0, 0};

        CHECK(magnitude(v) == 1);
    }

    TEST_CASE("Computing the magnitude of Vec3(0, 1, 0)") {
        Vec3 v{0, 1, 0};

        CHECK(magnitude(v) == 1);
    }

    TEST_CASE("Computing the magnitude of Vec3(0, 0, 1)") {
        Vec3 v{0, 0, 1};

        CHECK(magnitude(v) == 1);
    }

    TEST_CASE("Computing the magnitude of Vec3(1, 2, 3)") {
        Vec3 v{1, 2, 3};

        CHECK(magnitude(v) == std::sqrt(14));
    }

    TEST_CASE("Computing the magnitude of Vec3(-1, -2, -3)") {
        Vec3 v{-1, -2, -3};

        CHECK(magnitude(v) == std::sqrt(14));
    }

    TEST_CASE("Computing the magnitude of Vec3(-1, -2, -3)") {
        Vec3 v{-1, -2, -3};

        CHECK(magnitude(v) == std::sqrt(14));
    }

    TEST_CASE("Normalizing Vec3(4, 0, 0) gives (1, 0, 0)") {
        Vec3 v{4, 0, 0};

        CHECK(normalize(v) == Vec3(1, 0, 0));
    }

    TEST_CASE("Normalizing Vec3(1, 2, 3)") {
        Vec3 v{1, 2, 3};
        auto a = std::sqrt(14);

        CHECK(normalize(v) == Vec3(1 / a, 2 / a, 3 / a));
    }

    TEST_CASE("Magnitude of a normalized vector") {
        Vec3 v{1, 2, 3};

        CHECK(magnitude(normalize(v)) == 1);
    }

    TEST_CASE("Dot product of two Quads") {
        Vec3 a{1, 2, 3};
        Vec3 b{2, 3, 4};

        CHECK(dot(a, b) == 20);
    }

    TEST_CASE("Cross product of two vectors") {
        Vec3 a{1, 2, 3};
        Vec3 b{2, 3, 4};

        CHECK(cross(a, b) == Vec3(-1, 2, -1));
        CHECK(cross(b, a) == Vec3(1, -2, 1));
    }
}
