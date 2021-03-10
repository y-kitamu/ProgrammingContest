#include <bits/stdc++.h>


int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::vector<int>> a(H, std::vector<int>(W)), b(H, std::vector<int>(W));
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            std::cin >> a[y][x];
        }
    }
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            std::cin >> b[y][x];
        }
    }
}
