#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;

    int max = (N - 1) * (N - 2) / 2;
    if (K > max) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::cout << (N - 1) + max - K << std::endl;;
    for (int i = 1; i < N; i++) {
        std::cout << 1 << " " << i + 1 << std::endl;
    }

    int cnt = 0;
    for (int j = 1; j < N - 1; j++) {
        for (int k = j + 1; k < N; k++) {
            if (cnt == max - K) {
                return 0;
            }
            std::cout << j + 1 << " " << k + 1 << std::endl;
            cnt++;
        }
    }
    return 0;
}
