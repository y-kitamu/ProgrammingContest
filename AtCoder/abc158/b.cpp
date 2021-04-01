#include <bits/stdc++.h>

using ll = long long int;

int main() {
    ll N, A, B;
    std::cin >> N >> A >> B;

    ll cnt = N / (A + B);
    ll res = std::min(N - (A + B) * cnt, A);
    ll ans = cnt * A + res;
    std::cout << ans << std::endl;
}
