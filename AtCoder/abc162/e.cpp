#include <bits/stdc++.h>

using ll = long long int;


ll mod_pow(ll n, ll r, ll mod) {
    ll ans = 1;
    ll pow = n;
    while (r > 0) {
        if (r & 1) {
            ans = (ans * pow) % mod;
        }
        pow = pow * pow % mod;
        r >>= 1;
    }
    return ans;
}


int main() {
    const ll MOD = 1e9 + 7;
    ll N, K;
    std::cin >> N >> K;

    ll sum = 0;
    std::vector<ll> A(K, 0);
    for (int i = K; i > 0; i--) {
        ll num = K / i;
        A[i - 1] = mod_pow(num, N, MOD);
        for (int j = i + i; j <= K; j += i) {
            A[i - 1] -= A[j - 1];
        }
        // std::cout << i << " " << num << " " << A[i - 1] << " " << std::endl;
        sum = (sum + A[i - 1] * i % MOD) % MOD;
    }
    std::cout << (sum + MOD) % MOD << std::endl;
}
