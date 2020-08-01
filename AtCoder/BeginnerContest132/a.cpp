#include <bits/stdc++.h>


int main() {
    std::string S;
    std::cin >> S;
    if (S[0] == S[1] && S[2] == S[3] && S[0] != S[2]) {
        std::cout << "Yes" << std::endl;
        return 0;
    }
    if (S[0] == S[2] && S[1] == S[3] && S[0] != S[1]) {
        std::cout << "Yes" << std::endl;
        return 0;
    }
    if (S[0] == S[3] && S[1] == S[2] && S[0] != S[1]) {
        std::cout << "Yes" << std::endl;
        return 0;
    }
    std::cout << "No" << std::endl;
}
