#include <iostream>


int main() {
    int A;
    long long int B, N;
    std::cin >> A >> B >> N;

    if (B - 1 <= N) {
        std::cout << int(A * ((B - 1.0) / B)) << std::endl;
    } else {
        std::cout << int(A * (double(N) / B)) << std::endl;
    }
}
