/*
 * f.cpp
 *
 * Create Date : 2021-10-17 22:04:04
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


struct Segtree {
    Segtree(std::string S) {
        int n = S.length() * 4;
        mins = std::vector<int>(n, 0);
        sums = std::vector<int>(n, 0);

        offset = (1 << (int)log2(S.length())) - 1;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '(') {
                sums[i] = 1;
                mins[i] = 1;
            } else {
                mins[i] = -1;
                sums[i] = -1;
            }
        }

        for (int i = offset - 1; i >= 0; i--) {
            sums[i] = sums[i * 2 + 1] + sums[i * 2 + 2];
            mins[i] = mins[i * 2 + 1] + std::min(0, mins[i * 2 + 2]);
        }
    }

    void swap(int l, int r) {
        if (sums[l + offset] == sums[r + offset]) {
            return;
        }

        l += offset;
        sums[l] *= -1;
        mins[l] *= -1;
        while (l > 0) {
            l = (l - 1) / 2;
            sums[l] = sums[l * 2 + 1] + sums[l * 2 + 2];
            mins[l] = mins[l * 2 + 1] + std::min(0, mins[l * 2 + 2]);
        }
        r += offset;
        sums[r] *= -1;
        mins[r] *= -1;
        while (r > 0) {
            r = (r - 1) / 2;
            sums[r] = sums[r * 2 + 1] + sums[r * 2 + 2];
            mins[r] = mins[r * 2 + 1] + std::min(0, mins[r * 2 + 2]);
        }
    }

    int sum(int l, int r, int k, int min, int max) {
        if (max <= l || r <= min) {
            return 0;
        }
        if (l <= min && max <= r) {
            return sums[k];
        }
        int vl = sum(l, r, k * 2 + 1, min, (min + max) / 2);
        int vr = sum(l, r, k * 2 + 2, (min + max) / 2, min);
        return vl + vr;
    }

    int min(int l, int r, int k, int min, int max) {
        if (max <= l || r <= min) {
            return 0;
        }
        if (l <= min && max <= r) {
            return mins[k];
        }
        int vl = sum(l, r, k * 2 + 1, min, (min + max) / 2);
        int vr = sum(l, r, k * 2 + 2, (min + max) / 2, min);
        return std::min(vl, vl + vr);
    }

    void calc(int l, int r) {
        if (sum(l, r, 0, 0, offset + 1) == 0 && min(l, r, 0, 0, offset + 1) >= 0) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    int offset;
    std::vector<int> mins, sums;
};


int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::string S;
    std::cin >> S;
    auto seg = Segtree(S);

    for (int i = 0; i < Q; i++) {
        int cmd, l, r;
        std::cin >> cmd >> l >> r;

        if (cmd == 1) {
            seg.swap(l - 1, r - 1);
        } else {
            seg.calc(l - 1, r - 1);
        }
    }
}
