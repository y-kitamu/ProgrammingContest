#include <bits/stdc++.h>

class Segtree {
  public:
    Segtree(int n) {
        seg = std::vector<long long int>(4 * n, 0);
        lazy = std::vector<long long int>(4 * n, MAX_VAL);
        offset = 1;
        while (offset < n) {
            offset *= 2;
        }
    }

    void eval(int idx) {
        if (lazy[idx] == MAX_VAL) {
            return;
        }
        if (idx < offset - 1) {
            lazy[idx * 2 + 1] = lazy[idx] / 2;
            lazy[idx * 2 + 2] = lazy[idx] / 2;
        }
        seg[idx] = lazy[idx];
        lazy[idx] = MAX_VAL;
    }

    void update(int mini, int maxi, int val, int idx, int left, int right) {
        eval(idx);
        if (right <= mini || maxi <= left) {
            return;
        }
        long long int sum = getSum(mini, maxi, idx, left, right);
        seg[idx] += (std::min(maxi, right) - std::max(mini, left)) * val - sum;
        if (mini <= left && right <= maxi) {
            if (idx < offset - 1) {
                lazy[idx * 2 + 1] = val * (right - left) / 2;
                lazy[idx * 2 + 2] = val * (right - left) / 2;
            }
            return;
        }
        update(mini, maxi, val, idx * 2 + 1, left, (left + right) / 2);
        update(mini, maxi, val, idx * 2 + 2, (left + right) / 2, right);
    }

    long long int getSum(int mini, int maxi, int idx, int left, int right) {
        eval(idx);
        if (right <= mini || maxi <= left) {
            return 0;
        }
        if (mini <= left && right <= maxi) {
            return seg[idx];
        }
        long long int sum = getSum(mini, maxi, idx * 2 + 1, left, (left + right) / 2);
        sum += getSum(mini, maxi, idx * 2 + 2, (left + right) / 2, right);
        return sum;
    }

    std::vector<long long int> seg, lazy;
    int offset;
    long long int MAX_VAL = 1e9;
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
            seg.update(s, t + 1, x, 0, 0, seg.offset);
        } else {
            int s, t;
            std::cin >> s >> t;
            std::cout << seg.getSum(s, t + 1, 0, 0, seg.offset) << std::endl;
        }
    }
}
