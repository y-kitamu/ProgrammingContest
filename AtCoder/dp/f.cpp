/*
 * f.cpp
 *
 * Create Date : 2021-08-24 20:59:57
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::string s, t;
    std::cin >> s >> t;

    std::vector<std::vector<int>> dp(t.length() + 1, std::vector<int>(s.length() + 1, 0));

    for (int i = 0; i <= t.length(); i++) {
        for (int j = 0; j <= s.length(); j++) {
            if (i < t.length() && j < s.length()) {
                if (t[i] == s[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = dp[i][j];
                }
            }
            if (i < t.length()) {
                dp[i + 1][j] = std::max(dp[i][j], dp[i + 1][j]);
            }
            if (j < s.length()) {
                dp[i][j + 1] = std::max(dp[i][j], dp[i][j + 1]);
            }
            // std::cout << dp[i][j] << " ";
        }
        // std::cout << std::endl;
    }

    std::string ans = "";
    int i = t.length(), j = s.length();
    while (i > 0 && j > 0) {
        // std::cout << i << " , " << j << std::endl;
        if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else if (dp[i][j] == dp[i][j - 1]) {
            j--;
        } else if (dp[i][j] - dp[i - 1][j - 1] == 1) {
            ans = t[i - 1] + ans;
            i--;
            j--;
        } else {
            i--;
            j--;
        }
    }
    // std::cout << dp[t.length()][s.length()] << std::endl;
    std::cout << ans << std::endl;
}
