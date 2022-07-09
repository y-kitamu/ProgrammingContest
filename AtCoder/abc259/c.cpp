/**
 * @file c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-07-09 21:11:58
 */
#include <bits/stdc++.h>


int main() {
    std::string S, T;
    std::cin >> S >> T;

    if (S.length() > T.length()) {
        std::cout << "No" << std::endl;
        return 0;
    } else if (S.length() == T.length()) {
        for (int i = 0; i < S.length(); i++) {
            if (S[i] != T[i]) {
                std::cout << "No" << std::endl;
                return 0;
            }
        }
        std::cout << "Yes" << std::endl;
        return 0;
    }

    int si = 0;
    for (int i = 0; i < T.length(); i++) {
        if (si < S.length() && S[si] == T[i]) {
            si++;
            continue;
        }
        if (i < 2) {
            std::cout << "No" << std::endl;
            return 0;
        }
        if (S[si - 1] == S[si - 2] && T[i] == S[si - 1]) {
            continue;
        }
        std::cout << "No" << std::endl;
        return 0;
    }
    if (si == S.length()) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
