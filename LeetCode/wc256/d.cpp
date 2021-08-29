/*
 * d.cpp
 *
 * Create Date : 2021-08-29 12:38:21
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int n;
    long long int mod = 1e9 + 7;
    std::string binary;

    int numberOfUniqueGoodSubsequences(std::string binary) {
        n = binary.length();
        this->binary = binary;
        int idx = 0;
        for (; idx < n; idx++) {
            if (binary[idx] == '1') {
                break;
            }
        }
        if (idx == n) {
            return 1;
        }
        bool flag = false;
        for (auto& c : binary) {
            flag |= c == '0';
        }
        std::vector<long long int> dp(n, -1);
        return calc(idx, dp) + (int)(flag);
    }

    long long int calc(int idx, std::vector<long long int>& dp) {
        if (idx == n) {
            return 0;
        }
        if (dp[idx] >= 0) {
            return dp[idx];
        }

        long long int cnt = 1;
        int n0 = idx + 1, n1 = idx + 1;
        for (; n0 < n; n0++) {
            if (binary[n0] == '0') {
                break;
            }
        }
        cnt += calc(n0, dp);
        for (; n1 < n; n1++) {
            if (binary[n1] == '1') {
                break;
            }
        }
        cnt += calc(n1, dp);
        dp[idx] = cnt % mod;
        return dp[idx];
    }
};


int main() {}
