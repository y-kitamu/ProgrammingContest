#include <bits/stdc++.h>


int main() {
    int N;
    std::string S;
    std::cin >> N >> S;

    for (int i = 0; i < S.size(); i++) {
        auto c = S[i] + N;
        if (c > 'Z') {
            c -= 26;
        }
        S[i] = c;
    }
    std::cout << S << std::endl;
}
