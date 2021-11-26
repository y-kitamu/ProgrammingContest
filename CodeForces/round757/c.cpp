/*
 * c.cpp
 *
 * Create Date : 2021-11-26 20:47:33
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

long long int mod_pow(long long int n, long long int r, long long int mod) {
    long long int ans = 1;
    long long int pow = n;
    while (r > 0) {
        if (r & 1) {
            ans = (ans * pow) % mod;
        }
        pow = (pow * pow) % mod;
        r >>= 1;
    }
    return ans;
}


const int MAX = 510000;
long long int MOD = 1e9 + 7;

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

int main() {
    COMinit();
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        long long int n, m;
        std::cin >> n >> m;
        std::vector<long long int> l(m), r(m), x(m);
        for (int j = 0; j < m; j++) {
            std::cin >> l[j] >> r[j] >> x[j];
            l[j]--;
            r[j]--;
        }

        std::vector<std::vector<long long int>> diff(n + 1, std::vector<long long int>(32, 0));
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 31; k++) {
                if (x[j] & (1 << k)) {
                    diff[l[j]][k]++;
                    diff[r[j] + 1][k]--;
                }
            }
        }

        std::vector<long long int> cnt(32, 0);
        std::vector<std::vector<long long int>> cnts(n + 1, std::vector<long long int>(32, 0));
        for (int k = 0; k < 31; k++) {
            cnts[0][k] = diff[0][k];
        }
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < 31; k++) {
                cnts[j][k] = cnts[j - 1][k] + diff[j][k];
                if (cnts[j][k] > 0) {
                    cnt[k]++;
                }
            }
        }

        long long ans = 0;
        for (int j = 0; j < 31; j++) {
            if (cnt[j] <= 0) {
                continue;
            }
            long long int val = 1 << j;
            long long int tmp = (val * mod_pow(2, n - cnt[j], MOD)) % MOD;
            for (int k = 1; k <= cnt[j]; k++) {
                if (k % 2 == 1) {
                    ans = (ans + tmp * COM(cnt[j], k)) % MOD;
                }
            }
        }
        std::cout << ans << std::endl;
    }
}
