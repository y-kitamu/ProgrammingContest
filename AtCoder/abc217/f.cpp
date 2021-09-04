/*
 * f.cpp
 *
 * Create Date : 2021-09-04 21:22:01
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

const long long int MAX = 510000;
const long long int MOD = 998244353;

long long fac[MAX], finv[MAX], inv[MAX];

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

long long COM(long long int n, long long int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main() {
    COMinit();
    long long int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<long long int>> mat(2 * N, std::vector<long long int>(2 * N, 0));

    for (int i = 0; i < M; i++) {
        long long int a, b;
        std::cin >> a >> b;
        a--, b--;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }

    std::vector<long long int> dp(N + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            bool flag = true;
            for (int k = 0; k <= i - j; k++) {
                flag &= mat[2 * j + k][2 * i - k + 1] == 1;
            }
            if (flag) {
                dp[i + 1] += COM(i + 1, j) * dp[j] % MOD;
            }
        }
        dp[i + 1] %= MOD;
    }
    std::cout << (dp[N] + MOD) % MOD << std::endl;
}
