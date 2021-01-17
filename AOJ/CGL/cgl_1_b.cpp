#include <bits/stdc++.h>

class Vector {
  public:
    Vector() {}
    Vector(double x, double y) : x(x), y(y) {}
    Vector(Vector p1, Vector p2) {
        x = p2.x - p1.x;
        y = p2.y - p1.y;
    }

    double dot(Vector vec) { return (double)x * vec.x + y * vec.y; }
    double norm() { return std::sqrt((double)x * x + y * y); }
    Vector operator*(double scale) { return Vector(x * scale, y * scale); }
    Vector operator/(double scale) { return Vector(x / scale, y / scale); }
    Vector operator+(Vector vec) { return Vector(x + vec.x, y + vec.y); }
    Vector operator-(Vector vec) { return Vector(x - vec.x, y - vec.y); }
    double x, y;
};

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    return os << "(x, y) = (" << vec.x << ",  " << vec.y << ")";
}

int main() {
    Vector p1, p2;
    std::cin >> p1.x >> p1.y >> p2.x >> p2.y;

    Vector vec12(p1, p2);

    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        Vector pt;
        std::cin >> pt.x >> pt.y;
        Vector vec(p1, pt);
        double scale = vec12.dot(vec) / vec12.norm();
        Vector dst = vec12 / vec12.norm() * scale * 2 - vec + p1;
        std::cout << std::fixed << std::setprecision(10) << dst.x << " " << dst.y << std::endl;
    }
}
