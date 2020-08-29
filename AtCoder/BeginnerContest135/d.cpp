#include <bits/stdc++.h>

int main() {
    std::string S;
    std::cin >> S;

    int size = S.length();
    std::vector<long long int> mods(size, 1);
    for (long long int i = 1; i < size; i++) {
        mods[i] = (mods[i - 1] * 10) % 13;
    }

    long long int mod = 0;
    std::vector<long long int> count(13, 0);
    for (int i = 0; i < size; i++) {
        if (S[i] == '?') {
            count[mods[size - i - 1]]++;
            continue;
        }
        int factor = int(S[i] - '0');
        mod = (mod + mods[size - i - 1] * factor) % 13;
    }

    long long int MAX = 1000000007;
    std::vector<std::vector<long long int>> dp(14, std::vector<long long int>(13, 0));
    dp[0][mod] = 1;
    for (long long int i = 1; i <= 13; i++) {
        if (count[i - 1] == 0) {
            for (int j = 0; j < 13; j++) {
                dp[i][j] = dp[i - 1][j];
            }
            continue;
        }
        long long int n = 10 * count[i - 1] / 13;
        std::vector<long long int> nums(13, n);
        for (int j = 0; j < (10 * count[i - 1]) % 13; j++) {
            int m = ((i - 1) * j) % 13;
            nums[m]++;
        }
        for (int j = 0; j < 13; j++) {
            long long int factor = dp[i - 1][j];
            for (int k = 0; k < 13; k++) {
                long long int idx = (j + k) % 13;
                dp[i][idx] = (dp[i][idx] + factor * nums[k]) % MAX;
            }
        }
    }
    std::cout << dp[13][5] << std::endl;
}
