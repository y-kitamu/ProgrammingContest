#include <bits/stdc++.h>


template <class T>
T mod_comb(T n, T r, T mod, std::vector<std::vector<T>>& dp) {
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
        }
    }
    return dp[n - 1][r - 1];
}


template <class T>
T mod_pow(T n, T r, T mod) {
    T res = 1;
    T pow = n;
    while (r > 0) {
        if (r & 1) {
            res = (res * pow) % mod;
        }
        pow = pow * pow % mod;
        r >>= 1;
    }
    return res;
}


int main() {
    long long int MOD = 1e9 + 7;
    long long int n, k;
    std::cin >> n >> k;
    if (n < k) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<std::vector<long long int>> mdp(k, std::vector<long long int>(k, 0));
    for (int i = 0; i < k; i++) {
        mdp[i][0] = i + 1;
        mdp[i][i] = 1;
    }
    mod_comb(k, k, MOD, mdp);

    std::vector<long long int> dp(k, 0);
    dp[0] = 1;
    for (long long int i = 1; i < k; i++) {
        dp[i] = mod_pow(i + 1, n, MOD);
        for (long long int j = 0; j < i; j++) {
            dp[i] = (dp[i] - mdp[i][j] * dp[j]) % MOD;
        }
        // std::cout << dp[i] << " ";
    }
    // std::cout << std::endl;
    std::cout << (dp[k - 1] + MOD) % MOD << std::endl;
}
