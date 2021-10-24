/*
 * b.cpp
 *
 * Create Date : 2021-10-24 12:01:03
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int nextBeautifulNumber(int n) {
        std::vector<int> vals;
        for (int i = n + 1; i < 1224444; i++) {
            int val = i;
            std::vector<int> cnt(10, 0);
            while (val > 0) {
                cnt[val % 10]++;
                val /= 10;
            }
            bool flag = true;
            for (int j = 0; j < 10; j++) {
                flag &= (cnt[j] == j || cnt[j] == 0);
            }
            if (flag) {
                return i;
            }
        }
        return 1224444;
    }
};


int main() {}
