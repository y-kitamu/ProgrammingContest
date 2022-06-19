/**
 * @file a.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-19 11:28:47
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::string greatestLetter(std::string s) {
        std::string max = "";
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            char C = 'A' + i;
            if (s.find(c) == std::string::npos) {
                continue;
            }
            if (s.find(C) == std::string::npos) {
                continue;
            }
            max = C;
        }
        return max;
    }
};

int main() {}
