/*
 * c.cpp
 *
 * Create Date : 2022-03-27 11:38:45
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    std::vector<long long> kthPalindrome(std::vector<int>& queries, int intLength) {
        if (intLength == 1) {
            std::vector<long long> ans;
            for (auto& val : queries) {
                if (val < 10) {
                    ans.emplace_back(val);
                } else {
                    ans.emplace_back(-1);
                }
            }
            return ans;
        } else if (intLength == 2) {
            std::vector<long long> ans;
            for (auto& val : queries) {
                if (val < 10) {
                    ans.emplace_back(val * 10 + val);
                } else {
                    ans.emplace_back(-1);
                }
            }
            return ans;
        }

        int n_pair = (intLength + 1) / 2;
        std::vector<std::vector<int>> map(n_pair, std::vector<int>(10, 0));

        for (int i = 0; i < 10; i++) {
            map[0][i] = i + 1;
        }

        for (int j = 1; j < n_pair; j++) {
            int min_i = 0;
            if (j == n_pair - 1) {
                min_i = 1;
            }
            for (int i = min_i; i < 10; i++) {
                map[j][i] += map[j - 1][9];
                if (i > 0) {
                    map[j][i] += map[j][i - 1];
                }
            }
        }

        std::vector<long long> pow10(intLength, 1);
        for (int i = 1; i < intLength; i++) {
            pow10[i] = pow10[i - 1] * 10ll;
        }
        std::vector<long long> ans(queries.size(), 0);
        for (int k = 0; k < queries.size(); k++) {
            int val = queries[k];
            std::vector<int> vals;
            for (int j = n_pair - 1; j >= 0; j--) {
                for (int i = 0; i < 10; i++) {
                    if (val <= map[j][i]) {
                        vals.emplace_back(i);
                        if (i > 0) {
                            val -= map[j][i - 1];
                        }
                        break;
                    }
                }
            }
            if (vals.size() == 0) {
                ans[k] = -1;
                continue;
            }
            for (int i = 0; i < n_pair; i++) {
                int max_pow = intLength - i - 1;
                ans[k] += vals[i] * pow10[i];
                if (max_pow != i) {
                    ans[k] += vals[i] * pow10[max_pow];
                }
            }
        }
        return ans;
    }
};

int main() {}
