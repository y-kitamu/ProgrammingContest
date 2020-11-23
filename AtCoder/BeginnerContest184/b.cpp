#include <bits/stdc++.h>


int main() {
    int N, X;
    std::string S;
    std::cin >> N >> X;
    std::cin >> S;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'o') {
            X++;
        } else {
            X--;
            if (X < 0) {
                X = 0;
            }
        }
    }
    std::cout << X << std::endl;
}
