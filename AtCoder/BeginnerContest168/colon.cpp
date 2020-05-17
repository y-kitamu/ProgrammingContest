#include <bits/stdc++.h>


int main() {
    int A, B, H, M;
    std::cin >> A >> B >> H >> M;

    double percent = double(M) / 60.0;
    double m_theta = M_PI / 4.0 - percent * M_PI * 2;
    double h_theta = M_PI / 4.0 - M_PI / 6.0 * (H + percent);

    double x_h = A * std::cos(h_theta);
    double y_h = A * std::sin(h_theta);
    double x_m = B * std::cos(m_theta);
    double y_m = B * std::sin(m_theta);

    std::cout << std::fixed << std::setprecision(10) << std::hypot(x_m - x_h, y_m - y_h) << std::endl;;
}
