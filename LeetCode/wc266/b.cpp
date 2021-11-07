/*
 * b.cpp
 *
 * Create Date : 2021-11-07 11:38:50
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    long long countVowels(std::string word) {
        long long int n = word.length();
        long long int sum = 0;
        for (long long int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
                sum += (i + 1) * (n - i);
            }
        }
        return sum;
    }
};

int main() {}
