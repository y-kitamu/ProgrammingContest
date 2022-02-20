/*
 * d.cpp
 *
 * Create Date : 2022-02-20 21:08:23
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::deque<std::pair<int, int>> deq;
    int cnt = 0;
    std::vector<int> ans(N);
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;

        if (deq.size() == 0) {
            deq.push_back(std::make_pair(a, 1));
            cnt++;
        } else {
            auto top = deq.back();
            if (top.first == a) {
                deq.pop_back();
                if (top.second + 1 == a) {
                    cnt -= (a - 1);
                } else {
                    deq.push_back(std::make_pair(a, top.second + 1));
                    cnt++;
                }
            } else {
                deq.push_back(std::make_pair(a, 1));
                cnt++;
            }
        }
        ans[i] = cnt;
    }

    for (auto& val : ans) {
        std::cout << val << std::endl;
    }
}
