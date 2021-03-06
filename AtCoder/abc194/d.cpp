#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;

    double sum = 0.0;
    for (int j = 1; j < N; j++) {
        sum += (N - j) / (N * std::pow((1.0 - (double)j / N), 2.0));
    }

    std::cout << std::fixed << std::setprecision(10) << sum << std::endl;
}
