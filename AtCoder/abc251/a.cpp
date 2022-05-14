/**
 * @file a.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-14 20:59:07
 */
#include <bits/stdc++.h>


int main() {
    std::string S;
    std::cin >> S;

    for (int i = 0; i < 6 / S.length(); i++) {
        std::cout << S;
    }
    std::cout << std::endl;
}
