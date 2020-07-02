#include <bits/stdc++.h>

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

long long modpow(long long a, long long n, long long mod) {
    long long int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    long long int N, M;
    std::cin >> N >> M;

    COMinit();
    long long int pattern = COM(M, N);
    long long int combi = 0;
    for (int i = 1; i <= N; i++) {
        int tmp = COM(M - i, N - i) - COM(M - i - 1, N - i - 1);
        if (tmp < 0) {
            tmp += MOD;
        }
        combi = (combi + COM(N, i) * tmp) % MOD;
    }
    long long int nkai = 1;
    for (long long int i = 1; i <= N; i++) {
        nkai = nkai * i % MOD;
    }
    long long int sum = (pattern * nkai % MOD - combi) * pattern % MOD;
    sum = sum * nkai % MOD;
    std::cout << sum << std::endl;
}
