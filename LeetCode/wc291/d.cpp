/**
 * @file d.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-01 11:58:21
 */
#include <bits/stdc++.h>


class Solution {
  public:
    long long appealSum(std::string s) {
        std::vector<long long> idxs(26, 0);
        std::vector<long long> sums(s.length() + 1, 0);
        for (long long i = 0; i < s.length(); i++) {
            int cur = s[i] - 'a';
            sums[i + 1] = sums[i] + i + 1ll - idxs[cur];
            if (i > 0) {
                sums[i + 1] += sums[i] - sums[i - 1];
            }
            idxs[cur] = i + 1;
            // std::cout << sums[i + 1] << std::endl;
        }
        return sums[s.length()];
    }
};

int main() {}
