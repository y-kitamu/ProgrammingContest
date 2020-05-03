#include <iostream>


int main() {
    int K, A, B;
    std::cin >> K;
    std::cin >> A >> B;

    int next = (A / K + 1) * K;
    if (A % K == 0 ) {
        std::cout << "OK" << std::endl;
    } else if (A <= next &&  next <= B) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "NG" << std::endl;
    }
}
