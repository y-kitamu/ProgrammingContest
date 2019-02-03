#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> X(M);

    for (int i = 0; i < M; i++) {
        std::cin >> X[i];
    }

    if (N >= M) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::sort(X.begin(), X.end(), [](const auto &lhs, const auto &rhs) { return lhs < rhs; });

    std::vector<int> reg(M - 1);
    for (int i = 0; i < M - 1; i++) {
        reg[i] = X[i + 1] - X[i];
    }

    std::sort(reg.begin(), reg.end(), [](const auto &lhs, const auto &rhs) { return lhs > rhs; });

    int move_cnt = X[M - 1] - X[0];
    for (int i = 0; i < N - 1; i++) {
        move_cnt -= reg[i];
    }

    std::cout << move_cnt << std::endl;

    return 0;
}
