/*
 * c.cpp
 *
 * Create Date : 2021-08-08 21:09:19
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int H, W, N;
    std::cin >> H >> W >> N;

    std::map<int, std::vector<int>> A, B;
    std::set<int> seta, setb;
    for (int i = 0; i < N; i++) {
        int a, b;
        std::cin >> a >> b;
        A[a].emplace_back(i);
        B[b].emplace_back(i);
        seta.insert(a);
        setb.insert(b);
    }

    std::vector<int> ansa(N), ansb(N);
    int i = 0;
    for (auto itr = seta.begin(); itr != seta.end(); itr++, i++) {
        auto val = *itr;
        for (auto& idx : A[val]) {
            ansa[idx] = i;
        }
    }
    i = 0;
    for (auto itr = setb.begin(); itr != setb.end(); itr++, i++) {
        auto val = *itr;
        for (auto& idx : B[val]) {
            ansb[idx] = i;
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << ansa[i] + 1 << " " << ansb[i] + 1 << std::endl;
    }
}
