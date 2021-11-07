/*
 * a.cpp
 *
 * Create Date : 2021-11-07 11:29:26
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int countVowelSubstrings(std::string word) {
        int aidx = 0;
        int iidx = 'i' - 'a';
        int uidx = 'u' - 'a';
        int eidx = 'e' - 'a';
        int oidx = 'o' - 'a';
        int ans = 0;
        for (int i = 0; i < word.length(); i++) {
            for (int j = i + 1; j < word.length(); j++) {
                std::vector<int> cnts(26, 0);
                for (int k = i; k <= j; k++) {
                    cnts[word[k] - 'a']++;
                }
                bool flag = true;
                for (int l = 0; l < 26; l++) {
                    if (l == aidx || l == iidx || l == uidx || l == eidx || l == oidx) {
                        flag &= cnts[l] > 0;
                    } else {
                        flag &= cnts[l] == 0;
                    }
                }
                if (flag) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {}
