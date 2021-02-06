#include <bits/stdc++.h>


constexpr int NG = (int)1e9;


int main() {
    int N, W;
    std::cin >> N >> W;

    std::vector<int> vs(N), ws(N), ms(N);

    for (int i = 0; i < N; i++) {
        std::cin >> vs[i] >> ws[i] >> ms[i];
    }

    std::vector<int> dp(W + 1, NG);
    dp[0] = 0;

    std::vector<int> deq(W + 1), deqv(W + 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < ws[i]; j++) {
            int s = 0, t = 0;
            for (int k = 0; ws[i] * k + j <= W; k++) {
                if (dp[ws[i] * k + j] != NG) {
                    int val = dp[ws[i] * k + j] - vs[i] * k;
                    while (s < t && val > deqv[t - 1]) {
                        t--;
                    }
                    deq[t] = k;
                    deqv[t] = val;
                    t++;
                }
                if (s < t) {
                    dp[ws[i] * k + j] = deqv[s] + vs[i] * k;
                    if (deq[s] == k - ms[i]) {
                        s++;
                    }
                }
            }
        }
        // for (int i = 0; i <= W; i++) {
        //     std::cout << dp[i] << " ";
        // }
        // std::cout << std::endl;
    }

    int max = 0;
    for (int i = 0; i <= W; i++) {
        if (dp[i] != NG) {
            max = std::max(max, dp[i]);
        }
    }
    std::cout << max << std::endl;
}
