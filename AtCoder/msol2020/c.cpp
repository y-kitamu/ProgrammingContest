#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> As(N);
    for (int i = 0; i < N; i++) {
        std::cin >> As[i];
    }

    for (int i = K; i < N; i++) {
        if (As[i - K] < As[i]) {
            std::cout << "Yes" << std::endl;;
        } else {
            std::cout << "No" << std::endl;
        }
    }
}
