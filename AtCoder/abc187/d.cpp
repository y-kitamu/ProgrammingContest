#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;

    long long int sum_a = 0;
    std::vector<long long int> pps(N);
    for (int i = 0; i < N; i++) {
        long long int a, b;
        std::cin >> a >> b;
        sum_a += a;
        pps[i] = a + a + b;
    }
    std::sort(pps.begin(), pps.end(), [] (auto &lhs, auto &rhs) { return lhs > rhs; });

    int idx = 0;
    while (sum_a >= 0) {
        sum_a -= pps[idx];
        idx++;
    }

    std::cout << idx << std::endl;
}
