/*
 * b.cpp
 *
 * Create Date : 2022-04-17 11:35:02
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int minimumRounds(std::vector<int>& tasks) {
        std::map<int, int> cnt;
        for (auto& val : tasks) {
            cnt[val]++;
        }

        long long int sum = 0;
        for (auto& pair : cnt) {
            int val = pair.second;
            if (val == 1) {
                return -1;
            }
            if (val % 3 == 0) {
                sum += val / 3;
            } else {
                sum += val / 3 + 1;
            }
        }
        return sum;
    }
};

int main() {}
