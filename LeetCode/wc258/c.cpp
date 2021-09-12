/*
 * c.cpp
 *
 * Create Date : 2021-09-12 11:41:56
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int maxProduct(std::string s) {
        int n = s.length();
        int max = 0;
        for (int i = 0; i < (1 << n); i++) {
            int n0 = palindromic(i, s, true);
            if (n0 == 0) {
                continue;
            }
            for (int j = 0; j < (1 << n); j++) {
                if ((i & j) > 0) {
                    continue;
                }
                max = std::max(palindromic(j, s) * n0, max);
            }
        }
        return max;
    }

    int palindromic(int i, std::string s, bool debug = false) {
        int n = s.length();
        std::string sub0 = "";
        for (int x = 0; x < n; x++) {
            if (i & (1 << x)) {
                sub0 += s[x];
            }
        }
        int len = sub0.length();
        for (int i = 0; i < len; i++) {
            if (sub0[i] != sub0[len - i - 1]) {
                return 0;
            }
        }
        if (debug) {
            std::cout << i << " , " << sub0 << std::endl;
        }
        return len;
    }
};

int main() {}
