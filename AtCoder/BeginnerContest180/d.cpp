#include <bits/stdc++.h>


int main() {
    long long int X, Y, A, B;
    std::cin >> X >> Y >> A >> B;

    long long int exp = 0;
    while (X <= B / (A - 1)) {
        X *= A;
        if (X >= Y) {
            std::cout << exp << std::endl;
            return 0;
        }
        exp += 1;
    }
    exp += (Y - 1 - X) / B;
    std::cout << exp << std::endl;
}
