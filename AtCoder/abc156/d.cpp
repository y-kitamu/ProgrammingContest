#include <bits/stdc++.h>

using ll = long long int;

ll mod_pow(ll n, ll r, ll mod) {
    ll pow = n;
    ll res = 1;
    while (r > 0) {
        if (r & 1) {
            res = (res * pow) % mod;
        }
        pow = (pow * pow) % mod;
        r >>= 1;
    }
    return res;
}


const int MAX = 1000000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];
ll N, a, b;

// テーブルを作る前処理
void COMinit() {
    fac[0] = N;
    fac[1] = N * (N - 1) % MOD;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * (N - i) % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int k) {
    // if (n < k) return 0;
    // if (n < 0 || k < 0) return 0;
    return fac[k - 1] * finv[k] % MOD;
}

int main() {
    ll MOD = 1e9 + 7;
    std::cin >> N >> a >> b;

    COMinit();

    ll all = mod_pow(2, N, MOD) - 1;
    ll no = (COM(a) + COM(b)) % MOD;
    // std::cout << all << " , " << no << std::endl;
    std::cout << (all - no + MOD) % MOD << std::endl;
}
