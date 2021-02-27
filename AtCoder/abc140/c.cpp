#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> B(N - 1);
    for (int i = 0; i < N - 1; i++) {
        std::cin >> B[i];
    }

    int sum = B[0] + B[N - 2];
    for (int i = 1; i < N - 1; i++) {
        sum += std::min(B[i - 1], B[i]);
    }

    std::cout << sum << std::endl;
}
