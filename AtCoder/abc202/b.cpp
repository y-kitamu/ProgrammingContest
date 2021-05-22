#include <bits/stdc++.h>


int main() {
    std::string S;
    std::cin >> S;

    std::string res = "";
    int len = S.length();
    for (int i = 0; i < S.length(); i++) {
        auto c = S[len - 1 - i];
        if (c == '0') {
            res += '0';
        } else if (c == '1') {
            res += '1';
        } else if (c == '6') {
            res += '9';
        } else if (c == '8') {
            res += '8';
        } else if (c == '9') {
            res += '6';
        }
    }
    std::cout << res << std::endl;
}
