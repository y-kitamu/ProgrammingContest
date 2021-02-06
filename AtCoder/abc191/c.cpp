#include <bits/stdc++.h>


int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::vector<char>> mas(H, std::vector<char>(W));
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            std::cin >> mas[y][x];
        }
    }

    int cnt = 0;
    for (int y = 0; y < H - 1; y++) {
        for (int x = 0; x < W - 1; x++) {
            if ((mas[y][x] == mas[y][x + 1] && mas[y + 1][x] == mas[y + 1][x + 1]) ||
                (mas[y][x] == mas[y + 1][x] && mas[y][x + 1] == mas[y + 1][x + 1])) {
            } else {
                cnt++;
            }
        }
    }
    std::cout << cnt << std::endl;
}
