#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <cmath>

namespace pc {

template <class T>
class Point {
  public:
    Point() {}
    Point(T x, T y) : x(x), y(y) {}

  public:
    T x, y;
};


template <class T>
class Vector : public Point<T> {
  public:
    Vector() {}
    Vector(Point<T> p1, Point<T> p2) {
        this->x = p2.x - p1.x;
        this->y = p2.y - p1.y;
    }

    double dot(Vector<T> vec) { return this->x * vec.x + this->y * vec.y; }
    double cross(Vector<T> vec) { return this->x * vec.y - this->y * vec.x; }
    double norm() { return std::hypot(this->x, this->y); }
    template <class S>
    Vector<T> operator*(S scale) {
        return Vector<T>(this->x * scale, this->y * scale);
    }
    template <class S>
    Vector<T> operator/(S scale) {
        return Vector<T>(this->x / scale, this->y / scale);
    }
    Vector<T> operator+(Point<T> vec) { return Vector<T>(this->x + vec.x, this->y + vec.y); }
    Vector<T> operator-(Point<T> vec) { return Vector<T>(this->x - vec.x, this->y - vec.y); }
};

}  // namespace pc

#endif
