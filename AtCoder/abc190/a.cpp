#include <bits/stdc++.h>


int main() {
    int A, B, C;
    std::cin >> A >> B >> C;
    if (C == 0) {
        if (A <= B) {
            std::cout << "Aoki" << std::endl;
        } else {
            std::cout << "Takahashi" << std::endl;
        }
    } else {
        if (A < B) {
            std::cout << "Aoki" << std::endl;
        } else {
            std::cout << "Takahashi" << std::endl;
        }
    }
}
