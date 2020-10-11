#include <bits/stdc++.h>


int main() {
    char c, t;
    std::cin >> c >> t;
    if (c == 'Y') {
        if (t == 'a') {
            std::cout << 'A' << std::endl;
        } else if (t == 'b') {
            std::cout << 'B' << std::endl;
        } else {
            std::cout << 'C' << std::endl;
        }
    } else {
        std::cout << t << std::endl;
    }
}
