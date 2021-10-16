/*
 * a.cpp
 *
 * Create Date : 2021-10-16 20:59:29
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> idx(N, 0);
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&A](auto& lhs, auto& rhs) { return A[lhs] > A[rhs]; });
    std::vector<int> flag(N, 0), ans(N, 0);

    for (auto& i : idx) {
        if (flag[i] == 1) {
            continue;
        }
        flag[i] = 1;
        for (int j = i + 1; j < N; j++) {
            if (flag[j] == 1) {
                break;
            }
            flag[j] = 1;
            if (A[i] > A[j]) {
                if (j == N - 1 || A[j] < A[j + 1]) {
                    ans[j] = ans[i] = 1;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << ans[i];
        if (i < N - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}
