/*
 * b.cpp
 *
 * Create Date : 2021-09-05 11:35:03
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int numberOfWeakCharacters(std::vector<std::vector<int>>& properties) {
        auto index_sort = [&properties](int idx) {
            std::vector<int> indices(properties.size());
            std::iota(indices.begin(), indices.end(), 0);
            std::sort(indices.begin(), indices.end(), [&properties, &idx](auto& lhs, auto& rhs) {
                return properties[lhs][idx] < properties[rhs][idx];
            });
            return indices;
        };

        int n = properties.size();
        auto aidx = index_sort(0);
        auto didx = index_sort(1);

        int cnt = 0;
        int max_idx = n - 1;
        int max = properties[didx[max_idx]][1];
        std::vector<int> flag(n, 0);
        int i = 0;
        while (i < n) {
            flag[aidx[i]] = 1;
            while (i < n - 1 && properties[aidx[i]] == properties[aidx[i + 1]]) {
                i++;
                flag[aidx[i]] = 1;
            }
            while (max_idx >= 0 && flag[didx[max_idx]] == 1) {
                max_idx--;
            }
            if (max_idx < 0) {
                break;
            }
            max = properties[didx[max_idx]][1];
            if (properties[aidx[i]][1] < max) {
                cnt++;
            }
            i++;
        }

        return cnt;
    }
};


int main() {}
