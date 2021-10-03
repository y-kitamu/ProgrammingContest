/*
 * c.cpp
 *
 * Create Date : 2021-10-03 11:42:47
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    bool stoneGameIX(std::vector<int>& stones) {
        std::vector<int> cnts(3, 0);
        for (auto& val : stones) {
            cnts[val % 3]++;
        }
        if (cnts[1] == 0 && cnts[2] == 0) {
            return false;
        }

        bool flag = false;
        int cur = (cnts[0] + 1) % 2;
        if (cnts[1] > 0) {
            flag |= solve(cur, 1, cnts[1] - 1, cnts[2]);
        }
        if (cnts[2] > 0) {
            flag |= solve(cur, 2, cnts[1], cnts[2] - 1);
        }
        return flag;
    }

    bool solve(int cur, int sum, int res1, int res2) {
        while (res1 > 0 || res2 > 0) {
            cur = 1 - cur;
            if (res1 == 0) {
                sum = (sum + 2) % 3;
                res2--;
            } else if (res2 == 0) {
                sum = (sum + 1) % 3;
                res1--;
            } else {
                if (sum == 1) {
                    sum = 2;
                    res1--;
                } else if (sum == 2) {
                    sum = 1;
                    res2--;
                }
            }
            if (sum == 0) {
                // std::cout << "sum = " << sum << ", cur = " << cur << std::endl;
                return cur == 1;
            }
        }
        return false;
    }
};

int main() {}
