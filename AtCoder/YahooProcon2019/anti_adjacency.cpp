#include <iostream>

int main() {
    int N, K;

    std::cin >> N >> K;

    if (K * 2 - 1 <= N) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}
