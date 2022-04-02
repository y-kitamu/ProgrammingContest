/*
 * b.cpp
 *
 * Create Date : 2022-04-02 21:03:54
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int A, B;
    std::cin >> A >> B;

    double dx = (double)A / std::sqrt(A * A + B * B);
    double dy = (double)B / std::sqrt(A * A + B * B);
    std::cout << std::fixed << std::setprecision(10) << dx << " " << dy << std::endl;
}
