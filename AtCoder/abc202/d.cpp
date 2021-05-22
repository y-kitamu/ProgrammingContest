#include <bits/stdc++.h>


std::vector<std::vector<long long int>> calc_mode(int N) {
    std::vector<std::vector<long long int>> dp(N + 1, std::vector<long long int>(N + 1, 0));
    for (int i = 1; i <= N; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            // std::cout << dp[i][j] << " ";
        }
        // std::cout << std::endl;
    }
    return dp;
}


int main() {
    long long int A, B, K;
    std::cin >> A >> B >> K;

    auto dp = calc_mode(A + B);

    long long int res = K - 1;
    std::string out = "";
    int res_a = A, res_b = B;
    while (res_a > 0 || res_b > 0) {
        if (res_a == 0) {
            out += 'b';
            res_b--;
            continue;
        }
        if (res_b == 0) {
            out += 'a';
            res_a--;
            continue;
        }

        long long int val = dp[res_a + res_b - 1][res_a - 1];
        // std::cout << res_a + res_b - 1 << " , " << res_a - 1 << ", " << val << std::endl;
        // std::cout << res << " , " << val << " , " << res_a << std::endl;
        if (val <= res) {
            out += 'b';
            res -= val;
            res_b--;
        } else {
            out += 'a';
            res_a--;
        }
    }
    std::cout << out << std::endl;
}
