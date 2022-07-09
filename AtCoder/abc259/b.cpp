/**
 * @file b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-07-09 21:03:17
 */
#include <bits/stdc++.h>


int main() {
    double a, b, d;
    std::cin >> a >> b >> d;
    double len = std::sqrt(a * a + b * b);

    if (std::abs(a) < 1e-6 && std::abs(b) < 1e-6) {
        std::cout << 0.0 << " " << 0.0 << std::endl;
        return 0;
    }

    double theta = std::acos(a / len);
    if (b < 0) {
        theta *= -1.0;
    }

    double dtheta = (2.0 * M_PI) * d / 360;
    double th = theta + dtheta;

    std::cout << std::fixed << std::setprecision(10) << len * std::cos(th) << " " << len * std::sin(th)
              << std::endl;
}
