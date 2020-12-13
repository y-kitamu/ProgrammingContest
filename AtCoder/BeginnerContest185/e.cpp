#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for (int j = 0; j < M; j++) {
        std::cin >> B[j];
    }

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(M + 1, 0));
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int min = N + M;
            if (i > 0) {
                min = std::min(min, dp[i - 1][j] + 1);
            }
            if (j > 0) {
                min = std::min(min, dp[i][j - 1] + 1);
            }
            if (i > 0 && j > 0) {
                int offset = 0;
                if (A[i - 1] != B[j - 1]) {
                    offset = 1;
                }
                min = std::min(min, dp[i - 1][j - 1] + offset);
            }
            dp[i][j] = min;
        }
    }
    std::cout << dp[N][M] << std::endl;
}
