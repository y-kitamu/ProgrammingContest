#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    std::vector<double> logs(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        logs[i] = std::log(A[i]);
    }

    std::sort(logs.begin(), logs.end(), [](auto lhs, auto rhs) { return lhs > rhs; });
    std::vector<int> split(N, 1);

    for (int i = 0; i < N - 1; i++) {
        int count = int(std::exp(A[i] - A[N - 1]));
    }
}
