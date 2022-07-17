/**
 * @file b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-07-17 21:02:24
 */
#include <bits/stdc++.h>


int main() {
    int N, X, Y, Z;
    std::cin >> N >> X >> Y >> Z;

    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<int> flag(N, 0);

    std::vector<int> idx(N);
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&](int a, int b) {
        if (A[a] == A[b]) {
            return a < b;
        }
        return A[a] > A[b];
    });

    for (int i = 0; i < X; i++) {
        flag[idx[i]] = 1;
    }

    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&](int a, int b) {
        if (B[a] == B[b]) {
            return a < b;
        }
        return B[a] > B[b];
    });

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (cnt >= Y) {
            break;
        }
        if (flag[idx[i]] == 0) {
            flag[idx[i]] = 1;
            cnt++;
        }
    }

    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&](int a, int b) {
        auto lhs = A[a] + B[a];
        auto rhs = A[b] + B[b];
        if (lhs == rhs) {
            return a < b;
        }
        return lhs > rhs;
    });
    cnt = 0;
    for (int i = 0; i < N; i++) {
        if (cnt >= Z) {
            break;
        }
        if (flag[idx[i]] == 0) {
            flag[idx[i]] = 1;
            cnt++;
        }
    }

    for (int i = 0; i < N; i++) {
        if (flag[i] == 1) {
            std::cout << i + 1 << std::endl;
        }
    }
}
