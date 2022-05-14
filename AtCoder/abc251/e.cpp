/**
 * @file e.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-14 22:14:41
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<long long int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<long long int> dp(N + 1, 1e18);

    dp[0] = A[N - 1];
    dp[1] = A[N - 1] + A[0];
    for (int i = 2; i < N - 1; i++) {
        long long int cur = std::min(dp[i - 1], dp[i - 2]) + A[i - 1];
        dp[i] = std::min(dp[i], cur);
        dp[i + 1] = dp[i - 1] + A[i];
    }
    long long int ans1 = std::min(dp[N - 2], dp[N - 1]);

    std::vector<long long int> rdp(N + 1, 1e5);
    rdp[0] = A[0];
    rdp[1] = A[0];
    for (int i = 2; i < N; i++) {
        long long int cur = std::min(rdp[i - 1], rdp[i - 2]) + A[i - 1];
        rdp[i] = std::min(rdp[i], cur);
        rdp[i + 1] = rdp[i - 1] + A[i];
    }
    long long int ans2 = std::min(rdp[N - 1], rdp[N]);
    std::cout << std::min(ans1, ans2) << std::endl;
}
