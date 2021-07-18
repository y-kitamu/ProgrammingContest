/*
 * a.cpp
 *
 * Create Date : 2021-07-18 11:28:20
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int canBeTypedWords(std::string text, std::string brokenLetters) {
        std::vector<bool> cnt(26, true);
        for (auto& c : brokenLetters) {
            cnt[c - 'a'] = false;
        }

        int res = 0;
        bool ok = true;
        for (auto& c : text) {
            if (c == ' ') {
                if (ok) {
                    res++;
                }
                ok = true;
            } else {
                ok &= cnt[c - 'a'];
            }
        }
        if (ok) {
            res++;
        }
        return res;
    }
};


int main() {}
