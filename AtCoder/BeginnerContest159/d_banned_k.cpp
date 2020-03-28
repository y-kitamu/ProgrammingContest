/*
 * d_banned_k.cpp
 *
 * Create Date : 2020-03-28 09:34:50
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> arr(N);
    std::unordered_map<int, long long int> map;

    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
        if (map.find(arr[i]) == map.end()) {
            map[arr[i]] = 0;
        }
        map[arr[i]]++;
    }

    std::unordered_map<int, long long int> counts_in;
    long long int count = 0;
    for (auto && m: map) {
        counts_in[m.first] = m.second - 1;
        count += m.second * (m.second - 1) / 2;
    }

    for (int i = 0; i < N; i++) {
        std::cout << count - map[arr[i]] + 1 << std::endl;
    }
}
