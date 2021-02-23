#include <bits/stdc++.h>


template <class T>
T mod_pow(T n, T r, T mod) {
    if (r > n) {
        return 0;
    }
    if (r == 0) {
        return 1;
    }
    std::vector<std::vector<T>> dp(n, std::vector<T>(r, 0));
    for (int i = 0; i < r; i++) {
        dp[i][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        dp[i][0] = i + 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < r; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
        }
    }
    return dp[n - 1][r - 1];
}


int main() {
    long long int mod = 1e9 + 7;
    long long int n, k;
    std::cin >> n >> k;

    std::cout << mod_pow(n - 1, k - 1, mod) << std::endl;
}
