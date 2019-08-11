#include <iostream>


int main() {
    int A, B;
    std::cin >> A >> B;
    std::cout <<  std::max(std::max(A + B, A - B), A * B) << std::endl;;
}
