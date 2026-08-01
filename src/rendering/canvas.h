#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <string_view>
#include "colors.h"

class Canvas {
public:
    explicit Canvas(size_t w, size_t h) noexcept;
    explicit Canvas(size_t w, size_t h, const Color& c) noexcept;

    size_t width() const noexcept;
    size_t height() const noexcept;

    Color at(size_t, size_t) const;

    void set(size_t, size_t, const Color&);

    void toPPM(std::string_view) const;

private:
    size_t m_width, m_height;
    std::vector<Color> m_canvas;

    size_t index(size_t x, size_t y) const noexcept;
};

#endif // !CANVAS_H
