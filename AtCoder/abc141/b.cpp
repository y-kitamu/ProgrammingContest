#include <bits/stdc++.h>


int main() {
    std::string S;
    std::cin >> S;

    bool flag = true;
    for (int i = 0; i < S.length(); i++) {
        if (i % 2 == 0) {
            flag &= S[i] != 'L';
        } else {
            flag &= S[i] != 'R';
        }
    }
    if (flag) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
