#include <doctest/doctest.h>
#include <fstream>
#include <string>
#include "rendering/canvas.h"

const std::string testPath = "images/tests/";

TEST_SUITE("Canvas") {
    TEST_CASE("Creating a canvas") {
        Canvas c{10, 20};

        CHECK(c.width() == 10);
        CHECK(c.height() == 20);

        // every pixel is Color(0, 0, 0)
        for (size_t y{}; y < c.height(); ++y) {
            for (size_t x{}; x < c.width(); ++x) {
                CHECK(c.at(x, y) == Color());
            }
        }
    }

    TEST_CASE("Writing pixels to a canvas") {
        Canvas c{10, 20};
        Color red{1, 0, 0};

        c.set(2, 3, red);

        CHECK(c.at(2, 3) == red);
    }

    TEST_CASE("Constructing the PPM header") {
        Canvas c{10, 20};

        std::string fileName = testPath + "test_ppm_header.ppm";
        c.toPPM(fileName);

        std::ifstream file(fileName);
        REQUIRE(file.is_open());

        std::string line;

        std::getline(file, line);
        CHECK_EQ(line, "P3");

        std::getline(file, line);
        CHECK_EQ(line, "10 20");

        std::getline(file, line);
        CHECK_EQ(line, "255");

        file.close();
    }

    TEST_CASE("Constructing the PPM pixel data") {
        Canvas c{5, 3};

        Color c1{1.5, 0, 0};
        Color c2{0, 0.5, 0};
        Color c3{-0.5, 0, 1};

        c.set(0, 0, c1);
        c.set(2, 1, c2);
        c.set(4, 2, c3);

        std::string fileName = testPath + "test_ppm_data.ppm";

        c.toPPM(fileName);

        std::ifstream file(fileName);
        REQUIRE(file.is_open());

        std::string line;

        std::getline(file, line);
        std::getline(file, line);
        std::getline(file, line);

        std::getline(file, line);
        CHECK_EQ(line, "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0");

        std::getline(file, line);
        CHECK_EQ(line, "0 0 0 0 0 0 0 127 0 0 0 0 0 0 0");

        std::getline(file, line);
        CHECK_EQ(line, "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255");

        file.close();
    }

    TEST_CASE("Splitting long lines in PPM files") {
        Canvas c{10, 2, Color(1, 0.8, 0.6)};

        std::string fileName = testPath + "test_ppm_long_lines.ppm";
        c.toPPM(fileName);

        std::ifstream file(fileName);
        REQUIRE(file.is_open());

        std::string line;

        std::getline(file, line);
        std::getline(file, line);
        std::getline(file, line);

        std::getline(file, line);
        CHECK_EQ(
          line,
          "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204");

        std::getline(file, line);
        CHECK_EQ(line, "153 255 204 153 255 204 153 255 204 153 255 204 153");

        std::getline(file, line);
        CHECK_EQ(
          line,
          "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204");

        std::getline(file, line);
        CHECK_EQ(line, "153 255 204 153 255 204 153 255 204 153 255 204 153");

        file.close();
    }

    TEST_CASE("PPM files end with a newline character") {
        Canvas c{5, 3};

        std::string fileName = testPath + "test_ppm_long_lines.ppm";
        c.toPPM(fileName);

        std::ifstream file(fileName);
        REQUIRE(file.is_open());

        std::string content((std::istreambuf_iterator<char>(file)),
                          std::istreambuf_iterator<char>());

        CHECK(content.back() == '\n');

        file.close();
    }
}
