/*
 * e.cpp
 *
 * Create Date : 2022-04-10 21:16:06
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int N, X, Y;
    std::cin >> N >> X >> Y;

    std::vector<long long int> A(N);
    std::vector<long long int> x_inds, y_inds;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        if (A[i] == X) {
            x_inds.emplace_back(i);
        }
        if (A[i] == Y) {
            y_inds.emplace_back(i);
        }
    }

    std::vector<long long int> left(N + 1, 0), right(N);
    for (int i = 0; i < N; i++) {
        if (A[i] < Y || X < A[i]) {
            left[i + 1] = 0;
        } else {
            left[i + 1] = 1 + left[i];
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        if (A[i] < Y || X < A[i]) {
            right[i] = 0;
        } else {
            right[i] = 1;
            if (i < N - 1) {
                right[i] += right[i + 1];
            }
        }
    }

    long long int xi = 0, yi = 0;
    long long int ans = 0;
    long long int prev = -1;

    while (xi < x_inds.size() && yi < y_inds.size()) {
        if (x_inds[xi] < y_inds[yi]) {
            while (xi + 1 < x_inds.size() && x_inds[xi + 1] < y_inds[yi]) {
                xi++;
            }
            bool flag = true;
            for (int i = x_inds[xi]; i < y_inds[yi]; i++) {
                if (A[i] < Y || X < A[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans += std::min(left[x_inds[xi] + 1], x_inds[xi] - prev) * right[y_inds[yi]];
                prev = x_inds[xi];
            }
            xi++;
        } else if (x_inds[xi] > y_inds[yi]) {
            while (yi + 1 < y_inds.size() && y_inds[yi + 1] < x_inds[xi]) {
                yi++;
            }
            bool flag = true;
            for (int i = y_inds[yi]; i < x_inds[xi]; i++) {
                if (A[i] < Y || X < A[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans += std::min(left[y_inds[yi] + 1], y_inds[yi] - prev) * right[x_inds[xi]];
                prev = y_inds[yi];
            }
            yi++;
        } else {
            ans += std::min(left[x_inds[xi] + 1], x_inds[xi] - prev) * right[x_inds[xi]];
            prev = x_inds[xi];
            xi++;
            yi++;
        }
    }

    std::cout << ans << std::endl;
}
