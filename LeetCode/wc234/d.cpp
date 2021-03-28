#include <bits/stdc++.h>

using ll = long long int;


ll MOD_POW(ll n, ll r, ll mod) {
    ll res = 1;
    ll pow = n;
    while (r > 0) {
        if (r & 1) {
            res = (res * pow) % mod;
        }
        pow = (pow * pow) % mod;
        r >>= 1;
    }
    return res;
}

class Solution {
  public:
    int maxNiceDivisors(int primeFactors) {
        int cnt = (primeFactors - 1) / 3;
        int res = primeFactors - cnt * 3;
        ll ans = MOD_POW(3, cnt, MOD);
        return (ans * res) % MOD;
    }

    ll MOD = 1e9 + 7;
};


int main() {}
