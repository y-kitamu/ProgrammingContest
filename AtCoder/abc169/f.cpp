#include <bits/stdc++.h>


int main() {
    int N, S;
    std::cin >> N >> S;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    long long int MOD = 998244353;
    std::vector<std::vector<long long int>> dp(N + 1, std::vector<long long int>(S + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= S; j++) {
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * 2) % MOD;
            if (j + A[i] <= S) {
                dp[i + 1][j + A[i]] = (dp[i + 1][j + A[i]] + dp[i][j]) % MOD;
            }
        }
    }
    std::cout << dp[N][S] << std::endl;
}
