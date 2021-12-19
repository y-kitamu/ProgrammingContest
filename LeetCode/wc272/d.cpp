/*
 * d.cpp
 *
 * Create Date : 2021-12-19 11:46:31
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int kIncreasing(std::vector<int>& arr, int k) {
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            std::vector<int> ops(1);
            ops[0] = arr[i];
            for (int j = i + k; j < arr.size(); j += k) {
                auto itr = std::upper_bound(ops.begin(), ops.end(), arr[j]);
                if (itr == ops.end()) {
                    ops.emplace_back(arr[j]);
                } else {
                    *itr = arr[j];
                }
                for (auto& val : ops) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;
            }
            std::cout << "i = " << i << ", cnt = " << cnt << std::endl;
            cnt += ops.size();
        }
        return arr.size() - cnt;
    }
};

int main() {}
