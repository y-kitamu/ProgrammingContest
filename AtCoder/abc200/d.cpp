#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);

    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] %= 200;
    }

    std::vector<std::vector<std::vector<int>>> dp(N, std::vector<std::vector<int>>(200));
    for (int i = 0; i < N; i++) {
        dp[i][A[i]].emplace_back(i);
    }

    auto print_vec = [](std::vector<int>& vec) {
        std::cout << vec.size();
        for (auto& val : vec) {
            std::cout << " " << val + 1;
        }
        std::cout << std::endl;
    };

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 200; j++) {
            if (dp[i - 1][j].size() > 0) {
                if (dp[i][j].size() > 0) {
                    std::cout << "Yes" << std::endl;
                    print_vec(dp[i][j]);
                    print_vec(dp[i - 1][j]);
                    return 0;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
                int offset = (j + A[i]) % 200;
                dp[i - 1][j].emplace_back(i);
                if (dp[i][offset].size() > 0) {
                    std::cout << "Yes" << std::endl;
                    print_vec(dp[i][offset]);
                    print_vec(dp[i - 1][j]);
                    return 0;
                } else {
                    dp[i][offset] = dp[i - 1][j];
                }
            }
        }
    }

    std::cout << "No" << std::endl;
}
