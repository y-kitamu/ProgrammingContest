#include <bits/stdc++.h>


long long int modFact(long long int n, long long int mod) {
    long long int res = 1;
    for (int i = 2; i <= n; i++) {
        res = (res * i) % mod;
    }
    return res;
}


long long int modPow(long long int n, long long int k, long long int mod) {
    long long int res = 1;
    long long int pow = n;
    while (k > 0) {
        if (k & 1) {
            res = (res * pow) % mod;
        }
        pow = (pow * pow) % mod;
        k >>= 1;
    }
    return res;
}


long long int modConb(long long int n, long long int r, long long int mod) {
    long long int res0 = modFact(n, mod);
    long long int res1 = modFact(r, mod);
    res1 = modPow(res1, mod - 2, mod);
    long long int res2 = modFact(n - r, mod);
    res2 = modPow(res2, mod - 2, mod);
    return (((res0 * res1) % mod) * res2) % mod;
}


int main() {
    int X, Y;
    std::cin >> X >> Y;

    if ((X + Y) % 3 != 0) {
        std::cout << 0 << std::endl;
        return 0;
    }
    if (X > 2 * Y || Y > 2 * X) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int steps = (X + Y) / 3;
    int lhs = X - steps;

    long long int MOD = 1e9 + 7;
    std::cout << modConb(steps, lhs, MOD) << std::endl;
}
