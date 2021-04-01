#include <bits/stdc++.h>


using ll = long long int;

int main() {
    ll N, P;
    std::cin >> N >> P;
    std::string S;
    std::cin >> S;

    if (P == 2 || P == 5) {
        ll cnt = 0;
        for (ll i = 0; i < N; i++) {
            if ((S[N - 1 - i] - '0') % P == 0) {
                cnt += N - i;
            }
        }
        std::cout << cnt << std::endl;
    } else {
        std::vector<ll> mods(N + 1, 0);
        ll pow = 1;
        for (ll i = 0; i < N; i++) {
            mods[i + 1] = (mods[i] + (S[N - i - 1] - '0') * pow) % P;
            pow = (pow * 10) % P;
        }

        std::vector<ll> cnts(P, 0);
        for (auto& mod : mods) {
            cnts[mod]++;
        }

        ll ans = 0;
        for (auto cnt : cnts) {
            ans += cnt * (cnt - 1) / 2;
        }

        std::cout << ans << std::endl;
    }
}
