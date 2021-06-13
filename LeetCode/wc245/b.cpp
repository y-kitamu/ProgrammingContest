/*
 * b.cpp
 *
 * Create Date : 2021-06-13 11:33:20
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int maximumRemovals(std::string s, std::string p, std::vector<int>& removable) {
        int len = removable.size();
        int min = 0, max = len;

        while (min != max) {
            int mid = (min + max + 1) / 2;

            std::string tmp = s;
            for (int i = 0; i < mid; i++) {
                tmp[removable[i]] = '0';
            }

            int idx = 0;
            for (int i = 0; i < tmp.length(); i++) {
                if (idx == p.length()) {
                    break;
                }
                if (p[idx] == tmp[i]) {
                    idx++;
                }
            }

            if (idx == p.length()) {
                min = mid;
            } else {
                max = mid - 1;
            }
        }
        return min;
    }
};


int main() {}
