#include <bits/stdc++.h>


template <class T>
class Point {
  public:
    T x, y;

    Point() {}
    Point(T x, T y) : x(x), y(y) {}

    Point<T> operator-(Point<T> pt) { return Point(x - pt.x, y - pt.y); }
    T cross(Point<T> pt) { return x * pt.y - y * pt.x; }
};

template<class T>
std::ostream& operator<<(std::ostream& os, Point<T> pt) {
    std::cout << std::fixed << std::setprecision(10) << pt.x << " " << pt.y;
    return os;
}

template<class T>
Point<double> calc_intersect(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4) {
    Point v1 = p2 - p1;
    Point v2 = p4 - p3;
    // std::cout << v1 << std::endl;
    // std::cout << v2 << std::endl;
    int c1 = p1.cross(v1);
    int c2 = p3.cross(v2);
    int c3 = v1.cross(v2);
    double x = -(double)(v2.x * c1 - v1.x * c2) / c3;
    double y = -(double)(v2.y * c1 - v1.y * c2) / c3;
    return Point(x, y);
}


int main() {
    int q;
    std::cin >> q;

    std::vector<Point<double>> pts;
    for (int i = 0; i < q; i++) {
        Point<int> p1, p2, p3, p4;
        std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
        Point<double> pt = calc_intersect(p1, p2, p3, p4);
        pts.emplace_back(pt);
    }

    for (auto pt : pts){
        std::cout << std::fixed << std::setprecision(10) << pt.x << " " << pt.y << std::endl;
    }
}
