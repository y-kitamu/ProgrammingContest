#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    bool flag = false;
    for (int i = 1; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            flag |= N == i * j;
        }
    }
    if (flag) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
