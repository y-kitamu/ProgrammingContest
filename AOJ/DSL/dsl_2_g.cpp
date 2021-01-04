#include <bits/stdc++.h>


class Segtree {
  public:
    Segtree(int n) {
        seg = std::vector<long long int>(n * 4, 0);
        lazy = std::vector<long long int>(n * 4, 0);
        offset = 1;
        while (offset < n) {
            offset *= 2;
        }
    }

    void eval(int idx) {
        if (lazy[idx] == DEFAULT_VALUE) {
            return;
        }
        int num = offset / std::pow(2, (int(std::log2(idx + 1)) + 1));
        long long int add_val = num * lazy[idx];
        if (idx < offset - 1) {
            lazy[idx * 2 + 1] += lazy[idx];
            lazy[(idx + 1) * 2] += lazy[idx];
            seg[idx * 2 + 1] += add_val;
            seg[(idx + 1) * 2] += add_val;
        }
        lazy[idx] = DEFAULT_VALUE;
    }

    void add(int mini, int maxi, int val, int idx, int left, int right) {
        if (maxi <= left || right <= mini) {
            return;
        }
        int overlap = std::min(maxi, right) - std::max(left, mini);
        seg[idx] += overlap * val;
        if (mini <= left && right <= maxi) {
            lazy[idx] += val;
            return;
        }
        add(mini, maxi, val, idx * 2 + 1, left, (left + right) / 2);
        add(mini, maxi, val, (idx + 1) * 2, (left + right) / 2, right);
    }

    long long int getSum(int mini, int maxi, int idx, int left, int right) {
        eval(idx);
        if (maxi <= left || right <= mini) {
            return 0;
        }
        if (mini <= left && right <= maxi) {
            return seg[idx];
        }
        long long int sum = 0;
        sum += getSum(mini, maxi, idx * 2 + 1, left, (left + right) / 2);
        sum += getSum(mini, maxi, (idx + 1) * 2, (left + right) / 2, right);
        return sum;
    }

    std::vector<long long int> seg, lazy;
    int offset;
    const long long int DEFAULT_VALUE = 0;
};


int main() {
    int n, q;

    std::cin >> n >> q;
    Segtree segtree(n);
    for (int i = 0; i < q; i++) {
        int com;
        std::cin >> com;
        if (com == 0) {
            int s, t, x;
            std::cin >> s >> t >> x;
            segtree.add(s - 1, t, x, 0, 0, segtree.offset);
        } else {
            int s, t;
            std::cin >> s >> t;
            long long int sum = segtree.getSum(s - 1, t, 0, 0, segtree.offset);
            std::cout << sum << std::endl;;
        }
    }
}
