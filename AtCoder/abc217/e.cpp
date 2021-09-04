/*
 * e.cpp
 *
 * Create Date : 2021-09-04 21:14:43
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int Q;
    std::cin >> Q;

    std::vector<int> buf(Q);
    int min = 0, cur = 0;
    std::multiset<int> set;
    for (int i = 0; i < Q; i++) {
        int cmd;
        std::cin >> cmd;

        if (cmd == 1) {
            int val;
            std::cin >> val;
            buf[cur] = val;
            cur++;
        } else if (cmd == 2) {
            if (set.size() > 0) {
                std::cout << *set.begin() << std::endl;
                set.erase(set.begin());
            } else {
                std::cout << buf[min] << std::endl;
                min++;
            }
        } else {
            for (int i = min; i < cur; i++) {
                set.insert(buf[i]);
            }
            min = cur;
        }
    }
}
