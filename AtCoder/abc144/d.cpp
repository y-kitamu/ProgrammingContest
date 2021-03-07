#include <bits/stdc++.h>


int main() {
    int a, b, x;
    std::cin >> a >> b >> x;

    double half = a * a * b / 2.0;
    if (x > half) {
        double alpha = x * 2.0 / (a * a) - b;
        double theta = std::atan((b - alpha) / a) * 180 / M_PI;
        std::cout << std::fixed << std::setprecision(10) << theta << std::endl;
    } else {
        double alpha = x * 2.0 / (a * b);
        double theta = std::atan(b / alpha) * 180 / M_PI;
        std::cout << std::fixed << std::setprecision(10) << theta << std::endl;
    }
}
