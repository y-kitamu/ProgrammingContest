#include <bits/stdc++.h>


int main() {
    long long int MOD = 1e9 + 7;
    int N, M;
    std::cin >> N >> M;
    std::vector<int> S(N), T(M);

    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
    }

    for (int i = 0; i < M; i++) {
        std::cin >> T[i];
    }

    std::vector<std::vector<long long int>> dp(N, std::vector<long long int>(M, 0));
    std::vector<std::vector<long long int>> sums(N + 1, std::vector<long long int>(M + 1, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (S[i] == T[j]) {
                dp[i][j] = (sums[i][j] + 1) % MOD;
            }
            sums[i + 1][j + 1] = (sums[i + 1][j] + sums[i][j + 1] - sums[i][j] + dp[i][j]) % MOD;
        }
    }
    std::cout << (sums[N][M] + 1 + MOD) % MOD << std::endl;
}
