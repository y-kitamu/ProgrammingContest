#include <bits/stdc++.h>

long long int mod = 1e9 + 7;

long long int modpow(long long int val, long long int power) {
    long long int res = 1;
    while (power > 0) {
        if (power & 1) {
            res = res * val % mod;
        }
        val = val * val % mod;
        power >>= 1;
    }
    return res;
}


int main() {
    int N;
    std::cin >> N;

    long long int res = (modpow(10, N) - modpow(9, N) * 2 + modpow(8, N)) % mod;
    if (res < 0) {
        res += mod;
    }
    std::cout << res << std::endl;
}
