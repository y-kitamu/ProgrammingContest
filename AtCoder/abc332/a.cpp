/**
 * @file a.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2023-12-10 21:00:25
 */
#include <bits/stdc++.h>

int main(int argc, char** argv) {
    int N, S, K;
    std::cin >> N >> S >> K;

    long long int sum = 0, p, q;
    for (int i = 0; i < N; i++) {
        std::cin >> p >> q;
        long long int cost = p * q;
        sum += cost;
    }
    if (sum < S) {
        sum += K;
    }
    std::cout << sum << std::endl;
}
