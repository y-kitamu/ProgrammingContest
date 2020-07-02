#include <bits/stdc++.h>

int main() {
    std::string S, T;
    std::cin >> S >> T;

    int count = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] != T[i]) {
            count++;
        }
    }
    std::cout << count << std::endl;
}
