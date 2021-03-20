#include <bits/stdc++.h>

using ll = long long int;

class RUQSegtree {
  public:
    RUQSegtree(std::vector<ll> vec) {
        auto num = vec.size();
        max = 1;
        while (max < num) {
            max *= 2;
        }
        seg = std::vector<ll>(max * 2 - 1, 0);
        std::memcpy(seg.data() + max - 1, vec.data(), sizeof(ll) * vec.size());
    }

    ll get(int idx) {
        idx = max - 1 + idx;
        ll sum = seg[0];
        while (idx > 0) {
            sum += seg[idx];
            idx = (idx - 1) / 2;
        }
        return sum;
    }

    void update(ll val, int min, int max, int left, int right, int idx) {
        if (right <= min || max <= left) {
            return;
        }

        if (min <= left && right <= max) {
            seg[idx] = val;
            return;
        }
        update(val, min, max, left, (left + right) / 2, idx * 2 + 1);
        update(val, min, max, (left + right) / 2, right, idx * 2 + 2);
    }

    std::vector<ll> seg;
    int max;
};


std::vector<int> index_sort(std::vector<ll>& ref) {
    std::vector<int> idx(ref.size());
    std::iota(idx.begin(), idx.end(), 0);

    std::sort(idx.begin(), idx.end(), [&ref](auto& lhs, auto& rhs) { return ref[lhs] < ref[rhs]; });
    return idx;
}


int main() {
    ll N, D, A;
    std::cin >> N >> D >> A;

    std::vector<ll> X(N), H(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i] >> H[i];
    }

    auto sorted = index_sort(X);
    std::vector<ll> sX(N), sH(N);
    for (int i = 0; i < N; i++) {
        sX[i] = X[sorted[i]];
        sH[i] = H[sorted[i]];
    }

    RUQSegtree seg(sH);
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        ll val = seg.get(i);
        if (val <= 0) {
            continue;
        }
        auto ub = std::upper_bound(sX.begin(), sX.end(), sX[i] + 2 * D);
        auto ub_idx = std::distance(sX.begin(), ub);
        ll num = (val + A - 1) / A;
        ll attack = num * A;
        cnt += num;
        seg.update(-attack, i, ub_idx, 0, seg.max, 0);
    }

    std::cout << cnt << std::endl;
}
