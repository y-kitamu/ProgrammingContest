#include <bits/stdc++.h>


int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    std::vector<std::vector<int> > dp(s2.size() + 1, std::vector<int>(s1.size() + 1, 0));

    for (int i = 1; i <= s2.size(); i++) {
        dp[i][0] = dp[i - 1][0] + 1;
    }
    for (int i = 1; i <= s1.size(); i++) {
        dp[0][i] = dp[0][i - 1] + 1;
    }

    for (int i = 1; i <= s2.size(); i++) {
        for (int j = 1; j <= s1.size(); j++) {
            dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + 1;
            dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + (s2[i - 1] != s1[j - 1]));
        }
    }
    std::cout << dp[s2.size()][s1.size()] << std::endl;
}
