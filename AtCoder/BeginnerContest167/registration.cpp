#include <iostream>
#include <string>

int main() {
    std::string S, T;
    std::cin >> S >> T;

    for (auto i = 0; i < S.length(); i++) {
        if (S[i] != T[i]) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
}
