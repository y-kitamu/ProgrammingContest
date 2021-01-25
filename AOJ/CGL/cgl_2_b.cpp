#include <bits/stdc++.h>

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;


struct Point {
    int x, y;

    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    Point operator-(Point pt) { return Point(x - pt.x, y - pt.y); }
    int sqnorm() { return x * x + y * y; }
};


int cross(Point p1, Point p2) { return p1.x * p2.y - p1.y * p2.x; }
int dot(Point p1, Point p2) { return p1.x * p2.x + p1.y * p2.y; }

int ccw(Point p0, Point p1, Point p2) {
    Point p01 = p1 - p0;
    Point p02 = p2 - p0;

    if (cross(p01, p02) > 0) {
        return COUNTER_CLOCKWISE;
    }
    if (cross(p01, p02) < 0) {
        return CLOCKWISE;
    }
    if (dot(p01, p02) < 0) {
        return ONLINE_BACK;
    }
    if (p01.sqnorm() < p02.sqnorm()) {
        return ONLINE_FRONT;
    }
    return ON_SEGMENT;
}

bool intersect(Point p1, Point p2, Point p3, Point p4) {
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}


int main() {
    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        Point p0, p1, p2, p3;
        std::cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        if (intersect(p0, p1, p2, p3)) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }
}
