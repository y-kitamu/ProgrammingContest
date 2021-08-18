/*
 * e.cpp
 *
 * Create Date : 2021-06-19 21:38:08
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int L, R;
    std::cin >> L >> R;

    std::vector<int> square(R + 1, 0);
    std::vector<int> num_prime(R + 1, 0);
    for (int i = 2; i * i <= R; i++) {
        int val = i * i;
        for (int j = 1; val * j <= R; j++) {
            square[val * j] = 1;
        }
        if (num_prime[i] == 0) {
            for (int j = i + i; j <= R; j += i) {
                num_prime[j] = 1;
            }
        }
    }

    std::vector<int> counts(R + 1, 0);
    for (int i = 2; i <= R; i++) {
        if (num_prime[i] == 1) {
            continue;
        }
        for (int j = i; j <= R; j += i) {
            counts[j]++;
        }
    }


    long long int sum = 0;
    for (int i = 2; i <= R; i++) {
        if (square[i] == 1) {
            continue;
        }
        long long int num = R / i - (L - 1) / i;
        long long int cnt = num * (num - 1) / 2;
        // std::cout << i << " , " << counts[i] << " , " << cnt << std::endl;
        if (counts[i] % 2 == 0) {
            sum -= cnt;
        } else {
            sum += cnt;
        }
    }

    for (int i = std::max(2, L); i <= R; i++) {
        sum -= R / i - 1;
    }

    std::cout << sum * 2 << std::endl;
}
