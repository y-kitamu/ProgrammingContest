/**
 * @file a.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-07-17 20:58:47
 */
#include <bits/stdc++.h>


int main() {
    std::string S;
    std::cin >> S;

    if (S[0] != S[1] && S[0] != S[2]) {
        std::cout << S[0] << std::endl;
    } else if (S[1] != S[0] && S[1] != S[2]) {
        std::cout << S[1] << std::endl;
    } else if (S[2] != S[0] && S[2] != S[1]) {
        std::cout << S[2] << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
}
