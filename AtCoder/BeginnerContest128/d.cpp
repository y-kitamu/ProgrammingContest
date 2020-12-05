#include <bits/stdc++.h>


int main() {
    long long int N, K;
    std::cin >> N >> K;

    std::vector<long long int> jueries(N);
    for (long long int i = 0; i < N; i++) {
        std::cin >> jueries[i];
    }

    long long int sum = 0;
    int max_draw = std::min(K, N);
    for (int i = 0; i <= max_draw; i++) {
        for (int j = 0; j <= max_draw - i; j++) {
            std::vector<long long int> hold;
            for (int k = 0; k < i; k++) {
                hold.emplace_back(jueries[k]);
            }
            for (int k = 0; k < j; k++) {
                hold.emplace_back(jueries[N - 1 - k]);
            }
            std::sort(hold.begin(), hold.end(), [] (auto &lhs, auto &rhs) { return lhs < rhs; });
            int max_back = std::min(K - (i + j), (long long int)hold.size());
            int idx = 0;
            for (; idx < max_back; idx++) {
                if (hold[idx] >= 0) {
                    break;
                }
            }
            long long int s = 0;
            for (; idx < hold.size(); idx++) {
                s += hold[idx];
            }
            sum = std::max(s, sum);
        }
    }
    std::cout << sum << std::endl;
}
