#include <bits/stdc++.h>


const int MAX = 5000000;
const int MOD = 1000000007;

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


long long int mod_pow(long long int n, long long int r) {
    long long int ans = 1;
    long long int pow = n;
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
    int K;
    std::string S;
    std::cin >> K >> S;
    int len = S.length();

    long long int sum = 0;
    for (int i = 0; i <= K; i++) {
        long long int val =
            (COM(len + i - 1, len - 1) * mod_pow(25, i) % MOD) * mod_pow(26, K - i) % MOD;
        sum = (sum + val) % MOD;
    }
    std::cout << sum << std::endl;
}
