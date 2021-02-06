#include <bits/stdc++.h>


int main() {
    int V, T, S, D;
    std::cin >> V >> T >> S >> D;
    if (T * V <= D && D <= S * V) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }
}
