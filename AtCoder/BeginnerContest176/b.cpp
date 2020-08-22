#include <bits/stdc++.h>

int main() {
    std::string str;
    std::cin >> str;
    int sum = 0;
    for (int i = 0; i < str.length(); i++) {
        sum = (sum + (int)(str[i] - '0')) % 9;
    }
    if (sum == 0) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
