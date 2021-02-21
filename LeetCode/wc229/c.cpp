#include <bits/stdc++.h>


class Solution {
  public:
    int maximumScore(std::vector<int>& nums, std::vector<int>& multipliers) {
        int INF = -1e9;
        int N = multipliers.size();
        std::vector<std::vector<int>> dp(N + 1, std::vector<int>(N + 1, INF));
        dp[0][0] = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= i; j++) {
                std::cout << i << " , " << j << " , " << multipliers[i - 1] << " , ";
                if (j > 0) {
                    dp[j][i - j] =
                        std::max(dp[j][i - j], dp[j - 1][i - j] + multipliers[i - 1] * nums[j - 1]);
                    std::cout << dp[j - 1][i - j] << " , " << nums[j - 1] << " , ";
                }
                if (i - j > 0) {
                    dp[j][i - j] = std::max(
                        dp[j][i - j], dp[j][i - j - 1] + multipliers[i - 1] * nums[nums.size() - i + j]);
                    std::cout << dp[j][i - j - 1] << " , " << nums[N - i + j];
                }
                std::cout << ", " << dp[j][i - j] << std::endl;
            }
        }
        int max = INF;
        for (int i = 0; i <= N; i++) {
            std::cout << dp[i][N - i] << " ";
            max = std::max(dp[i][N - i], max);
        }
        std::cout << std::endl;
        return max;
    }
};


int main() {}
