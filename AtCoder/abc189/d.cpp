#include <bits/stdc++.h>

long long int search(long long int idx, long long int val, std::vector<std::vector<long long int>>& dp,
                     std::vector<std::string>& s) {
    if (dp[idx][val] != -1) {
        return dp[idx][val];
    }
    if (s[idx - 1] == "AND") {
        if (val == 0) {
            dp[idx][val] = search(idx - 1, 0, dp, s);
        } else {
            dp[idx][val] = search(idx - 1, 1, dp, s) * 2 + search(idx - 1, 0, dp, s);
        }
    } else {
        if (val == 0) {
            dp[idx][val] = search(idx - 1, 0, dp, s) * 2 + search(idx - 1, 1, dp, s);
        } else {
            dp[idx][val] = search(idx - 1, 1, dp, s);
        }
    }
    return dp[idx][val];
}


int main() {
    long long int N;
    std::cin >> N;

    std::vector<std::string> s(N);
    for (long long int i = 0; i < N; i++) {
        std::cin >> s[i];
    }

    std::vector<std::vector<long long int>> dp(
        N + 1, std::vector<long long int>(2, -1));  // 0 = true, 1 = false
    dp[0][0] = 1;
    dp[0][1] = 1;
    std::cout << search(N, 0, dp, s) << std::endl;
}
