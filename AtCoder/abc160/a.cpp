#include <bits/stdc++.h>


int main() {
    std::string S;
    std::cin >> S;
    if (S[2] == S[3] && S[4] == S[5]) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
