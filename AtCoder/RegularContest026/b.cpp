#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;

    long long int sum = 1;
    for (long long int i = 2; i < std::sqrt(N) + 1; i++) {
        if (N % i == 0) {
            if (i == N / i) {
                sum += i;
            } else if (i < N / i) {
                sum += i + N / i;
            }
        }
    }

    if (N == 1) {
        std::cout << "Deficient" << std::endl;
    } else if (sum == N) {
        std::cout << "Perfect" << std::endl;
    } else if (sum < N) {
        std::cout << "Deficient" << std::endl;
    } else {
        std::cout << "Abundant" << std::endl;
    }
}
