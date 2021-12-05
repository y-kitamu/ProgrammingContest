/*
 * a.cpp
 *
 * Create Date : 2021-12-05 20:59:41
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int A, B;
    std::cin >> A >> B;

    long long int b = B / 2;
    if (B % 2 == 1) {
        b = b * 10 + 5;
    }
    long long int a = A;
    while (a > 0) {
        a /= 10;
        b *= 10;
    }
    std::cout << b * 10 + A << std::endl;
}
