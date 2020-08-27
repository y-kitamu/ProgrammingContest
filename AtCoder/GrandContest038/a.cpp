#include <bits/stdc++.h>


int main() {
    int H, W, A, B;
    std::cin >> H >> W >> A >> B;

    int h = 0;
    for (;h < H - B; h++) {
        int w = 0;
        for (;w < A; w++) {
            std::cout << 1;
        }
        for (;w < W; w++) {
            std::cout << 0;
        }
        std::cout << std::endl;
    }
    for (;h < H; h++) {
        int w = 0;
        for (;w < A; w++) {
            std::cout << 0;
        }
        for (;w < W; w++) {
            std::cout << 1;
        }
        std::cout << std::endl;
    }
}
