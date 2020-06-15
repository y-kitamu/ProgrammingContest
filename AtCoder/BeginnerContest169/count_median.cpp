#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];
    }

    std::sort(A.begin(), A.end(), [](auto &lhs, auto &rhs) { return lhs < rhs; });
    std::sort(B.begin(), B.end(), [](auto &lhs, auto &rhs) { return lhs > rhs; });

    if (N % 2 == 0) {
        int idx0 = N / 2 - 1;
        int idx1 = idx0 + 1;
        std::cout << ((B[idx0] + B[idx1]) - (A[idx0] + A[idx1])) + 1 << std::endl;
    } else {
        int idx = (N - 1) / 2;
        std::cout << (B[idx] - A[idx]) + 1 << std::endl;
    }
}
