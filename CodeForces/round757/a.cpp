/*
 * a.cpp
 *
 * Create Date : 2021-11-26 20:13:47
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n, l, r, k;
        std::cin >> n >> l >> r >> k;
        std::vector<int> a(n);
        for (int j = 0; j < n; j++) {
            std::cin >> a[j];
        }
        std::sort(a.begin(), a.end());
        int ans = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] > r || a[j] > k) {
                break;
            }
            if (a[j] < l) {
                continue;
            }
            k -= a[j];
            ans++;
        }
        std::cout << ans << std::endl;
    }
}
