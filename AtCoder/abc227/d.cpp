/*
 * d.cpp
 *
 * Create Date : 2021-11-13 21:27:26
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<long long int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end(), std::greater<long long int>());

    long long int min = 1;
    long long int max = 1e18;

    while (min != max) {
        long long int mid = (min + max + 1) / 2;
        long long int cnt = 0;
        long long int res = mid;
        for (int i = 0; i < N; i++) {
            if (mid <= A[i]) {
                cnt++;
            } else {
                res -= A[i];
                if (res <= 0) {
                    cnt++;
                    res += mid;
                }
            }
        }
        // std::cout << mid << " , " << cnt << std::endl;
        if (cnt < K) {
            max = mid - 1;
        } else {
            min = mid;
        }
    }
    std::cout << min << std::endl;
}
