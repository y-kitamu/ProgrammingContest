#include <bits/stdc++.h>


using ll = long long int;

int main() {
    ll X, Y, A, B, C;
    std::cin >> X >> Y >> A >> B >> C;
    std::vector<ll> p(A), q(B), r(C + 1, 0);
    for (ll i = 0; i < A; i++) {
        std::cin >> p[i];
    }
    for (ll j = 0; j < B; j++) {
        std::cin >> q[j];
    }
    for (ll k = 0; k < C; k++) {
        std::cin >> r[k];
    }

    std::sort(p.begin(), p.end(), std::greater<ll>());
    std::sort(q.begin(), q.end(), std::greater<ll>());
    std::sort(r.begin(), r.end(), std::greater<ll>());

    // auto pring = [](std::vector<ll>& vec) {
    //     for (auto& val : vec) {
    //         std::cout << val << " ";
    //     }
    //     std::cout << std::endl;
    // };
    // pring(p);
    // pring(q);
    // pring(r);

    ll ans = 0;
    ll ia = 0, ib = 0, ic = 0;
    for (ll i = 0; i < X + Y; i++) {
        if (ia < X && ib < Y) {
            // std::cout << ia << " " << ib << " " << ic << " ";
            // std::cout << p[ia] << " " << q[ib] << " " << r[ic] << std::endl;
            if (p[ia] >= q[ib] && p[ia] >= r[ic]) {
                ans += p[ia++];
            } else if (q[ib] >= p[ia] && q[ib] >= r[ic]) {
                ans += q[ib++];
            } else {
                ans += r[ic++];
            }
        } else if (ia < X) {
            if (p[ia] >= r[ic]) {
                ans += p[ia++];
            } else {
                ans += r[ic++];
            }
        } else {
            if (q[ib] >= r[ic]) {
                ans += q[ib++];
            } else {
                ans += r[ic++];
            }
        }
    }
    // std::cout << ia << " " << ib << " " << ic << std::endl;
    std::cout << ans << std::endl;
}
