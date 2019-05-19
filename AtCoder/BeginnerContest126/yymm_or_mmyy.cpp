#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    std::string S;
    std::cin >> S;
    int l = std::atoi(S.substr(0, 2).c_str());
    int r = std::atoi(S.substr(2, 2).c_str());

    if (1 <= l && l <= 12) {
        if (1 <= r && r <= 12) {
            std::cout << "AMBIGUOUS" << std::endl;
        } else {
            std::cout << "MMYY" << std::endl;
        }
    } else {
        if (1 <= r && r <= 12) {
            std::cout << "YYMM" << std::endl;
        } else {
            std::cout << "NA" << std::endl;
        }
    }
}
