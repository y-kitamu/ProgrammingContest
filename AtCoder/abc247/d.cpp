/*
 * d.cpp
 *
 * Create Date : 2022-04-10 21:10:04
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int Q;
    std::cin >> Q;

    std::vector<std::pair<long long int, long long int>> cyl;
    int cur = 0;
    for (int i = 0; i < Q; i++) {
        int cmd;
        std::cin >> cmd;
        if (cmd == 1) {
            int val, num;
            std::cin >> val >> num;
            cyl.emplace_back(std::make_pair(val, num));
        } else {
            long long int num;
            std::cin >> num;

            long long int ans = 0;
            while (num > 0) {
                long long int c = std::min(num, cyl[cur].second);
                cyl[cur].second -= c;
                num -= c;
                ans += c * cyl[cur].first;
                if (cyl[cur].second == 0) {
                    cur++;
                }
            }
            std::cout << ans << std::endl;
        }
    }
}
