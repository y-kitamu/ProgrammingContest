/*
 * b.cpp
 *
 * Create Date : 2022-02-05 21:02:07
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int n;
    std::cin >> n;
    std::vector<int> A(n);

    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    int offset = 0;
    std::set<int> vals{0};

    for (int i = 0; i < n; i++) {
        offset = (A[i] + offset) % 360;
        vals.insert(offset);
    }

    std::vector<int> vec(vals.begin(), vals.end());
    int max = 360 - vec[vec.size() - 1];
    for (int i = 1; i < vec.size(); i++) {
        max = std::max(max, vec[i] - vec[i - 1]);
    }
    std::cout << max << std::endl;
}
