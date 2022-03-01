/*
 * b.cpp
 *
 * Create Date : 2022-02-27 21:05:53
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


void bubble(std::vector<int>& vec, int N) {
    for (int i = 0; i < N - 2; i++) {
        for (int j = N - 3; j >= 0; j--) {
            if (vec[j] <= vec[j + 1] && vec[j] <= vec[j + 2]) {
            } else if (vec[j + 1] <= vec[j] && vec[j + 1] <= vec[j + 2]) {
                std::swap(vec[j], vec[j + 1]);
                std::swap(vec[j + 1], vec[j + 2]);
            } else if (vec[j + 2] <= vec[j] && vec[j + 2] <= vec[j + 1]) {
                std::swap(vec[j + 1], vec[j + 2]);
                std::swap(vec[j], vec[j + 1]);
            }

            if (vec[j] == vec[j + 2] && vec[j + 2] < vec[j + 1]) {
                std::swap(vec[j + 1], vec[j + 2]);
            }
        }
    }
}

void bubble_rev(std::vector<int>& vec, int N) {
    for (int i = 0; i < N - 2; i++) {
        for (int j = N - 3; j >= 0; j--) {
            if (vec[j] >= vec[j + 1] && vec[j] >= vec[j + 2]) {
            } else if (vec[j + 1] >= vec[j] && vec[j + 1] >= vec[j + 2]) {
                std::swap(vec[j], vec[j + 1]);
                std::swap(vec[j + 1], vec[j + 2]);
            } else if (vec[j + 2] >= vec[j] && vec[j + 2] >= vec[j + 1]) {
                std::swap(vec[j + 1], vec[j + 2]);
                std::swap(vec[j], vec[j + 1]);
            }

            if (vec[j] == vec[j + 2] && vec[j + 2] > vec[j + 1]) {
                std::swap(vec[j + 1], vec[j + 2]);
            }
        }
    }
}


int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N), B(N);
    int MAX = 10000;
    std::vector<int> cntsa(MAX, 0), cntsb(MAX, 0);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        cntsa[A[i]]++;
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
        cntsb[B[i]]++;
    }

    for (int i = 0; i < MAX; i++) {
        if (cntsa[i] != cntsb[i]) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }

    bubble(A, N);
    bubble(B, N);

    bool flag = true;
    for (int i = 0; i < N; i++) {
        if (A[i] != B[i]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        std::cout << "Yes" << std::endl;
        return 0;
    }

    bubble_rev(A, N);
    bubble_rev(B, N);
    for (int i = 0; i < N; i++) {
        if (A[i] != B[i]) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
}
