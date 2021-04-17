#include <bits/stdc++.h>


using ll = long long int;

ll mod_pow(ll n, ll r, ll mod) {
    ll ans = 1;
    ll pow = n;
    while (r > 0) {
        if (r & 1) {
            ans = (ans * pow) % mod;
        }
        pow = (pow * pow) % mod;
        r >>= 1;
    }
    return ans;
}

int main() {
    ll MOD = 1e9 + 7;
    ll N, P;
    std::cin >> N >> P;

    ll ans = (P - 1) * mod_pow(P - 2, N - 1, MOD) % MOD;
    std::cout << ans << std::endl;
}
