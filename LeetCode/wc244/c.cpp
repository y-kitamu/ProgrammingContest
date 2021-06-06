/*
 * c.cpp
 *
 * Create Date : 2021-06-06 11:41:54
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int minFlips(std::string s) {
        int n = s.length();
        std::vector<int> odd(2, 0), even(2, 0);

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                even[s[i] - '0']++;
            } else {
                odd[s[i] - '0']++;
            }
        }

        int min = n;
        for (int i = 0; i < n; i++) {
            if ((odd[1] == 0 && even[0] == 0) || (odd[0] == 0 && even[1] == 0)) {
                return 0;
            }

            min = std::min(min, count_min(odd, even));

            std::swap(odd, even);
            if ((n - 1) % 2 == 0) {
                odd[s[i] - '0']--;
                even[s[i] - '0']++;
            }

            std::cout << odd[0] << " , " << odd[1] << " , " << even[0] << " , " << even[1] << std::endl;
        }
        return min;
    }

    int count_min(std::vector<int>& odd, std::vector<int>& even) {
        return std::min(odd[0] + even[1], odd[1] + even[0]);
    }
};

int main() {}
