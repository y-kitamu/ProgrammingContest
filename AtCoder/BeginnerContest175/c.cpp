#include <bits/stdc++.h>


int main() {
    long long int X, K, D;
    std::cin >> X >> K >> D;

    if (std::abs(X) / D >= K) {
        std::cout << std::abs(X) - D * K << std::endl;
        return 0;
    }

    long long int count = std::abs(X) / D;
    long long int res = K - count;
    if (res % 2 == 0) {
        std::cout << std::abs(X) - D * count << std::endl;
    } else {
        std::cout << -std::abs(X) + D * (count + 1) << std::endl;
    }
}
