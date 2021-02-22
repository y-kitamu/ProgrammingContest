#include <bits/stdc++.h>

template <class T>
T mod_comb(T k, T n, std::vector<std::vector<T>>& dp, T MOD) {
    for (int i = 1; i < k; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
        }
    }
    return dp[k - 1][n - 1];
}


int main() {
    long long int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<long long int>> dp(k, std::vector<long long int>(n, 0));
    for (int i = 0; i < k; i++) {
        dp[i][0] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;
    }
    long long int MOD = 1e9 + 7;
    std::cout << mod_comb(k, n, dp, MOD) << std::endl;
}
