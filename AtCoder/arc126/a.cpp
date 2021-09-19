/*
 * a.cpp
 *
 * Create Date : 2021-09-19 21:55:23
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int T;
    std::cin >> T;

    // (2, 2, 2, 2, 2), (2, 2, 3, 3), (2, 2, 2, 4), (2, 4, 4), (3, 3, 4),
    for (int i = 0; i < T; i++) {
        long long int n2, n3, n4;
        std::cin >> n2 >> n3 >> n4;
        long long int cnt334 = std::min(n3 / 2, n4);
        n3 -= cnt334 * 2;
        n4 -= cnt334;
        long long int cnt244 = std::min(n4 / 2, n2);
        n2 -= cnt244;
        n4 -= cnt244 * 2;
        long long int cnt2233 = std::min(n3 / 2, n2 / 2);
        n2 -= cnt2233 * 2;
        n3 -= cnt2233 * 2;
        long long int cnt2224 = 0;
        if (n4 > 0 && n2 >= 3) {
            cnt2224 = 1;
            n4--;
            n2 -= 3;
        }
        long long int cnt22222 = n2 / 5;

        std::cout << cnt334 + cnt244 + cnt2233 + cnt2224 + cnt22222 << std::endl;
    }
}
