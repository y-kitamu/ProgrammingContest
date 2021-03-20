#include <bits/stdc++.h>


int main() {
    int H, N;
    std::cin >> H >> N;

    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];
    }

    std::vector<int> dp(H + 1, 1e9);
    dp[0] = 0;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < H; i++) {
            int idx = std::min(H, i + A[j]);
            dp[idx] = std::min(dp[idx], dp[i] + B[j]);
        }
    }
    std::cout << dp[H] << std::endl;
}
