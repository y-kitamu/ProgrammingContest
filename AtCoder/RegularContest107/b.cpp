#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;

    auto count = [&N] (long long int val) {
        if (val <= N + 1)  {
            return val - 1;
        }
        long long int min_val = val - N;
        return N - (min_val - 1);
    };

    long long int sum = 0;
    for (int x = std::max(2, 2 + K); x <=std::min(2 * N, 2 * N + K); x++) {
        int y = x - K;
        sum += count(x) * count(y);
    }
    std::cout << sum << std::endl;
}
