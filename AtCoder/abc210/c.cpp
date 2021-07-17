/*
 * c.cpp
 *
 * Create Date : 2021-07-17 21:05:15
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> cs(N);
    for (int i = 0; i < N; i++) {
        std::cin >> cs[i];
    }

    int max = 0;
    std::map<int, int> cnts;
    for (int i = 0; i < K; i++) {
        int val = cs[i];
        if (cnts.find(val) == cnts.end()) {
            cnts[val] = 0;
            max++;
        }
        cnts[val]++;
    }

    int res = max;
    for (int i = 0; i < N - K; i++) {
        cnts[cs[i]]--;
        if (cnts[cs[i]] == 0) {
            max--;
        }

        if (cnts.find(cs[i + K]) == cnts.end()) {
            cnts[cs[i + K]] = 0;
        }
        cnts[cs[i + K]]++;
        if (cnts[cs[i + K]] == 1) {
            max++;
        }
        res = std::max(res, max);
        // std::cout << max << std::endl;
    }

    std::cout << res << std::endl;
}
