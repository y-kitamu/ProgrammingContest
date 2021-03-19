#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;

    std::vector<std::vector<long long int>> dp(10, std::vector<long long int>(10, 0));
    for (int i = 1; i <= N; i++) {
        auto str = std::to_string(i);
        int first = str[0] - '0';
        int last = str[str.size() - 1] - '0';
        dp[first][last]++;
    }

    long long int cnt = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cnt += dp[i][j] * dp[j][i];
        }
    }
    std::cout << cnt << std::endl;
}
