#include <iostream>


int main() {
    int N, M;
    std::cin >> N >> M;

    if (N % 2 == 0) {
        for (int i = 1; i <= M; i++) {
            if ((N - i - i) >= i + i) {
                std::cout << i << " " << N - i + 1 << std::endl;
            } else {
                std::cout << i << " " << N - i << std::endl;
            }
        }
    } else {
        for (int i = 1; i <= M; i++) {
            std::cout << i << " " << N - i << std::endl;
        }
    }
}
