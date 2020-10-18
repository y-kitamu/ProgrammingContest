#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;
    long long int max = std::sqrt(N + 1);
    std::vector<long long int> vec;
    for (long long int i = 1; i <= max; i++) {
        if (N % i == 0) {
            std::cout << i << std::endl;
            if (N / i != i) {
                vec.emplace_back(N / i);
            }
        }
    }
    for (long long int i = vec.size() - 1; i >= 0; i--) {
        std::cout << vec[i] << std::endl;
    }
}
