#include <bits/stdc++.h>

#include "geometry.hpp"


int main() {
    pc::Point<double> p0, p1;
    std::cin >> p0.x >> p0.y >> p1.x >> p1.y;
    pc::Vector<double> vec01(p0, p1);
    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        pc::Point<double> p2;
        std::cin >> p2.x >> p2.y;
        pc::Vector<double> vec02(p0, p2);
        if (vec02.norm() < 1e-10) {
            std::cout << "ON_SEGMENT" << std::endl;
            continue;
        }
        double dot = vec01.dot(vec02) / (vec01.norm() * vec02.norm());
        if (std::abs(dot * dot - 1.0) < 1e-10) {
            if (dot < 0) {
                std::cout << "ONLINE_BACK" << std::endl;
            } else if (vec02.norm() > vec01.norm()) {
                std::cout << "ONLINE_FRONT" << std::endl;
            } else {
                std::cout << "ON_SEGMENT" << std::endl;
            }
        } else {
            double cross = vec01.cross(vec02);
            if (cross < 0) {
                std::cout << "CLOCKWISE" << std::endl;
            } else {
                std::cout << "COUNTER_CLOCKWISE" << std::endl;
            }
        }
    }
}
