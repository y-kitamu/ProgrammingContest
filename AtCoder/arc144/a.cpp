/**
 * @file a.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-07-16 20:59:16
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    int M = N * 2;
    std::cout << M << std::endl;
    if (N % 4 > 0) {
        std::cout << N % 4;
    }
    for (int i = 0; i < N / 4; i++) {
        std::cout << 4;
    }
    std::cout << std::endl;
}
