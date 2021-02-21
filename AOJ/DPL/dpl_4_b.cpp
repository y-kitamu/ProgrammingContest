#include <bits/stdc++.h>


int main() {
    long long int N, K, L, R;
    std::cin >> N >> K >> L >> R;

    std::vector<long long int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    int half = N / 2;
    std::vector<std::vector<long long int>> dp(half + 1);
    for (int S = 0; S < 1 << half; S++) {
        int cnt = 0;
        long long int sum = 0;
        for (int i = 0; i < half; i++) {
            if (S >> i & 1) {
                cnt++;
                sum += a[i];
            }
        }
        dp[cnt].emplace_back(sum);
    }

    for (auto& row : dp) {
        // for (auto val : row) {
        //     std::cout << val << " , ";
        // }
        // std::cout << std::endl;
        std::sort(row.begin(), row.end());
    }

    long long int count = 0;
    int rest = N - half;
    for (int S = 0; S < 1 << rest; S++) {
        int cnt = 0;
        long long int sum = 0;
        for (int i = 0; i < rest; i++) {
            if (S >> i & 1) {
                cnt++;
                sum += a[half + i];
            }
        }
        if (0 <= K - cnt && K - cnt <= half) {
            // std::cout << S << " , " << cnt << " , " << sum << " , " << L - sum << " to " << R - sum
            //           << std::endl;
            auto low = std::lower_bound(dp[K - cnt].begin(), dp[K - cnt].end(), L - sum);
            auto high = std::upper_bound(dp[K - cnt].begin(), dp[K - cnt].end(), R - sum);
            count += high - low;
        }
    }

    std::cout << count << std::endl;
}
