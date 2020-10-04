#include <bits/stdc++.h>


int main() {
    std::string str;
    std::cin >> str;
    if (str[str.length() - 1] == 's') {
        std::cout << str << "es" << std::endl;
    } else {
        std::cout << str << "s" << std::endl;
    }
}
