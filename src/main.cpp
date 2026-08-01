#include "math/vec3.h"
#include "math/point.h"
#include "math/operations.h"
#include "rendering/canvas.h"

struct Projectile {
    Projectile(Point p, Vec3 v) : position(p), velocity(v) {}
    Point position;
    Vec3 velocity;
};

struct Environment {
    Vec3 gravity;
    Vec3 wind;
};

Projectile tick(Environment env, Projectile proj) {
    Point position = proj.position + proj.velocity;
    Vec3 velocity = proj.velocity + env.gravity + env.wind ;
    return Projectile(position, velocity);
}

static const Color color{1, 0, 0};

void drawPoint(Canvas& canvas, Point p) {
    auto x = static_cast<size_t>(p.x());
    auto y = static_cast<size_t>(canvas.height() - p.y());

    if (x > 0 && x - 1 < canvas.width())
        canvas.set(x - 1, y, color);
    if (x + 1 < canvas.width())
        canvas.set(x + 1, y, color);
    if (y > 0 && y - 1 < canvas.height())
        canvas.set(x, y - 1, color);
    if (y + 1 < canvas.height())
        canvas.set(x, y + 1, color);
    canvas.set(x, y, color);
}

int main() {
    Canvas c{900, 550};

    Point start{0, 1, 0};
    Vec3 velocity = normalize(Vec3(1, 1.8, 0)) * 11.25;
    Projectile p{start, velocity};

    Vec3 gravity{0, -0.1, 0};
    Vec3 wind{-0.01, 0, 0};
    Environment e{gravity, wind};

    while (p.position.y() >= 0) {
        drawPoint(c, p.position);
        p = tick(e, p);
    }

    c.toPPM("images/projectile_motion.ppm");

    return 0;
}
