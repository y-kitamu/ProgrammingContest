/*
 * b.cpp
 *
 * Create Date : 2021-11-27 21:03:39
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int A, B;
    std::cin >> A >> B;

    while (A > 0 && B > 0) {
        long long int a = A % 10, b = B % 10;
        if (a + b >= 10) {
            std::cout << "Hard" << std::endl;
            return 0;
        }
        A /= 10;
        B /= 10;
    }
    std::cout << "Easy" << std::endl;
}
