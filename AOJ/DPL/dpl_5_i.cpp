#include <bits/stdc++.h>

using ll = long long int;

int main() {
    ll mod = 1e9 + 7;
    ll n, k;
    std::cin >> n >> k;

    if (n < k) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<std::vector<ll>> dp(k, std::vector<ll>(n, 0));
    for (int i = 0; i < std::min(n, k); i++) {
        dp[i][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < k; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + (i + 1) * dp[i][j - 1]) % mod;
        }
    }

    std::cout << dp[k - 1][n - 1] << std::endl;
}
