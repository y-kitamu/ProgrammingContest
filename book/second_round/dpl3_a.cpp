#include <bits/stdc++.h>

int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::vector<int>> max_square(H, std::vector<int>(W, 0));
    int maximum_length = 0;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            int val;
            std::cin >> val;
            if (val == 0) {
                if (x == 0 || y == 0) {
                    max_square[y][x] = 1;
                } else {
                    max_square[y][x] = std::min(
                        std::min(max_square[y - 1][x - 1], max_square[y - 1][x]),
                        max_square[y][x- 1]
                        ) + 1;
                }

            } else {
                max_square[y][x] = 0;
            }
            if (max_square[y][x] > maximum_length) {
                maximum_length = max_square[y][x];
            }
        }
    }

    std::cout << maximum_length * maximum_length << std::endl;
}
