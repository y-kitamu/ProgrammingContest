/*
 * e.cpp
 *
 * Create Date : 2021-11-13 21:45:09
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

long long int combi(long long int n, long long int r) {
    long long int num = 1;
    long long int den = 1;
    for (int i = 0; i < r; i++) {
        num *= (n - i);
        den *= (i + 1);
    }
    return num / den;
}


int main() {
    std::string S;
    int K;
    std::cin >> S >> K;

    int n = S.length();
    if (n * n < K) {
        std::vector<int> map(3);
        for (auto& c : S) {
            if (c == 'K') {
                map[0]++;
            } else if (c == 'E') {
                map[1]++;
            } else if (c == 'Y') {
                map[2]++;
            }
        }
        std::sort(map.begin(), map.end());
        long long int ans = combi(n, map[0]);
        ans *= combi(n - map[0], map[1]);
        std::cout << ans << std::endl;
        return 0;
    }
}
