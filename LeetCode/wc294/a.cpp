/**
 * @file a.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-22 11:27:45
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int percentageLetter(std::string s, char letter) {
        int cnt = 0;
        for (auto& c : s) {
            if (c == letter) {
                cnt++;
            }
        }
        return cnt * 100 / s.length();
    }
};

int main() {}
