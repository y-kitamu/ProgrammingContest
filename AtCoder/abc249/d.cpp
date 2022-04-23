/*
 * d.cpp
 *
 * Create Date : 2022-04-23 21:13:43
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;

    int max = 0;
    std::vector<long long int> cnts(2e5 + 1, 0);
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        cnts[a]++;
        max = std::max(max, a);
    }

    long long int ans = 0;
    int sqrt = std::sqrt(max + 1);
    for (int i = 1; i <= sqrt; i++) {
        ans += cnts[i * i] * cnts[i] * cnts[i];
        for (int j = i + 1; j <= max / i; j++) {
            ans += cnts[j * i] * cnts[j] * cnts[i] * 2;
        }
    }
    std::cout << ans << std::endl;
}
