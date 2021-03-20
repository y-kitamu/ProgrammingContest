#include <bits/stdc++.h>


int main() {
    std::string str;
    std::cin >> str;
    int pos = str.find('.');
    std::cout << str.substr(0, pos) << std::endl;
}
