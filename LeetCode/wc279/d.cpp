/*
 * d.cpp
 *
 * Create Date : 2022-02-06 12:02:17
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int minimumTime(std::string s) {
        std::vector<int> lcs(s.length() + 1, 0), rcs(s.length() + 1, 0);

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                lcs[i + 1] = std::min(lcs[i] + 2, i + 1);
            } else {
                lcs[i + 1] = lcs[i];
            }
        }

        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '1') {
                rcs[i] = std::min(rcs[i + 1] + 2, int(s.length()) - i);
            } else {
                rcs[i] = rcs[i + 1];
            }
        }

        int ans = lcs[0] + rcs[0];
        for (int i = 1; i <= s.length(); i++) {
            std::cout << lcs[i] << ", " << rcs[i] << std::endl;
            ans = std::min(ans, lcs[i] + rcs[i]);
        }

        return ans;
    }
};


int main() {}
