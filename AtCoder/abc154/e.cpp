#include <bits/stdc++.h>


long long int comb(long long int n, long long int r, std::vector<std::vector<int>>& dp) {
    if (r <= 0) {
        return 1;
    }
    if (r > n) {
        return 0;
    }
    if (dp[n - 1][r - 1] != -1) {
        return dp[n - 1][r - 1];
    }
    dp[n - 1][r - 1] = comb(n - 1, r - 1, dp) + comb(n - 1, r, dp);
    return dp[n - 1][r - 1];
}


int solve(std::string N, int K, std::vector<std::vector<int>>& dp) {
    if (N.length() < K) {
        return 0;
    }
    if (K == 0) {
        return 1;
    }

    int pow = std::pow(9, K);
    int sum = comb(N.length() - 1, K, dp) * pow;

    pow = std::pow(9, K - 1);
    sum += comb(N.length() - 1, K - 1, dp) * (N[0] - '1') * pow;

    int idx = 1;
    while (idx < N.length() && N[idx] == '0') {
        idx++;
    }
    sum += solve(N.substr(idx), K - 1, dp);
    return sum;
}


int main() {
    std::string N;
    int K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> dp(N.length(), std::vector<int>(N.length(), -1));
    for (int i = 0; i < N.length(); i++) {
        dp[i][0] = i + 1;
        dp[i][i] = 1;
    }

    int sum = solve(N, K, dp);
    std::cout << sum << std::endl;
}
