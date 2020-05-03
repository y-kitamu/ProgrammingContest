#include <iostream>
#include <iomanip>
#include <cmath>


class Vector {
  public:
    Vector() {}
    Vector(double x, double y): x(x), y(y) {}
    Vector operator+(Vector vec) { return Vector(x + vec.x, y + vec.y); }
    Vector operator-(Vector vec) { return Vector(x - vec.x, y - vec.y); }
    Vector operator*(double val) { return Vector(x * val, y * val); }
    Vector operator/(double val) { return Vector(x / val, y / val); }


    double dot(Vector vec) { return x * vec.x + y * vec.y; }
    double norm() {
        return std::sqrt(x * x + y * y);
    }
    Vector normalize() {
        return *this / this->norm();
    }

    double x, y;
};


class Line {
  public:
    Line() {}
    Line(Vector p0, Vector p1): p0(p0), p1(p1) {
        direction = p1 - p0;
    }

    Vector p0, p1;
    Vector direction;
};

int main() {
    Vector p1, p2;
    std::cin >> p1.x >> p1.y >> p2.x >> p2.y;
    Line l(p1, p2);
    Vector dir = l.direction.normalize();

    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        Vector p;
        std::cin >> p.x >> p.y;

        Line ql(p1, p);
        auto x = p1 + dir * ql.direction.dot(dir);
        std::cout << std::fixed << std::setprecision(10) << x.x << " " << x.y << std::endl;
    }
}
