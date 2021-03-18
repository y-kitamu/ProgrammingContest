#include <bits/stdc++.h>


int main() {
    int N, K, M;
    std::cin >> N >> K >> M;

    int goal = M * N;
    for (int i = 0; i < N - 1; i++) {
        int a;
        std::cin >> a;
        goal -= a;
    }

    if (goal > K) {
        std::cout << -1 << std::endl;
    } else if (goal < 0) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << goal << std::endl;
    }
}
