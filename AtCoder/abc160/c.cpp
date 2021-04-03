#include <bits/stdc++.h>


int main() {
    int K, N;
    std::cin >> K >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int max = A[0] + K - A[N - 1];
    for (int i = 0; i < N - 1; i++) {
        max = std::max(A[i + 1] - A[i], max);
    }
    std::cout << K - max << std::endl;
}
