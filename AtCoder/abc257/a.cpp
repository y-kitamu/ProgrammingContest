/**
 * @file a.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-25 20:58:51
 */
#include <bits/stdc++.h>


int main() {
    int N, X;
    std::cin >> N >> X;
    std::cout << (char)('A' + (X - 1) / N) << std::endl;
}
