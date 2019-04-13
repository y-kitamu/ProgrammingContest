#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;

    int coin = 0;

    for (int i = 0; i < 2; i++) {
        if (A > B) {
            coin += A;
            A--;
        } else {
            coin += B;
            B--;
        }
    }
    std::cout << coin << std::endl;
}
