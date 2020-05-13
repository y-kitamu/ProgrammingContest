#include <bits/stdc++.h>


class Vector {
  public:
    Vector(double x, double y): x(x), y(y) {};

    Vector operator+(const Vector &vec) { return Vector(x + vec.x, y + vec.y); }
    Vector operator-(const Vector &vec) { return Vector(x - vec.x, y - vec.y); }
    Vector operator*(double d) { return Vector(x * d, y * d); }
    double dot(const Vector &vec) { return x * vec.x + y * vec.y; };
    double square_norm() { return x * x + y * y; }

    double x, y;
};


int main() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    Vector line(x2 - x1, y2 - y1), vec1(x1, y1);
    double norm = line.square_norm();
    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        int x0, y0;
        std::cin >> x0 >> y0;
        Vector vec0(x0, y0);

        // double n = (vec0.dot(line) - a) / norm;
        // Vector proj = vec1 + line * n;
        // Vector pos = proj * 2  - vec0;
        // std::cout << std::fixed << std::setprecision(10) << pos.x << " " << pos.y << std::endl;
    }
}
