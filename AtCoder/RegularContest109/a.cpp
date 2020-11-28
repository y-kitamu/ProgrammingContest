#include <bits/stdc++.h>


int main() {
    int a, b, x, y;
    std::cin >> a >> b >> x >> y;

    if (a > b) {
        std::cout << std::min(((a - b) * 2 - 1) * x, (a - b - 1) * y + x) << std::endl;
    } else if (a == b) {
        std::cout << x << std::endl;
    } else {
        std::cout << std::min(((b - a) * 2 + 1) * x, (b - a) * y + x) << std::endl;
    }
}
