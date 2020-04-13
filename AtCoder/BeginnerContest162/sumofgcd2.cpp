/*
 * sumofgcd2.cpp
 *
 * Create Date : 2020-04-12 21:59:11
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>
#include <vector>
#include <cmath>


int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<long long int> gcd_nums(K + 1, 0);
    long long int count = 0;
    long long int max = 1e9 + 7;
    
    for (int i = K; i > 0; i--) {
        int multiples_cnt = 1;
        int gcd_cnt = 0;
        for (int j = 2;; j++) {
            if (i * j > K) {
                break;
            }
            multiples_cnt++;
            gcd_cnt += gcd_nums[i * j];
            gcd_cnt = gcd_cnt % max;
        }
        int val = 1;
        for (int k = 0; k < N; k++) {
            val = val * multiples_cnt % max;
        }
        gcd_nums[i] = (val - gcd_cnt) % max;
        if (gcd_nums[i] < 0) {
            gcd_nums[i] += max;
        }
        count += gcd_nums[i] * i % max;
    }
    std::cout << count << std::endl;
}
