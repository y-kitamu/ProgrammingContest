#include <bits/stdc++.h>


int main() {
    std::string S, T;
    std::cin >> S >> T;

    int A, B;
    std::cin >> A >> B;

    std::string U;
    std::cin >> U;

    if (S == U) {
        A--;
    } else if (T == U) {
        B--;
    }
    std::cout << A << " " << B << std::endl;
}
