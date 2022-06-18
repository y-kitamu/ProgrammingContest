/**
 * @file b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-18 21:01:04
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int sum = 0;
    for (int i = N - 1; i >= 0; i--) {
        sum += A[i];
        if (sum >= 4) {
            std::cout << i + 1 << std::endl;
            return 0;
        }
    }
    std::cout << 0 << std::endl;
}
