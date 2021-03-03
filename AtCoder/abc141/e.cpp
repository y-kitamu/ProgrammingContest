#include <bits/stdc++.h>


int main() {
    int N;
    std::string S;
    std::cin >> N >> S;

    std::vector<std::vector<int>> dp(N, std::vector<int>(N, 0));

    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (S[i] == S[j]) {
                if (i == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = std::min(dp[i - 1][j - 1] + 1, j - i);
                    max = std::max(dp[i][j], max);
                }
            }
        }
    }
    std::cout << max << std::endl;
}
