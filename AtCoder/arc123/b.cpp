/*
 * b.cpp
 *
 * Create Date : 2021-07-18 21:09:14
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> C[i];
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    std::sort(C.begin(), C.end());

    int ia = 0, ib = 0, ic = 0;
    while (ia < N) {
        auto itrb = std::upper_bound(B.begin() + ib, B.end(), A[ia]);
        ib = itrb - B.begin();
        if (ib == N) {
            break;
        }
        auto itrc = std::upper_bound(C.begin() + ic, C.end(), B[ib]);
        ic = itrc - C.begin();
        if (ic == N) {
            break;
        }

        ia++;
        ib++;
        ic++;
    }
    std::cout << ia << std::endl;
}
