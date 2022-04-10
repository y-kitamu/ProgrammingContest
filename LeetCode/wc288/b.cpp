/*
 * b.cpp
 *
 * Create Date : 2022-04-10 11:41:35
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::string minimizeResult(std::string expression) {
        int pidx = -1;
        for (int i = 0; i < expression.length(); i++) {
            if (expression[i] == '+') {
                pidx = i;
                break;
            }
        }

        int min_val = 1e9;
        std::string ans;
        for (int li = 0; li < pidx; li++) {
            int llval = 0;
            int lmval = 0;
            for (int i = 0; i < li; i++) {
                llval = llval * 10 + (int)(expression[i] - '0');
            }
            for (int i = li; i < pidx; i++) {
                lmval = lmval * 10 + (int)(expression[i] - '0');
            }
            if (li == 0) {
                llval = 1;
            }

            for (int ri = pidx + 2; ri <= expression.length(); ri++) {
                int rmval = 0;
                int rrval = 0;
                for (int i = pidx + 1; i < ri; i++) {
                    rmval = rmval * 10 + (int)(expression[i] - '0');
                }
                for (int i = ri; i < expression.length(); i++) {
                    rrval = rrval * 10 + (int)(expression[i] - '0');
                }
                if (ri == expression.length()) {
                    rrval = 1;
                }
                int val = llval * (lmval + rmval) * rrval;
                if (val < min_val) {
                    min_val = val;
                    ans = "";
                    for (int i = 0; i < li; i++) {
                        ans += expression[i];
                    }
                    ans += '(';
                    for (int i = li; i < ri; i++) {
                        ans += expression[i];
                    }
                    ans += ')';
                    for (int i = ri; i < expression.length(); i++) {
                        ans += expression[i];
                    }
                }
            }
        }
        return ans;
    }
};


int main() {}
