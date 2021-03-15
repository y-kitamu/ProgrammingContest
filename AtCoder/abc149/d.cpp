#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;
    int R, S, P;
    std::cin >> R >> S >> P;
    std::string T;
    std::cin >> T;

    std::vector<int> vals(N);
    for (int i = 0; i < N; i++) {
        switch (T[i]) {
            case 'r':
                vals[i] = 2;
                break;
            case 's':
                vals[i] = 0;
                break;
            case 'p':
                vals[i] = 1;
                break;
        }
    }

    int sum = 0;
    for (int i = 0; i < K; i++) {
        std::vector<int> dp(3, 0);
        switch (vals[i]) {
            case 0:
                dp[0] = R;
                break;
            case 1:
                dp[1] = S;
                break;
            case 2:
                dp[2] = P;
                break;
        }

        for (int j = i + K; j < N; j += K) {
            int s0 = std::max(dp[1], dp[2]);
            int s1 = std::max(dp[0], dp[2]);
            int s2 = std::max(dp[0], dp[1]);
            dp[0] = s0;
            dp[1] = s1;
            dp[2] = s2;
            switch (vals[j]) {
                case 0:
                    dp[0] += R;
                    break;
                case 1:
                    dp[1] += S;
                    break;
                case 2:
                    dp[2] += P;
                    break;
            }
        }
        int max = std::max(std::max(dp[0], dp[1]), dp[2]);
        sum += max;
    }
    std::cout << sum << std::endl;
}
