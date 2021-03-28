#include <bits/stdc++.h>


using ll = long long int;

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b;
        std::swap(a, b);
        u -= t * v;
        std::swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
    ll MOD = 998244353;
    ll N;
    std::cin >> N;
    std::vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    std::sort(A.begin(), A.end());

    std::vector<ll> sums(N);
    sums[0] = 0;
    ll pow = 1;
    for (int i = 1; i < N; i++) {
        sums[i] = (sums[i - 1] + (A[i] * pow) % MOD) % MOD;
        pow = (pow * 2) % MOD;
    }

    ll sum = 0;
    pow = 1;
    for (int i = 0; i < N; i++) {
        // std::cout << A[i] << " , " << sums[N - 1] - sums[i] << std::endl;
        // std::cout << A[i] << " , " << modinv(pow, MOD) << std::endl;
        ll one = A[i] * A[i] % MOD;
        ll more = (A[i] * (sums[N - 1] - sums[i])) % MOD * modinv(pow, MOD) % MOD;
        sum = (sum + one + more) % MOD;
        pow = (2 * pow) % MOD;
    }
    std::cout << (sum + MOD) % MOD << std::endl;
}
