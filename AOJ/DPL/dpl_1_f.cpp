#include <bits/stdc++.h>


int main() {
    int N, W;
    std::cin >> N >> W;

    std::vector<int> vs(N), ws(N);
    for (int i = 0; i < N; i++) {
        std::cin >> vs[i] >> ws[i];
    }

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(N * 100 + 1, (int)10000000000));
    for (int i = 0; i <= N; i++) {
        dp[i][0] = 0;
    }
    for (int j = 1; j <= N * 100; j++) {
        for (int i = 1; i <= N; i++) {
            int diff = std::max(0, j - vs[i - 1]);
            dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][diff] + ws[i - 1]);
        }
    }

    int max = 0;
    for (int j = 1; j <= N * 100; j++) {
        // std::cout << dp[N][j] << " ";
        if (dp[N][j] <= W) {
            max = j;
        }
    }
    // std::cout << std::endl;
    std::cout << max << std::endl;
}
