#include <bits/stdc++.h>


class Segtree {
  public:
    Segtree(long long int N) : N(N) {
        long long int log = std::log2(N);
        max = 1ll << (log + 1);
        seg = std::vector<long long int>(max * 2 - 1, N);
    }

    void update(long long int val, long long int min, long long int max, long long int left,
                long long int right, long long int idx) {
        if (max <= left || right <= min) {
            return;
        }
        if (idx * 2 + 2 < max && seg[idx] != N) {
            seg[idx * 2 + 1] = seg[idx];
            seg[idx * 2 + 2] = seg[idx];
        }
        if (min <= left && right <= max) {
            seg[idx] = std::min(val, seg[idx]);
            return;
        }
        int mid = (left + right) / 2;
        update(val, min, max, left, mid, idx * 2 + 1);
        update(val, min, max, mid, right, idx * 2 + 2);
    }

    int getval(int idx) {
        idx = idx + max - 1;
        long long int val = seg[idx];
        while (idx > 0) {
            idx = (idx - 1) / 2;
            val = std::min(seg[idx], val);
        }
        return val;
    }

    void print() {
        for (auto val : seg) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    long long int N;
    long long int max;
    std::vector<long long int> seg;
};


int main() {
    long long int N, Q;
    std::cin >> N >> Q;

    Segtree rows(N), cols(N);
    long long int sum = 0;
    for (int i = 0; i < Q; i++) {
        int val, x;
        std::cin >> val >> x;
        if (val == 1) {
            // cols.print();
            int cnt = cols.getval(x);
            sum += std::max(cnt - 2, 0);
            std::cout << cnt << std::endl;
            rows.update(x, 0, cnt, 0, rows.max, 0);
            // rows.print();
        } else {
            // rows.print();
            int cnt = rows.getval(x);
            sum += std::max(cnt - 2, 0);
            std::cout << cnt << std::endl;
            cols.update(x, 0, cnt, 0, cols.max, 0);
            // cols.print();
        }
    }
    std::cout << (N - 2) * (N - 2) - sum << std::endl;
}
