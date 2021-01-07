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
            lazy[idx * 2 + 2] += lazy[idx];
        }
        int val = 1;
        while (val * 2 - 1 < idx) {
            val *= 2;
        }
        int num_elem = offset / val;
        seg[idx] = num_elem * lazy[idx];
        lazy[idx] = 0;
    }

    void update(int mini, int maxi, int val, int idx, int left, int right) {
        if (maxi <= left || right <= mini) {
            return;
        }
        long long int sum = getSum(mini, maxi, idx, left, right);
        seg[idx] += val * (std::min(right, maxi) - std::max(left, mini)) - sum;
        if (mini <= left && right <= maxi) {
            if (idx < offset) {
                lazy[idx * 2 + 1] += val;
                lazy[idx * 2 + 2] += val;
            }
            return;
        }
        update(mini, maxi, val, idx * 2 + 1, left, (left + right) / 2);
        update(mini, maxi, val, (idx + 1) * 2, (left + right) / 2, right);
    }

    long long int getSum(int mini, int maxi, int idx, int left, int right) {
        eval(idx);
        if (maxi <= left || right <= mini) {
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
};

int main() {
    int n, q;
    std::cin >> n >> q;

    Segtree seg(n);

    for (int i = 0; i < q; i++) {
        int com;
        std::cin >> com;
        if (com == 0) {
            int s, t, x;
            std::cin >> s >> t >> x;
            seg.update(s, t + 1, x, 0, 0, seg.offset);
        } else {
            int s, t;
            std::cin >> s >> t;
            std::cout << seg.getSum(s, t + 1, 0, 0, seg.offset) << std::endl;;
        }
    }
}
