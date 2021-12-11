/*
 * d.cpp
 *
 * Create Date : 2021-12-11 21:08:18
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> counts(N, 0), roots(N);
    auto find_root = [&roots](int idx) {
        std::vector<int> updates;
        while (roots[idx] != idx) {
            updates.emplace_back(idx);
            idx = roots[idx];
        }
        for (auto& i : updates) {
            roots[i] = idx;
        }
        return idx;
    };

    std::iota(roots.begin(), roots.end(), 0);

    bool ans = true;
    for (int i = 0; i < M; i++) {
        int A, B;
        std::cin >> A >> B;
        A--, B--;
        counts[A]++, counts[B]++;
        int ra = find_root(A);
        int rb = find_root(B);
        ans &= ra != rb;
        roots[rb] = ra;
    }

    for (auto& cnt : counts) {
        if (cnt > 2) {
            ans = false;
            break;
        }
    }

    if (ans) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
