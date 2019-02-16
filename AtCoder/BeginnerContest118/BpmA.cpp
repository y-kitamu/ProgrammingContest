#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;

    int res = B % A == 0 ? A + B : B - A;
    std::cout << res << std::endl;
}
