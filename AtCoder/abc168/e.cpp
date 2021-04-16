#include <bits/stdc++.h>

using ll = long long int;


ll GCD(ll a, ll b) { return b > 0 ? GCD(b, a % b) : a; }

ll mod_pow(ll n, ll r, ll MOD) {
    ll ans = 1;
    ll pow = n;
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
    int N;
    std::cin >> N;

    std::map<std::pair<ll, ll>, int> map;
    for (int i = 0; i < N; i++) {
        long long int a, b;
        std::cin >> a >> b;
        ll gcd = GCD(std::abs(a), std::abs(b));
        if (gcd > 0) {
            a /= gcd, b /= gcd;
        }
        if (a < 0) {
            a *= -1;
            b *= -1;
        }
        if (a == 0 && b != 0) {
            b = 1;
        }
        if (b == 0 && a != 0) {
            a = 1;
        }
        std::pair<ll, ll> p{a, b};
        if (map.find(p) == map.end()) {
            map[p] = 0;
        }
        map[p]++;
    }

    ll MOD = 1e9 + 7;
    ll ans = 1;
    ll zeros = 0;
    for (auto& pair : map) {
        ll x = pair.first.first;
        ll y = pair.first.second;

        if (x == 0 && y == 0) {
            zeros = pair.second;
            continue;
        }

        auto p = y <= 0 ? std::make_pair(-y, x) : std::make_pair(y, -x);
        if (map.find(p) != map.end()) {
            ll cnt = (mod_pow(2, pair.second, MOD) + mod_pow(2, map[p], MOD) - 1) % MOD;
            ans = (ans * cnt) % MOD;
            map[p] = 0;
        } else {
            ans = ans * mod_pow(2, pair.second, MOD) % MOD;
        }
        map[pair.first] = 0;
    }
    std::cout << ans + zeros - 1 << std::endl;
}
