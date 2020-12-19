#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<long long int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end(), [] (auto &lhs, auto& rhs) { return lhs < rhs; });

    std::vector<long long int> sums(N);
    sums[0] = A[0];
    for (int i = 1; i < N; i++) {
        sums[i] = sums[i - 1] + A[i];
    }

    long long int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += sums[N - 1] - sums[i] - (N - 1 - i) * A[i];
    }

    std::cout << sum << std::endl;
}
