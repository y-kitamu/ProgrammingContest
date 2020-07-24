#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<int> sum_weights(N);

    for (int i = 0; i < N; i++) {
        int w;
        std::cin >> w;
        if (i == 0) {
            sum_weights[i] = w;
        } else {
            sum_weights[i] = sum_weights[i - 1] + w;
        }
    }

    int min_diff = sum_weights[N - 1];
    for (int i = 0; i < N - 1; i++) {
        int diff = std::abs((sum_weights[N - 1] - sum_weights[i]) - sum_weights[i]);
        min_diff = std::min(min_diff, diff);
    }
    std::cout << min_diff << std::endl;
}
