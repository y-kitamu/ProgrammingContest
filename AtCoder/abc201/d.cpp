#include <bits/stdc++.h>


int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> rows(H);

    for (int y = 0; y < H; y++) {
        std::cin >> rows[y];
    }

    std::vector<std::vector<int>> map(H, std::vector<int>(W));
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (rows[y][x] == '+') {
                map[y][x] = 1;
            } else {
                map[y][x] = -1;
            }
            if ((x + y) % 2 == 0) {
                map[y][x] *= -1;
            }
        }
    }

    std::vector<std::vector<int>> dp(H, std::vector<int>(W, 0));
    for (int i = 1; i < W; i++) {
        dp[0][i] = dp[0][i - 1] + map[0][i];
    }

    for (int i = 1; i < H; i++) {
        dp[i][0] = dp[i - 1][0] + map[i][0];
    }

    for (int y = 1; y < H; y++) {
        for (int x = 1; x < W; x++) {
            if ((x + y) % 2 == 0) {
                // maximize
                dp[y][x] = dp[y - 1][x - 1] + std::max(map[y][x - 1], map[y - 1][x]) + map[y][x];
            } else {
                // minimize
                dp[y][x] = dp[y - 1][x - 1] + std::min(map[y][x - 1], map[y - 1][x]) + map[y][x];
            }
        }
    }

    if (dp[H - 1][W - 1] > 0) {
        std::cout << "Takahashi" << std::endl;
    } else if (dp[H - 1][W - 1] < 0) {
        std::cout << "Aoki" << std::endl;
    } else {
        std::cout << "Draw" << std::endl;
    }
}
