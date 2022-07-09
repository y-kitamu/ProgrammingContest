/**
 * @file a.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-07-09 20:57:26
 */
#include <bits/stdc++.h>


int main() {
    int N, M, X, T, D;

    std::cin >> N >> M >> X >> T >> D;

    int init = T - std::min(N, X) * D;

    std::cout << init + std::min(M, X) * D << std::endl;
    ;
}
