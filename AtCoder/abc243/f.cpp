/*
 * f.cpp
 *
 * Create Date : 2022-03-12 22:07:08
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

using ll = long long;

const int MAX = 100;
const ll MOD = 998244353;

long long fac[MAX], finv[MAX], inv[MAX];

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

// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll mod_pow(int n, int r, int mod) {
    ll ans = 1;
    ll pow = n;
    while (r > 0) {
        if (r & 1) {
            ans = (ans * pow) % mod;
        }
        pow = (pow * pow) % mod;
        r >>= 1;
    }
    return ans;
}

ll ext_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll res = ext_gcd(b, a % b, y, x);
    y -= (a / b) * x;
    return res;
}


int main() {
    COMinit();
    int N, M, K;
    std::cin >> N >> M >> K;

    ll denomi = 0;
    std::vector<ll> W(N);
    for (int i = 0; i < N; i++) {
        std::cin >> W[i];
        denomi += W[i];
    }

    std::vector<std::vector<ll>> prob(N, std::vector<ll>(K + 1));
    for (int i = 0; i < N; i++) {
        prob[i][0] = 1;
        for (int k = 1; k <= K; k++) {
            prob[i][k] = (prob[i][k - 1] * W[i]) % MOD;
        }
    }

    denomi = mod_pow(denomi, K, MOD);
    ll inv, tmp;
    ext_gcd(denomi, MOD, inv, tmp);

    std::vector<std::vector<ll>> dp(K + 1, std::vector<ll>(M + 1, 0));
    dp[0][0] = 1;

    for (int n = 0; n < N; n++) {
        std::vector<std::vector<ll>> next(K + 1, std::vector<ll>(M + 1));
        next = dp;
        for (int k = 1; k <= K; k++) {
            for (int m = 0; m < M; m++) {
                for (int j = 0; j < k; j++) {
                    ll p = COM(k, k - j) * prob[n][k - j] % MOD;
                    next[k][m + 1] = (next[k][m + 1] + dp[j][m] * p) % MOD;
                }
            }
        }
        // for (auto& vec : next) {
        //     for (auto& val : vec) {
        //         std::cout << val << " ";
        //     }
        //     std::cout << std::endl;
        // }
        // std::cout << std::endl;
        dp = next;
    }

    std::cout << (dp[K][M] * inv % MOD + MOD) % MOD << std::endl;
}
