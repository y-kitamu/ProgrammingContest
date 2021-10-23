/*
 * c.cpp
 *
 * Create Date : 2021-10-23 21:06:57
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<long long int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i] >> Y[i];
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            long long int x1 = X[i] - X[j];
            long long int y1 = Y[i] - Y[j];
            for (int k = j + 1; k < N; k++) {
                long long int x2 = X[j] - X[k];
                long long int y2 = Y[j] - Y[k];
                if (x1 * y2 != y1 * x2) {
                    cnt++;
                }
            }
        }
    }
    std::cout << cnt << std::endl;
}
