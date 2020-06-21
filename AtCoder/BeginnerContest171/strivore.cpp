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

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    long long int K;
    std::string S;
    std::cin >> K;
    std::cin >> S;

    long long int all = modpow(26, K + S.length(), MOD);
    long long int no = COM(K + S.length(), S.length()) * modpow(26, K, MOD);
    long long int out = all - no;
    if (out < 0) {
        out += MOD;
    }
    std::cout << out << std::endl;
}
