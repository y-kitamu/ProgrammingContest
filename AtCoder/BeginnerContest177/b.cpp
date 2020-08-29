#include <bits/stdc++.h>

int main() {
    std::string S, T;
    std::cin >> S >> T;

    int len_s = S.length();
    int len_t = T.length();
    int min = len_t;
    for (int i = 0; i <= len_s - len_t; i++) {
        int count = 0;
        for (int j = 0; j < len_t; j++) {
            if (S[i + j] != T[j]) {
                count++;
            }
        }
        min = std::min(min, count);
    }
    std::cout << min << std::endl;
}
