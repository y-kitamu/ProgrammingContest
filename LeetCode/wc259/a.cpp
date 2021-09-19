/*
 * a.cpp
 *
 * Create Date : 2021-09-19 11:30:38
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int finalValueAfterOperations(std::vector<std::string>& operations) {
        int val = 0;
        for (auto& op : operations) {
            if (op[1] == '-') {
                val--;
            } else {
                val++;
            }
        }
        return val;
    }
};

int main() {}
