/*
 * b.cpp
 *
 * Create Date : 2022-02-13 21:11:03
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<long long int> S(N);
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
    }

    std::vector<long long int> das(N + 2, 0);
    std::vector<long long int> mins(3, 0);
    for (int i = 0; i < N - 1; i += 3) {
        for (int j = 0; j < 3; j++) {
            if (i + j + 1 >= N) {
                break;
            }
            long long int diff = das[i + j] + S[i + j + 1] - S[i + j];
            das[i + j + 3] = diff;
            mins[j] = std::min(diff, mins[j]);
        }
    }

    for (int i = 0; i < N + 2; i++) {
        das[i] -= mins[i % 3];
    }

    long long int offset = S[0] - (das[0] + das[1] + das[2]);
    if (offset < 0) {
        std::cout << "No" << std::endl;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        if (das[i] + das[i + 1] + das[i + 2] + offset != S[i]) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }

    std::cout << "Yes" << std::endl;
    for (int i = 0; i < N + 1; i++) {
        if (i % 3 == 0) {
            std::cout << das[i] + offset << " ";
        } else {
            std::cout << das[i] << " ";
        }
    }
    if ((N + 1) % 3 == 0) {
        std::cout << das[N + 1] + offset << std::endl;
    } else {
        std::cout << das[N + 1] << std::endl;
    }
}
