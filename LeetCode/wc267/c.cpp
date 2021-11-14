/*
 * c.cpp
 *
 * Create Date : 2021-11-14 11:49:02
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::string decodeCiphertext(std::string encodedText, int rows) {
        int len = encodedText.length();
        if (len == 0) {
            return "";
        }
        int cols = len / rows;
        std::string ans(1e6, ' ');
        int max = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int idx = i * cols + j;
                int c = encodedText[idx];
                if (c == ' ') {
                    continue;
                }
                int oidx = (j - i) * rows + i;
                if (oidx < 0) {
                    continue;
                }
                ans[oidx] = c;
                max = std::max(oidx, max);
            }
        }
        return ans.substr(0, max + 1);
    }
};


int main() {}
