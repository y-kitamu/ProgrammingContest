#include <bits/stdc++.h>


int main() {
    int K;
    std::cin >> K;
    std::vector<std::vector<int>> dp(1e5, std::vector<int>(10, 0));

    long long int ans = 0;
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        dp[0][i] = 1;
        if (i > 0) {
            sum++;
            if (sum == K) {
                ans = i;
                std::cout << ans << std::endl;
                return 0;
            }
        }
    }

    int mi = 0, mj = 0, idx = 0;
    for (int j = 1; j < 1e5; j++) {
        for (int i = 0; i < 10; i++) {
            dp[j][i] = dp[j - 1][i];
            if (i > 0) {
                dp[j][i] += dp[j - 1][i - 1];
            }
            if (i < 9) {
                dp[j][i] += dp[j - 1][i + 1];
            }
            if (i > 0) {
                sum += dp[j][i];
            }
            if (sum >= K) {
                mi = i, mj = j;
                idx = K - (sum - dp[j][i]);
                break;
            }
        }
        if (sum >= K) {
            break;
        }
    }

    // std::cout << mi << " " << mj << " " << idx << std::endl;
    ans = mi;
    for (int j = mj - 1; j >= 0; j--) {
        ans *= 10;
        int s = 0;
        for (int i = std::max(0, mi - 1); i <= std::min(9, mi + 1); i++) {
            s += dp[j][i];
            if (s >= idx) {
                ans += i;
                mi = i;
                idx -= (s - dp[j][i]);
                break;
            }
        }
    }

    std::cout << ans << std::endl;
}
