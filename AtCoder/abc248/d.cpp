/*
 * d.cpp
 *
 * Create Date : 2022-04-16 21:12:09
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */

#include <bits/stdc++.h>


struct Seg {
    Seg(int N) {
        offset = 1;
        while (offset < N) {
            offset *= 2;
        }
        max = offset;
        offset--;
        seg = std::vector<std::map<int, int>>(max * 4);
    }

    void insert(int idx, int val) {
        seg[idx][val]++;
        if (idx > 0) {
            insert((idx - 1) / 2, val);
        }
    }

    int count(int idx, int l, int r, int x, int min, int max) {
        if (max <= l || r <= min) {
            return 0;
        }
        if (l <= min && max <= r) {
            return seg[idx][x];
        }

        int mid = (min + max) / 2;
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;

        int res = 0;
        if (l < mid) {
            res += count(left, l, r, x, min, mid);
        }
        if (mid < r) {
            res += count(right, l, r, x, mid, max);
        }
        return res;
    }

    int max;
    int offset;
    std::vector<std::map<int, int>> seg;
};


int main() {
    int N;
    std::cin >> N;
    auto seg = Seg(N);

    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        seg.insert(seg.offset + i, a);
    }


    int Q;
    std::cin >> Q;

    for (int i = 0; i < Q; i++) {
        int l, r, x;
        std::cin >> l >> r >> x;

        std::cout << seg.count(0, l - 1, r, x, 0, seg.max) << std::endl;
    }
}
