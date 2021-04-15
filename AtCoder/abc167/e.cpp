#include <bits/stdc++.h>


const int MAX = 510000;
const long long MOD = 998244353;

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

long long mod_pow(long long n, long long r) {
    long long ans = 1;
    long long pow = n;
    while (r > 0) {
        if (r & 1) {
            ans = (ans * pow) % MOD;
        }
        pow = (pow * pow) % MOD;
        r >>= 1;
    }
    return ans;
}


int main() {
    COMinit();

    long long N, M, K;
    std::cin >> N >> M >> K;

    long long ans = 0;
    for (int i = 0; i <= K; i++) {
        ans = ((COM(N - 1, i) * M % MOD) * mod_pow(M - 1, N - 1 - i)) % MOD + ans;
        ans %= MOD;
        // std::cout << COM(N - 1, i) * M << " * " << M - 1 << "**" << N - 1 - i << " = "
        //           << mod_pow(M - 1, N - 1 - i) << " " << ans << std::endl;
    }

    std::cout << ans << std::endl;
}
