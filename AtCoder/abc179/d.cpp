#include <bits/stdc++.h>


using ll = long long int;

ll MOD = 998244353;

class Segtree {
  public:
    Segtree(ll N) {
        max = 1;
        while (max < N) {
            max *= 2;
        }
        offset = max - 1;
        seg = std::vector<ll>(max * 2 - 1, 0);
        seg[offset] = 1;
    }

    void add(ll val, ll min, ll max, ll left, ll right, ll idx) {
        if (max <= left || right <= min) {
            return;
        }
        if (min <= left && right <= max) {
            seg[idx] = (seg[idx] + val) % MOD;
            return;
        }
        ll mid = (left + right) / 2;
        add(val, min, max, left, mid, idx * 2 + 1);
        add(val, min, max, mid, right, idx * 2 + 2);
    }

    ll getvalue(ll idx, ll val) {
        if (idx == 0) {
            return (seg[idx] + val) % MOD;
        }
        return getvalue((idx - 1) / 2, (seg[idx] + val) % MOD);
    }

    void print() {
        for (auto& val : seg) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    ll max, offset;
    std::vector<ll> seg;
};


int main() {
    ll N, K;

    std::cin >> N >> K;

    std::vector<std::vector<ll>> lr(K, std::vector<ll>(2));
    for (ll i = 0; i < K; i++) {
        std::cin >> lr[i][0] >> lr[i][1];
    }

    Segtree seg(N);
    for (ll i = 0; i < N; i++) {
        ll val = seg.getvalue(seg.offset + i, 0);
        for (ll k = 0; k < K; k++) {
            if (i + lr[k][0] >= N) {
                continue;
            }
            seg.add(val, i + lr[k][0], std::min(i + lr[k][1] + 1, N), 0, seg.max, 0);
        }
        // seg.print();
    }

    std::cout << seg.getvalue(seg.offset + N - 1, 0) << std::endl;
}
