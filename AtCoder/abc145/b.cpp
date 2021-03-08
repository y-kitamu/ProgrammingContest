#include <bits/stdc++.h>


int main() {
    int N;
    std::string S;
    std::cin >> N >> S;

    if (N % 2 != 0) {
        std::cout << "No" << std::endl;
    } else {
        bool flag = true;
        for (int i = 0; i < N / 2; i++) {
            flag &= S[i] == S[i + N / 2];
        }
        if (flag) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
}
