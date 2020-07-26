#include <bits/stdc++.h>


int main() {
    std::string pass;
    std::cin >> pass;
    for (int i = 0; i < 3; i++) {
        if (pass[i] == pass[i + 1]) {
            std::cout << "Bad" << std::endl;
            return 0;
        }
    }
    std::cout << "Good" << std::endl;
}
