#include <bits/stdc++.h>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> counts(1e6, 0);
    for (int i = 0; i < N; i++) {
        int val;
        std::cin >> val;
        counts[val]++;
    }

    int sum = 0;
    int max = std::min(counts[0], K);
    for (int i = 0; i < counts.size(); i++) {
        if (counts[i] == 0) {
            break;
        }
        max = std::min(counts[i], max);
        sum += max;
    }
    std::cout << sum << std::endl;
}
