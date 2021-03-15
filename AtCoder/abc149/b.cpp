#include <bits/stdc++.h>


int main() {
    long long int A, B, K;
    std::cin >> A >> B >> K;

    if (K <= A) {
        std::cout << A - K << " " << B << std::endl;
    } else if (K <= A + B) {
        std::cout << 0 << " " << A + B - K << std::endl;
    } else {
        std::cout << 0 << " " << 0 << std::endl;
    }
}
