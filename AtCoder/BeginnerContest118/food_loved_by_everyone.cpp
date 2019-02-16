#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;

    int food[M] = {};

    for (int i = 0; i < N; i++) {
        int K;
        std::cin >> K;
        for (int j = 0; j < K; j++) {
            int val;
            std::cin >> val;
            food[val - 1]++;
        }
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        if (food[i] == N) cnt++;
    }

    std::cout << cnt << std::endl;
}
