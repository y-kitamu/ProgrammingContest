/**
 * @file c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-19 11:46:26
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int longestSubsequence(std::string s, int k) {
        std::vector<long long int> dp(s.length() + 1, -1);
        dp[0] = 0;
        for (int i = 0; i < s.length(); i++) {
            std::vector<long long int> next(s.length() + 1, 0);
            for (int j = 1; j <= s.length(); j++) {
                if (dp[j - 1] >= 0) {
                    next[j] = (dp[j - 1] << 1) + (int)(s[i] - '0');
                    if (dp[j] >= 0) {
                        next[j] = std::min(next[j], dp[j]);
                    }
                    if (next[j] > k) {
                        next[j] = -1;
                    }
                } else {
                    next[j] = dp[j];
                }
            }
            // for (auto& val : next) {
            //     std::cout << val << " ";
            // }
            // std::cout << std::endl;
            dp = next;
        }
        for (int i = s.length(); i >= 0; i--) {
            if (dp[i] != -1 && dp[i] <= k) {
                return i;
            }
        }
        return 0;
    }
};

int main() {}
