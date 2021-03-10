#include <bits/stdc++.h>


int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a + b + c >= 22) {
        std::cout << "bust" << std::endl;
    } else {
        std::cout << "win" << std::endl;
    }
}
