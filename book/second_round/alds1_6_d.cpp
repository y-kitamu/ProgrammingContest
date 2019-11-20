/*
 * alds1_6_d.cpp
 *
 * Create Date : 2019-11-20 18:31:16
 * Copyright (c) 2019 Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>
#include <cstring>

int partition(int * w, int left, int right) {
    int mid_val = w[right];
    int mid_idx = left;
    for (int i = left; i < right; i++) {
        if (w[i] < mid_val) {
            std::swap(w[mid_idx], w[i]);
            mid_idx++;
        }
    }
    std::swap(w[mid_idx], w[right]);
    return mid_idx;
}

void quickSort(int * w, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = partition(w, left, right);
    quickSort(w, left, mid - 1);
    quickSort(w, mid + 1, right);
}

int main() {
    int n;
    std::cin >> n;

    int w[n];
    
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }

    int sorted[n];
    std::memcpy(sorted, w, sizeof(int) * n);
    quickSort(sorted, 0, n - 1);

    int cost = 0;
    for (int i = 0; i < n; i++) {
        while (w[i] != sorted[i]) {
            for (int j = i; j < n; j++) {
                if (w[j] == sorted[i]) {
                    for (int k = i; k < n; k++) {
                        if (w[k] == sorted[j]) {
                            if (j != k) {
                                cost += w[j] + w[k];
                                std::swap(w[j], w[k]);
                                break;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << sorted[i] << " ";
    }
    std::cout << std::endl;

    std::cout << cost << std::endl;
}
