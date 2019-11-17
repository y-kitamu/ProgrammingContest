/*
 * alds_1_6_b.cpp
 *
 * Create Date : 2019-11-17 17:30:37
 * Copyright (c) 2019 Yusuke Kitamura <ymyk6602@gmail.com>
 */

#include <iostream>
#include <memory>

int partition(int * A, int p, int r) {
    int x = A[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            std::swap(A[i], A[j]);
        }
     }
    std::swap(A[i + 1], A[r]);
    return i + 1;
}

int main() {
    int n;
    std::cin >> n;
    int A[n];

    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    
    int split = partition(A, 0, n - 1);
    for (int i = 0; i < n - 1; i++) {
        if (i == split) {
            std::cout << "[" << A[i] << "] ";
        } else {
            std::cout << A[i] << " ";
        }
    }
    if (split == n - 1) {
        std::cout << "[" << A[n - 1] << "]" << std::endl;
    } else {
        std::cout << A[n - 1] << std::endl;
    }
}
