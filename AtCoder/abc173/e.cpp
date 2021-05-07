#include <bits/stdc++.h>

using ll = long long int;


int main() {
    ll MOD = 1e9 + 7;
    int N, K;
    std::cin >> N >> K;

    std::vector<ll> A, B;
    for (int i = 0; i < N; i++) {
        int val;
        std::cin >> val;
        if (val < 0) {
            B.emplace_back(-val);
        } else if (val >= 0) {
            A.emplace_back(val);
        }
    }
    if (N == K) {
        ll res = 1;
        for (auto& val : A) {
            res = res * val % MOD;
        }
        for (auto& val : B) {
            res = res * val % MOD;
        }
        if (B.size() % 2 == 1) {
            res = (MOD - res) % MOD;
        }
        std::cout << res << std::endl;
        return 0;
    }
    if (A.size() == 0 && K % 2 == 1) {
        std::sort(B.begin(), B.end());
        ll res = 1;
        for (int i = 0; i < K; i++) {
            res = (res * B[i]) % MOD;
        }
        std::cout << (MOD - res) % MOD << std::endl;
        return 0;
    }
    std::sort(A.begin(), A.end(), std::greater());
    std::sort(B.begin(), B.end(), std::greater());
    ll res = 1;
    ll idx = 0, idx_a = 0, idx_b = 0;
    ll na = A.size(), nb = B.size();
    while (idx < K) {
        if (idx_b >= nb - 1 || idx == K - 1) {
            res = (res * A[idx_a]) % MOD;
            idx_a++;
            idx++;
        } else if (idx_a >= na - 1) {
            res = ((B[idx_b] * B[idx_b + 1]) % MOD) * res % MOD;
            idx_b += 2;
            idx += 2;
        } else {
            ll a = A[idx_a] * A[idx_a + 1];
            ll b = B[idx_b] * B[idx_b + 1];
            if (a >= b) {
                res = res * A[idx_a] % MOD;
                idx_a++;
                idx++;
            } else {
                res = res * (b % MOD) % MOD;
                idx_b += 2;
                idx += 2;
            }
        }
    }
    std::cout << res << std::endl;
}
