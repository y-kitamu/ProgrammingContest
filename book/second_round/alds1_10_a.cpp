/*
 * alds1_10_a.cpp
 *
 * Create Date : 2020-03-29 13:14:23
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>

static int has_fib[44];
static int fib[44];

int fibonacci(int n) {
    if (has_fib[n] == 1) {
        return fib[n];
    }
    fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
    has_fib[n] = 1;
    return fib[n];
}

int main() {
    int N;
    fib[0] = 1;
    has_fib[0] = 1;
    fib[1] = 1;
    has_fib[1] = 1;
    std::cin >> N;
    std::cout << fibonacci(N) << std::endl;
}
