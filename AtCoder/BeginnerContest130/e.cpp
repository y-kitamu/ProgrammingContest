#include <bits/stdc++.h>


int main() {
    long long int MOD = 1e9 + 7;
    int N, M;
    std::cin >> N >> M;
    std::vector<long long int> S(N), T(M);
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
    }
    for (int j = 0; j < M; j++) {
        std::cin >> T[j];
    }

    std::vector<std::vector<long long int>> dp(N + 1, std::vector<long long int>(M + 1, 1));

    for (int i = 1; i <= N ;i++) {
        for (int j = 1; j <=M; j++) {
            dp[i][j] = dp[i][j - 1];
            if (S[i - 1] == T[j - 1]) {
                dp[i][j] += dp[i - 1][j - 1];
            }
            dp[i][j] = (dp[i][j] % MOD);
        }
    }
    if (dp[N][M] < 0) {
        dp[N][M] += MOD;
    }
    std::cout << dp[N][M] << std::endl;
}
