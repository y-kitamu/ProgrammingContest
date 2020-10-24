#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;
    long long int max_3 = std::log2(2e18) / std::log2(3);
    long long int max_5 = std::log2(2e18) / std::log2(5);

    for (long long int i = 1, val5 = 5; i <= max_5; i++, val5 *= 5) {
        for (long long int j = 1, val3 = 3; j <= max_3; j++, val3 *= 3) {
            if (val5 + val3 == N) {
                std::cout << j << " " << i << std::endl;
                return 0;
            }
            if (val5 + val3 > N) {
                break;
            }
        }
        if (val5 > N) {
            break;
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}
