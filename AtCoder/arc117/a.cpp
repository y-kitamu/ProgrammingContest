#include <bits/stdc++.h>


int main() {
    int A, B;
    std::cin >> A >> B;

    int sum = 1e6;
    for (int i = 0; i < A - 1; i++) {
        std::cout << i + 1 << " ";
        sum -= i + 1;
    }
    std::cout << sum << " ";

    sum = 1e6;
    for (int i = 0; i < B - 1; i++) {
        std::cout << -(i + 1) << " ";
        sum -= i + 1;
    }
    std::cout << -sum << std::endl;
}
