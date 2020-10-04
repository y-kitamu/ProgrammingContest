#include <bits/stdc++.h>


int main() {
    std::vector<long long int> costs;
    long long int stairs = 1;
    for (int i = 0; i <= 30; i++) {
        long long int cost = stairs * (stairs + 1) / 2;
        costs.emplace_back(cost);
        stairs = stairs * 2 + 1;
    }

    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        long long int x;
        std::cin >> x;
        long long int cost = 0;
        int idx = 0;
        while (cost <= x) {
            cost += costs[idx];
            idx++;
        }
        idx--;
        std::cout << idx << std::endl;
    }
}
