#include <bits/stdc++.h>


int main() {
    int N, n;
    std::cin >> N;
    n = N;
    std::vector<int> factors;
    for (int i = 2; i <= std::sqrt(n); i++) {
        while (n % i == 0) {
            factors.emplace_back(i);
            n /= i;
        }
    }
    std::cout << N << ":";
    for (auto val : factors) {
        std::cout << " " << val;
    }
    if (n > 1) {
        std::cout << " " << n;
    }

    std::cout << std::endl;
}
