/*
 * e.cpp
 *
 * Create Date : 2021-08-29 21:46:46
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int N, K;
    std::cin >> N >> K;
    std::vector<long long int> A(N + 1, 0);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    std::sort(A.begin(), A.end(), std::greater<long long int>());
    // for (auto& val : A) {
    //     std::cout << val << " ";
    // }
    // std::cout << std::endl;

    long long int sum = 0;
    for (int i = 0; i < N; i++) {
        long long int max = (A[i] - A[i + 1]) * (i + 1);
        if (max >= K) {
            long long int full = K / (i + 1);
            long long int val = (2 * A[i] - full + 1) * full / 2;
            sum += val * (i + 1);
            long long int res = K % (i + 1);
            sum += (A[i] - full) * res;
            break;
        } else {
            K -= max;
            sum += (A[i] + A[i + 1] + 1ll) * (A[i] - A[i + 1]) / 2ll * (long long)(i + 1);
        }
    }
    std::cout << sum << std::endl;
}
