#include <bits/stdc++.h>


int main() {
    long long int N, K;
    std::cin >> N >> K;

    std::vector<long long int> sums(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        int val;
        std::cin >> val;
        sums[i] = sums[i - 1] + val;
    }

    long long int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (sums[N] - sums[i] < K) {
            continue;
        }
        // std::cout << i << std::endl;
        long long int min = i + 1;
        long long int max = N;
        while (min <= max) {
            long long int idx = (min + max) / 2;
            int sum = sums[idx] - sums[i];
            if (sum >= K && sums[idx - 1] - sums[i] < K) {
                cnt += N - idx + 1;
                break;
            }
            if (sum >= K) {
                max = std::max(idx - 1, min);
            } else {
                min = std::min(idx + 1, max);
            }
        }
    }
    std::cout << cnt << std::endl;
}
