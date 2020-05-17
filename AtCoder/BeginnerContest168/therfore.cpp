#include <bits/stdc++.h>


int main() {
    std::string s;
    std::cin >> s;

    char last = s[s.length() - 1];
    if (last == '0' || last == '1' || last == '8' || last == '6') {
        std::cout << "pon" << std::endl;
    } else if (last == '3') {
        std::cout << "bon" << std::endl;
    } else {
        std::cout << "hon" << std::endl;
    }
}
