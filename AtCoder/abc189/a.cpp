#include <bits/stdc++.h>


int main() {
    std::string s;
    std::cin >> s;
    if (s[0] == s[1] && s[1] == s[2]) {
        std::cout << "Won" << std::endl;
    } else {
        std::cout << "Lost" << std::endl;
    }
}
