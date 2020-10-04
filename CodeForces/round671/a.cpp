#include <bits/stdc++.h>


int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int N;
        std::cin >> N;
        std::string number;
        std::cin >> number;
        if (N % 2 == 0) {
            // unmarked digit is even position
            // at least 1 digit is even value, then Breach win
            bool flag = false;
            for (int i = 0; i < N; i += 2) {
                if (int(number[i] - '0') % 2 == 0) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                std::cout << 2 << std::endl;
            } else {
                std::cout << 1 << std::endl;
            }
        } else {
            // unmarked digit is odd position
            // at least 1 digit is odd value, then Raze win
            bool flag = false;
            for (int i = N - 1; i >= 0; i -= 2) {
                if (int(number[i] - '0') % 2 == 1) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                std::cout << 1 << std::endl;
            } else {
                std::cout << 2 << std::endl;
            }
        }
    }
}
