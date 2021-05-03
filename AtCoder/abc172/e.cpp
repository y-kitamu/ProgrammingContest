#include <bits/stdc++.h>

using ll = long long int;

const int MAX = 510000;
const int MOD = 1000000007;

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
    int N, M;
    std::cin >> N >> M;

    COMinit();

    std::vector<ll> perm(N + 1, 0);
    perm[0] = 1;
    for (int i = 1; i <= N; i++) {
        perm[i] = perm[i - 1] * (M - N + i) % MOD;
    }

    ll sum = 0;
    ll flag = 1;
    for (int i = 1; i <= N; i++) {
        sum = (sum + flag * perm[N - i] * COM(N, i) % MOD) % MOD;
        flag *= -1;
    }
    ll res = (perm[N] - sum + MOD) % MOD;
    // std::cout << res << std::endl;
    std::cout << (res * perm[N]) % MOD << std::endl;
}
