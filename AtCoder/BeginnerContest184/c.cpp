#include <bits/stdc++.h>


int main() {
    int r1, c1, r2, c2;
    std::cin >> r1 >> c1 >> r2 >> c2;

    if (r1 == r2 && c1 == c2) {
        std::cout << 0 << std::endl;
        return 0;
    }
    if (r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2 || std::abs(r1 - r2) + std::abs(c1 - c2) <= 3) {
        std::cout << 1 << std::endl;
        return 0;
    }
    if (std::abs(r1 - r2) + std::abs(c1 - c2) <= 6) {
        std::cout << 2 << std::endl;
        return 0;
    }
    int res = r2 - r1;
    int dist = std::min(std::abs(c1 + res - c2), std::abs(c1 - res - c2));
    if (dist <= 3) {
        std::cout << 2 << std::endl;
        return 0;
    }
    if ((r1 + c1) % 2 == (r2 + c2) % 2) {
        std::cout << 2 << std::endl;
        return 0;
    }
    std::cout << 3 << std::endl;
}
