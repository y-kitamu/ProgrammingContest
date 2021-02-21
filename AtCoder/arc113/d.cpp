#include <bits/stdc++.h>


long long int mod_pow(long long int n, long long int r, long long int mod) {
    long long int pow = n;
    long long int res = 1;
    while (r > 0) {
        if (r & 1) {
            res = (res * pow) % mod;
        }
        pow = pow * pow % mod;
        r >>= 1;
    }
    return res;
}

void solve(long long int N, long long int M, long long int K) {
    long long int MOD = 998244353;

    if (N == 1 && M == 1) {
        std::cout << K << std::endl;
        return;
    }

    std::vector<long long int> pows_n(K + 1, 0), pows_m(K + 1, 0);

    for (long long int i = 1; i < K + 1; i++) {
        pows_n[i] = mod_pow(i, N, MOD);
        pows_m[i] = mod_pow(i, M, MOD);
    }

    long long int sum = 0;
    for (long long int i = 1; i <= K; i++) {
        long long int X = mod_pow(i, N, MOD) + MOD - mod_pow(i - 1, N, MOD);
        long long int Y = mod_pow(K - i + 1, M, MOD);
        sum = (sum + X * Y) % MOD;
    }
    sum = (MOD * MOD + sum) % MOD;
    std::cout << sum << std::endl;
}


int main() {
    long long int N, M, K;
    std::cin >> N >> M >> K;
    solve(N, M, K);
}
