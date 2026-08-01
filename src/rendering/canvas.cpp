#include <fstream>
#include <filesystem>
#include "canvas.h"

static constexpr double MIN_RGB{0.0};
static constexpr double MAX_RGB{255.0};

Canvas::Canvas(size_t w, size_t h)
    noexcept : m_width{w}, m_height{h}, m_canvas(w * h) {}

Canvas::Canvas(size_t w, size_t h, const Color& c)
    noexcept : m_width{w}, m_height{h}, m_canvas(w * h, c) {}


size_t Canvas::width() const noexcept {
    return m_width;
}

size_t Canvas::height() const noexcept {
    return m_height;
}

Color Canvas::at(size_t x, size_t y) const {
    return m_canvas.at(index(x, y));
}

void Canvas::set(size_t x, size_t y, const Color& c) {
    m_canvas.at(index(x, y)) = c;
}

static size_t numberOfDigits(size_t x) noexcept {
    if (x < 10) return 1;
    else if (x < 100) return 2;
    return 3;
}

static void writeValue(std::ofstream& file, size_t value, size_t& col) noexcept {
    auto length = numberOfDigits(value);

    if (col == 0) {
        file << value;
        col = length;
    } else if (col + 1 + length > 70) {
        file << "\n" << value;
        col = length;
    } else {
        file << " " << value;
        col += 1 + length;
    }
}

static size_t rgb32(double x) noexcept {
    if (x < MIN_RGB) return 0;
    if (x > MAX_RGB) return 255;
    return static_cast<size_t>(x);
}

void Canvas::toPPM(std::string_view filename) const {
    std::ofstream file{std::filesystem::path(filename)};

    if (!file) return;

    file << "P3\n";
    file << m_width << " " << m_height << "\n";
    file << "255\n";

    for (size_t row{}; row < m_height; ++row) {
        size_t columnCount{0};

        for (size_t col{}; col < m_width; ++col) {
            Color pixel{MAX_RGB * at(col, row)};

            writeValue(file, rgb32(pixel.red()), columnCount);
            writeValue(file, rgb32(pixel.green()), columnCount);
            writeValue(file, rgb32(pixel.blue()), columnCount);
        }

        file << "\n";
    }

    file << "\n";
    file.close();
}

size_t Canvas::index(size_t x, size_t y) const noexcept {
    return y * m_width + x;
}
