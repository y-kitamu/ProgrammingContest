#include <bits/stdc++.h>


class Segtree {
  public:
    Segtree(int N) {
        int num = 1;
        while (num < N) {
            num *= 2;
        }
        seg = std::vector<int>(num * 2 - 1, 0);
        offset = num - 1;
    }

    void update(int idx, int val) {
        seg[idx] = val;
        if (idx == 0) {
            return;
        }

        idx = (idx - 1) / 2;
        update(idx, seg[idx * 2 + 1] + seg[idx * 2 + 2]);
    }

    int sum(int left, int right, int min, int max, int idx) {
        if (max <= left || right <= min) {
            return 0;
        }
        if (left <= min && max <= right) {
            return seg[idx];
        }
        int res = 0;
        int mid = (min + max) / 2;
        res += sum(left, right, min, mid, idx * 2 + 1);
        res += sum(left, right, mid, max, idx * 2 + 2);
        return res;
    }

    void print() {
        for (auto val : seg) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    std::vector<int> seg;
    int offset;
};


std::vector<int> index_sort(std::vector<int>& vec) {
    std::vector<int> idx(vec.size(), 0);
    std::iota(idx.begin(), idx.end(), 0);

    std::sort(idx.begin(), idx.end(), [&vec](auto& lhs, auto& rhs) { return vec[lhs] < vec[rhs]; });
    return idx;
}


int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> c(N);
    std::vector<std::vector<int>> ll(N);
    for (int i = 0; i < N; i++) {
        std::cin >> c[i];
        c[i]--;
        ll[c[i]].emplace_back(i);
    }

    std::vector<int> L(Q), R(Q);
    for (int i = 0; i < Q; i++) {
        std::cin >> L[i] >> R[i];
        L[i]--;
    }
    auto sorted = index_sort(L);

    Segtree seg(N);
    for (int i = 0; i < N; i++) {
        if (ll[i].size() > 0) {
            seg.update(ll[i][0] + seg.offset, 1);
        }
    }

    std::vector<int> idx(N, 0);
    std::vector<int> res(Q);
    int cur = 0;

    for (int j = 0; j < Q; j++) {
        int left = L[sorted[j]];
        int right = R[sorted[j]];
        // std::cout << left << ", " << right << std::endl;
        for (; cur < left; cur++) {
            if (seg.seg[seg.offset + cur] == 1) {
                idx[c[cur]]++;
                if (idx[c[cur]] < ll[c[cur]].size()) {
                    seg.update(seg.offset + ll[c[cur]][idx[c[cur]]], 1);
                }
            }
            // std::cout << cur << ",," << seg.offset + cur << std::endl;
            seg.update(seg.offset + cur, 0);
        }
        // seg.print();
        res[sorted[j]] = seg.sum(left, right, 0, seg.offset + 1, 0);
    }

    for (int i = 0; i < Q; i++) {
        std::cout << res[i] << std::endl;
    }
}
