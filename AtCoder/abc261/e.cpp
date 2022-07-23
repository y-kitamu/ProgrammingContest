/**
 * @file e.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-07-23 21:31:52
 */
#include <bits/stdc++.h>


int main() {
    int N, C;
    std::cin >> N >> C;

    std::vector<int> T(N);
    std::vector<int> A(N);

    for (int i = 0; i < N; i++) {
        std::cin >> T[i] >> A[i];
    }

    std::vector<std::vector<std::vector<int>>> dp(
        31, std::vector<std::vector<int>>(N + 1, std::vector<int>(2, 0)));
    std::vector<int> ans(N + 1, 0);
    ans[0] = C;

    for (int i = 0; i <= 30; i++) {
        std::vector<int> dp(2);
        dp[0] = 0;
        dp[1] = 1;
        for (int j = 1; j <= N; j++) {
            int val = (A[i] >> i) & 1;
            if (T[j] == 1) {
                dp[0] = dp[0] & val;
                dp[1] = dp[1] & val;
            } else if (T[j] == 2) {
                dp[0] = dp[0] | val;
                dp[1] = dp[1] | val;
            } else {
                dp[0] = dp[0] ^ val;
                dp[1] = dp[1] ^ val;
            }

            if (dp[(ans[j - 1] >> i) & 1] > 0) {
                ans[j] |= (1 << i);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        std::cout << ans[i] << std::endl;
    }
}
