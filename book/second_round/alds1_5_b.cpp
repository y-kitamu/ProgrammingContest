/*
 * alds_1_5_b.cpp
 *
 * Create Date : 2019-11-17 16:51:12
 * Copyright (c) 2019 Yusuke Kitamura <ymyk6602@gmail.com>
 */

#include <iostream>
#include <cstring>

const int INFTY = 2000000000;

void printArray(int * A, int n) {
    for (int i = 0; i < n - 1; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << A[n - 1] << std::endl;
}

int merge(int * A, int left, int mid, int right) {
    int n1 = mid - left, n2 = right - mid;
    int L[n1 + 1], R[n2 + 1];
    std::memcpy(L, A + left, sizeof(int) * n1);
    std::memcpy(R, A + left + n1, sizeof(int) * n2);
    L[n1] = INFTY, R[n2] = INFTY;

    int i = 0, j = 0, count = 0;
    for (int k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        count++;
    }
    return count;
}


long long mergeSort(int * A, int left, int right) {
    long long count = 0;
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        count += mergeSort(A, left, mid);
        count += mergeSort(A, mid, right);
        count += merge(A, left, mid, right);
    }
    return count;
}


int main() {
    int n;
    std::cin >> n;
    int A[n];

    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    
    long long count = mergeSort(A, 0, n);

    printArray(A, n);
    std::cout << count << std::endl;
}
