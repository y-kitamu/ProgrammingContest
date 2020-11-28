#include <bits/stdc++.h>


int main() {
    long long int N, K;
    std::cin >> N >> K;

    std::vector<long long int> jueries(N);
    for (long long int i = 0; i < N; i++) {
        std::cin >> jueries[i];
    }

    long long int max = std::min(K, N);
    long long int sum_max = 0;
    for (long long int i = 0; i <= max; i++) {
        for (long long int j = 0; j < max - i; j++) {
            std::vector<long long int> hold;
            hold.insert(hold.end(), jueries.begin(), jueries.begin() + i);
            hold.insert(hold.end(), jueries.end() - j, jueries.end());
            std::sort(hold.begin(), hold.end(), [](auto &lhs, auto &rhs) { return lhs < rhs; });
            long long int sum = std::accumulate(hold.begin(), hold.end(), 0);
            long long int num = hold.size();
            for (long long int k = 0; k < std::min(num, K - num); k++) {
                if (hold[k] >= 0) {
                    break;
                }
                sum -= hold[k];
            }
            sum_max = std::max(sum, sum_max);
        }
    }
    std::cout << sum_max << std::endl;
}
