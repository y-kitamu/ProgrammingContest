#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    long long int u, v;
    long long int sum = 0;
    for (int i = 0; i < N - 1; i++) {
        std::cin >> u >> v;
        sum += std::min(u, v) * (N - std::max(u, v) + 1);
    }

    long long int res = 0;
    for (long long int i = 1; i <= N; i++) {
        res += (i + 1) * i / 2;
    }
    std::cout << res - sum << std::endl;
}
