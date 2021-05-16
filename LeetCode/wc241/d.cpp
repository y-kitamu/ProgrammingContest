#include <bits/stdc++.h>


class Solution {
  public:
    static const int MAX = 510000;
    const int MOD = 1000000007;
    long long fac[MAX], finv[MAX], inv[MAX];
    long long pow[MAX];
    // テーブルを作る前処理
    void COMinit() {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < MAX; i++) {
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }

    void POWinit() {
        pow[0] = 1;
        for (int i = 1; i < MAX; i++) {
            pow[i] = pow[i - 1] * i % MOD;
        }
    }

    // 二項係数計算
    long long COM(int n, int k) {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }

    int rearrangeSticks(int n, int k) {
        COMinit();
        POWinit();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, -1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 0;
        }
        return search(n, k, dp);
    }

    int search(int n, int k, std::vector<std::vector<int>>& dp) {
        // std::cout << n << " , " << k << std::endl;
        if (n == k) {
            return 1;
        }
        if (dp[n][k] != -1) {
            return dp[n][k];
        }
        long long int sum = 0;
        for (int i = k; i <= n; i++) {
            long long int res = (long long int)search(i - 1, k - 1, dp) * COM(n - 1, i - 1) % MOD;
            sum = (sum + res * pow[n - i] % MOD) % MOD;
        }
        dp[n][k] = sum;
        return sum;
    }
};


int main() {}
