/**
 * @file a.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-01 11:27:59
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::string removeDigit(std::string number, char digit) {
        int idx = -1;
        std::string max_str;
        for (int i = 0; i < number.length(); i++) {
            if (number[i] != digit) {
                continue;
            }
            auto str = number.substr(0, i) + number.substr(i + 1);
            if (idx == -1) {
                max_str = str;
                idx = i;
            }
            if (max_str < str) {
                max_str = str;
                idx = i;
            }
        }
        return max_str;
    }
};


int main() {}
