#include <bits/stdc++.h>


int main() {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        long long int N;
        std::cin >> N;

        if (N % 4 == 0) {
            std::cout << "Even" << std::endl;
        } else if (N % 2 == 0) {
            std::cout << "Same" << std::endl;
        } else {
            std::cout << "Odd" << std::endl;
        }
    }
}
