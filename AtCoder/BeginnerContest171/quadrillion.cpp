#include <bits/stdc++.h>


int main() {
    long long int number;

    std::cin >> number;

    std::vector<char> name;
    while (number > 26) {
        long long int val = (number - 1) % 26;
        name.emplace_back('a' + (uint8_t)val);
        number = (number - 1) / 26;
    }
    name.emplace_back('a' + (uint8_t)number - 1);

    for (int i = name.size() - 1; i >= 0; i--) {
        std::cout << name[i];
    }
    std::cout << std::endl;
}
