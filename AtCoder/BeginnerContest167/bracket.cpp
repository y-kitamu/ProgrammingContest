#include <iostream>
#include <string>
#include <vector>


int main () {
    int N;
    std::cin >> N;

    int sum = 0;
    for (int i = 0; i < N; i++) {
        std::string str;
        std::cin >> str;
        for (auto c : str) {
            if (c == '(') {
                sum++;
            } else {
                sum--;
            }
        }
    }
    if (sum == 0) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
