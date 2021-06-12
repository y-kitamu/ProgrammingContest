/*
 * a.cpp
 *
 * Create Date : 2021-06-12 20:59:25
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

using ll = long long int;

int main() {
    ll MOD = 1000000007;

    ll N;
    std::cin >> N;

    std::vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if (N == 1) {
        std::cout << A[0] << std::endl;
        return 0;
    } else if (N == 2) {
        std::cout << (2 * A[0]) % MOD << std::endl;
        return 0;
    }

    std::vector<ll> counts(N + 1, 0);
    counts[0] = 1;
    counts[1] = 1;
    for (ll i = 2; i <= N; i++) {
        counts[i] = (counts[i - 1] + counts[i - 2]) % MOD;
    }

    ll sum = (A[0] * counts[N]) % MOD;
    for (ll i = 1; i < N; i++) {
        ll pos = counts[i] * counts[N - i] % MOD;
        ll neg = counts[i - 1] * counts[N - i - 1] % MOD;
        sum = (sum + ((pos - neg) % MOD) * A[i] % MOD) % MOD;
    }
    std::cout << (sum % MOD + MOD) % MOD << std::endl;
}
