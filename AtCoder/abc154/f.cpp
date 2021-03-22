#include <bits/stdc++.h>

const int MAX = 5000000;
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
long long comb_mod(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main() {
    COMinit();
    long long int r1, c1, r2, c2;
    std::cin >> r1 >> c1 >> r2 >> c2;

    long long int MOD = 1e9 + 7;

    long long int sum = comb_mod(c2 + r2, r2);
    if (r1 == r2 && c1 == c2) {
    } else if (r1 == r2) {
        for (long long int i = c1; i < c2; i++) {
            sum = (sum + comb_mod(i + r2, r2)) % MOD;
        }
    } else if (c1 == c2) {
        for (long long int i = r1; i < r2; i++) {
            sum = (sum + comb_mod(c2 + i, c2)) % MOD;
        }
    } else {
        sum = (sum + comb_mod(c1 + r1, r1) + comb_mod(c2 + r2, r2)) % MOD;
        for (long long int i = c1 + 1; i < c2; i++) {
            sum = (sum + comb_mod(i + r2, r2)) % MOD;
        }
        for (long long int i = r1 + 1; i < r2; i++) {
            sum = (sum + comb_mod(c2 + i, c2)) % MOD;
        }
    }


    std::cout << (sum + MOD) % MOD << std::endl;
}
