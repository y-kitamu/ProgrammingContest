/*
 * alds1_6_a.cpp
 *
 * Create Date : 2019-11-17 19:02:32
 * Copyright (c) 2019 Yusuke Kitamura <ymyk6602@gmail.com>
 */

#include <iostream>

const int MAX_NUM = 2000000;

void CountingSort(int * A, int * B, int n) {
    int C[MAX_NUM + 1] = {};

    for (int i = 0; i < n; i++) {
        C[A[i]]++;
    }

    for (int i = 1; i <= MAX_NUM; i++) {
        C[i] = C[i] + C[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
}


int main() {
    int n;
    std::cin >> n;
    int A[n], B[n];

    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    CountingSort(A, B, n);

    for (int i = 0; i < n - 1; i++) {
        std::cout << B[i] << " ";
    }
    std::cout << B[n - 1] << std::endl;
}
