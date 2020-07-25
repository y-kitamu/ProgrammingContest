#include <bits/stdc++.h>


int main() {
    long long int W, H, x, y;
    std::cin >> W >> H >> x >> y;

    std::cout << double(W * H) / 2.0;

    if (x * 2 == W && y * 2 == H) {
        std::cout << " 1" << std::endl;
    } else {
        std::cout << " 0" << std::endl;
    }
}
