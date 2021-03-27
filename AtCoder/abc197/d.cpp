#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    int ix0, iy0, ixh, iyh;
    std::cin >> ix0 >> iy0;
    std::cin >> ixh >> iyh;

    double cx = (ix0 + ixh) / 2.0, cy = (iy0 + iyh) / 2.0;
    double dth = acos(-1) * 2 / N;
    double x0 = ix0 - cx, y0 = iy0 - cy;
    double th = std::atan2(y0, x0) + dth;
    double r = std::hypot(ix0 - ixh, iy0 - iyh) / 2;
    double x1 = cx + std::cos(th) * r;
    double y1 = cy + std::sin(th) * r;
    std::cout << std::fixed << std::setprecision(10) << x1 << " " << y1 << std::endl;
}
