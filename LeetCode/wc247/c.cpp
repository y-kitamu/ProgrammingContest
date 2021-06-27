/*
 * c.cpp
 *
 * Create Date : 2021-06-27 12:05:14
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    long long wonderfulSubstrings(std::string word) {
        std::vector<long long int> state(1 << 10, 0);

        uint32_t cur = 0;
        state[cur]++;
        for (int i = 0; i < word.length(); i++) {
            uint32_t idx = word[i] - 'a';
            cur ^= (1 << idx);
            state[cur]++;
        }

        long long int cnt = 0;
        for (int i = 0; i < (1 << 10); i++) {
            cnt += state[i] * state[i - 1] / 2;
        }

        long long int one_odd = 0;
        for (int i = 0; i < (1 << 10); i++) {
            for (int j = 0; j < 10; j++) {
                int idx = i ^ (1 << j);
                one_odd += state[i] * state[idx];
            }
        }
        return cnt + one_odd / 2;
    }
};

int main() {}
