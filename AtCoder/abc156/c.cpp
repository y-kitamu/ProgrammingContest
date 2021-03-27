#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> x(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> x[i];
        sum += x[i];
    }

    int val = sum / N;
    int max = 1e9;
    for (int i = -1; i <= 1; i++) {
        int cpt = val + i;
        int cost = 0;
        for (auto& pt : x) {
            cost += (pt - cpt) * (pt - cpt);
        }
        max = std::min(cost, max);
    }

    std::cout << max << std::endl;
}
