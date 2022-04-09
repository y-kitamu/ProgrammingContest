/*
 * b.cpp
 *
 * Create Date : 2022-04-09 21:24:28
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

    // if (A[0] == 1) {
    //     std::cout << "No" << std::endl;
    //     return 0;
    // }

    int flipped = 0;
    int lidx = 0;
    int ridx = N - 1;
    while (lidx <= ridx) {
        // std::cout << lidx << " , " << ridx << std::endl;
        if (!(A[ridx] ^ flipped)) {
            ridx--;
        } else if (!(A[lidx] ^ flipped)) {
            lidx++;
            flipped = 1 - flipped;
        } else {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
}
