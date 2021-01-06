#include <bits/stdc++.h>


class Segtree {
  public:
    Segtree(int n) {
        seg = std::vector<long long int>(4 * n, 0);
        lazy = std::vector<long long int>(4 * n, 0);
        offset = 1;
        while (offset < n) {
            offset *= 2;
        }
    }

    void eval(int idx) {
        if (lazy[idx] == 0) {
            return;
        }
        if (idx < offset - 1) {
            lazy[idx * 2 + 1] += lazy[idx];
            lazy[(idx + 1) * 2] += lazy[idx];
        }
        seg[idx] += lazy[idx];
        lazy[idx] = 0;
        while (idx > 0) {
            idx = (idx - 1) / 2;
            seg[idx] = std::min(seg[idx * 2 + 1], seg[(idx + 1) * 2]);
        }
    }

    void add(int mini, int maxi, int val, int idx, int left, int right) {
        eval(idx);
        if (maxi <= left || right <= mini) {
            return;
        }
        if (mini <= left && right <= maxi) {
            lazy[idx] += val;
            eval(idx);
            return;
        }
        add(mini, maxi, val, idx * 2 + 1, left, (left + right) / 2);
        add(mini, maxi, val, (idx + 1) * 2, (left + right) / 2, right);
    }

    long long int find(int mini, int maxi, int idx, int left, int right) {
        eval(idx);
        if (maxi <= left || right <= mini) {
            return MAX;
        }
        if (mini <= left && right <= maxi) {
            return seg[idx];
        }
        long long int lval = find(mini, maxi, idx * 2 + 1, left, (left + right) / 2);
        long long int rval = find(mini, maxi, (idx + 1) * 2, (left + right) / 2, right);
        return std::min(lval, rval);
    }

    long long int MAX = 1e10;
    std::vector<long long int> seg, lazy;
    int offset;
};

int main() {
    int n, q;
    std::cin >> n >> q;

    Segtree seg(n);
    for (int i = 0; i < q; i++) {
        int cmd;
        std::cin >> cmd;
        if (cmd == 0) {
            int s, t, x;
            std::cin >> s >> t >> x;
            seg.add(s, t + 1, x, 0, 0, seg.offset);
        } else {
            int s, t;
            std::cin >> s >> t;
            std::cout << seg.find(s, t + 1, 0, 0, seg.offset) << std::endl;;
        }
    }
}
