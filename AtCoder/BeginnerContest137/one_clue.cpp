#include <iostream>

int main() {
    int K, X;
    std::cin >> K >> X;

    for (int i = -K + 1; i < K; i++) {
        std::cout << X + i << " ";
    }
    std::cout << std::endl;
}
