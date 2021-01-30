#include <bits/stdc++.h>


int main() {
    int N, W;
    std::cin >> N >> W;

    std::vector<std::vector<int>> items(N, std::vector<int>(2));
    for (int i = 0; i < N; i++) {
        std::cin >> items[i][0] >> items[i][1];
    }

    std::vector<std::vector<int>> dp(N, std::vector<int>(W + 1, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < W + 1; j++) {
            if (i > 0) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j]);
            }
            if (j > 0) {
                dp[i][j] = std::max(dp[i][j], dp[i][j - 1]);
            }
            if (j >= items[i][1]) {
                dp[i][j] = std::max(dp[i][j - items[i][1]] + items[i][0], dp[i][j]);
            }
        }
    }
    std::cout << dp[N - 1][W] << std::endl;
}
