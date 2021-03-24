#include <bits/stdc++.h>


using ll = long long int;

ll count(ll val, std::vector<ll>& A, std::vector<ll>& B) {
    ll rhs = B.size();
    ll cnt = 0;

    for (ll i = 0; i < A.size(); i++) {
        while (rhs > 0 && B[rhs - 1] * A[i] > val) {
            rhs--;
        }
        if (B[rhs] * A[i] <= val) {
            break;
        }
        cnt += B.size() - rhs;
    }
    return cnt;
}


ll binarySearch(ll k, ll min, ll max, std::vector<ll>& A, std::vector<ll>& B) {
    if (min == max) {
        return min;
    }
    ll mid = (min + max) / 2;
    ll cnt = count(mid, A, B);

    if (cnt <= k) {
        return binarySearch(k, min, mid, A, B);
    }
    return binarySearch(k, mid + 1, max, A, B);
}


int main() {
    ll N, K;
    std::cin >> N >> K;

    std::vector<ll> Apos, Aneg;
    int zeros = 0;
    for (ll i = 0; i < N; i++) {
        ll val;
        std::cin >> val;
        if (val == 0) {
            zeros++;
        } else if (val > 0) {
            Apos.emplace_back(val);
        } else {
            Aneg.emplace_back(-val);
        }
    }

    std::sort(Apos.begin(), Apos.end());
    std::sort(Aneg.begin(), Aneg.end());

    ll MAX = 1e18;
    ll res;
    if (K <= Apos.size() * Aneg.size()) {
        res = -binarySearch(K, 0, MAX, Apos, Aneg);
    } else {
        ll znum = zeros * (zeros - 1) / 2 + zeros * (N - zeros);
        if (K <= Apos.size() * Aneg.size() + znum) {
            res = 0;
        } else {
            res = binarySearch(N * (N - 1) / 2 - K, 0, MAX, Apos, Aneg);
        }
    }

    std::cout << res << std::endl;
}
