#include <bits/stdc++.h>


int main() {
    std::string S;
    std::cin >> S;
    int cnt = 0;
    for (int i = 0; i < S.length() / 2; i++) {
        cnt += S[i] != S[S.length() - i - 1];
    }
    std::cout << cnt << std::endl;
}
