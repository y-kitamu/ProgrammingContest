#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;

    long long int min = N - 1;
    long long int sq = std::sqrt(N);
    for (int i = 2; i <= sq; i++) {
        if (N % i == 0) {
            min = std::min(min, i + N / i - 2);
        }
    }
    std::cout << min << std::endl;
}
