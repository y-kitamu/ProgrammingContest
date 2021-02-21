#include <bits/stdc++.h>

constexpr long long int MOD = 1e9 + 7;

long long int mod_pow(long long int a, long long int b, long long int mod = MOD) {
    long long int pow = a;
    long long int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * pow) % mod;
        }
        pow = (pow * pow) % mod;
        b = b >> 1;
    }
    return res;
}


int main() {
    long long int n, k;
    std::cin >> n >> k;

    std::cout << mod_pow(k, n, MOD) << std::endl;
}
