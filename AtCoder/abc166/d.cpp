#include <bits/stdc++.h>

using ll = long long int;


ll pow(ll n, ll r) {
    ll ans = 1;
    ll scale = n;
    while (r > 0) {
        if (r & 1) {
            ans *= scale;
        }
        r >>= 1;
        scale *= scale;
    }
    return ans;
}


ll diff(ll n) { return pow(n + 1, 5) - pow(n, 5); }


int main() {
    ll X;
    std::cin >> X;
    int max_i = 0;
    for (;; max_i++) {
        auto val = diff(max_i);
        // std::cout << max_i << " " << val << std::endl;
        if (val > X) {
            break;
        }
    }

    for (ll a = -max_i; a <= max_i; a++) {
        for (ll b = -max_i; b <= max_i; b++) {
            if (pow(a, 5) - pow(b, 5) == X) {
                std::cout << a << " " << b << std::endl;
                return 0;
            }
        }
    }
}
