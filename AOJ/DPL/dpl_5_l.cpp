#include <bits/stdc++.h>


using ll = long long int;

int main() {
    ll mod = 1e9 + 7;
    ll n, k;
    std::cin >> n >> k;

    std::vector<std::vector<ll>> dp(k, std::vector<ll>(n, 0));
    std::vector<std::vector<ll>> sum(k, std::vector<ll>(n, 0));

    for (int i = 0; i < std::min(n, k); i++) {
        dp[i][i] = 1;
    }

    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;
        sum[0][i] = 1;
    }

    for (int i = 1; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i) {
                dp[i][j] = sum[i][j - i - 1];
            }
            sum[i][j] = (sum[i - 1][j] + dp[i][j]) % mod;
        }
    }

    std::cout << dp[k - 1][n - 1] << std::endl;
}
