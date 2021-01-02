#include <bits/stdc++.h>

using lli = long long int;

constexpr lli VAL = (1ll << 31) - 1;

class Segtree {
  public:
    Segtree(int n) {
        lazy = std::vector<lli>(n * 4, VAL);
        seg = std::vector<lli>(n * 4, VAL);
        offset = 1;
        while (offset < n) {
            offset *= 2;
        }
    }

    void eval(int k) {
        if (lazy[k] == VAL) {
            return;
        }
        if (k < offset) {
            lazy[k * 2 + 1] = lazy[k];
            lazy[(k + 1) * 2] = lazy[k];
        }
        seg[k] = lazy[k];
        lazy[k] = VAL;
    }

    void update(int mini, int maxi, int val, int idx, int left, int right) {
        eval(idx);
        if (mini <= left && right <= maxi) {
            lazy[idx] = val;
            eval(idx);
        } else if (mini < right && left < maxi) {
            update(mini, maxi, val, idx * 2 + 1, left, (left + right) / 2);
            update(mini, maxi, val, (idx + 1) * 2, (left + right) / 2, right);
            seg[idx] = std::min(seg[idx * 2 + 1], seg[(idx + 1) * 2]);
        }
    }

    int find(int mini, int maxi, int idx, int left, int right) {
        eval(idx);
        if (maxi <= left || right <= mini) {
            return VAL;
        } else if (mini <= left && right <= maxi) {
            return seg[idx];
        }
        int vleft = find(mini, maxi, idx * 2 + 1, left, (left + right) / 2);
        int vright = find(mini, maxi, (idx + 1) * 2, (left + right) / 2, right);
        return std::min(vleft, vright);
    }

    std::vector<lli> lazy, seg;
    int offset;
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
            segtree.update(s, t + 1, x, 0, 0, segtree.offset);
        } else {
            int s, t;
            std::cin >> s >> t;
            auto val = segtree.find(s, t + 1, 0, 0, segtree.offset);
            std::cout << val << std::endl;
        }
    }
}
