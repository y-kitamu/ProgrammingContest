#include <bits/stdc++.h>

int main() {
    long long int S;
    std::cin >> S;

    long long int x1 = 1000000000, y1 = 1, x2, y2;
    y2 = (S + x1 - 1) / x1;
    x2 = x1 * y2 - S;
    std::cout << 0 << " " << 0 << " " << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;
    // std::cout << std::abs((long long int)x1 * (long long int)y2 - (long long int)x2 * (long long int)y1) << std::endl;
}
