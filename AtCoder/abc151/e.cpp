#include <bits/stdc++.h>


const int MAX = 510000;
const int MOD = 1000000007;

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


long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main() {
    const long long int MOD = 1e9 + 7;
    long long int N, K;
    std::cin >> N >> K;

    std::vector<long long int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    COMinit();

    long long int min = 0;
    for (int i = 0; i <= N - K; i++) {
        min = (COM(N - i - 1, K - 1) * A[i] % MOD + min) % MOD;
    }
    long long int max = 0;
    for (int i = K - 1; i < N; i++) {
        max = (COM(i, K - 1) * A[i] % MOD + max) % MOD;
    }
    // std::cout << min << " " << max << std::endl;
    std::cout << (MOD + max - min) % MOD << std::endl;
}
