/*
 * a.cpp
 *
 * Create Date : 2021-09-12 11:28:24
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    std::string reversePrefix(std::string word, char ch) {
        int i = 0;
        for (; i < word.length(); i++) {
            if (word[i] == ch) {
                break;
            }
        }
        if (i == word.length()) {
            return word;
        }
        std::string ans = word;
        for (int j = i; j >= 0; j--) {
            ans[i - j] = word[j];
        }
        return ans;
    }
};


int main() {}
