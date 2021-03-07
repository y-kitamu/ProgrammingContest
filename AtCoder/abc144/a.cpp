#include <bits/stdc++.h>


int main() {
    int A, B;
    std::cin >> A >> B;
    if (A < 10 && B < 10) {
        std::cout << A * B << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
}
