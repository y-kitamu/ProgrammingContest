#include <iostream>


class Vector {
  public:
    Vector(){}
    Vector(int x, int y): x(x), y(y) {}
    int dot(Vector v) {
        return v.x * x + v.y * y;
    }

    int norm() {
        return x * x + y * y;
    }

    Vector operator+(Vector v) { return Vector(v.x + x, v.y + y); }
    Vector operator-(Vector v) { return Vector(x - v.x, y - v.y); }

    int x, y;
};


class Line {
  public:
    Line() {}
    Line(Vector p1, Vector p2): p1(p1), p2(p2) {
        direction = p1 - p2;
    }

    Vector p1, p2;
    Vector direction;
};


int main() {
    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        Vector p0, p1, p2, p3;
        std::cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        Line l1(p0, p1), l2(p2, p3);
        int dot = l1.direction.dot(l2.direction);

        if (dot == 0) {
            std::cout << 1 << std::endl;
        } else if (dot * dot == l1.direction.norm() * l2.direction.norm()) {
            std::cout << 2 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }
}
