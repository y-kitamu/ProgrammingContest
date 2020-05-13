#include <iostream>

int main() {
    int A, B, C, K;
    std::cin >> A >> B >> C >> K;

    if (K < A) {
        std::cout << K << std::endl;
        return 0;
    }

    K -= A;

    if (K < B) {
        std::cout << A << std::endl;
        return 0;
    }

    K -= B;

    std::cout << A - K << std::endl;
}
