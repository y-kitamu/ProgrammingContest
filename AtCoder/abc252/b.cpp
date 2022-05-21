/**
 * @file b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-21 21:04:35
 */
#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;
    int max = 0;
    std::vector<int> A(N), B(K);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        max = std::max(A[i], max);
    }
    for (int k = 0; k < K; k++) {
        std::cin >> B[k];
        B[k]--;
    }

    for (int i = 0; i < N; i++) {
        if (A[i] == max) {
            for (int k = 0; k < K; k++) {
                if (B[k] == i) {
                    std::cout << "Yes" << std::endl;
                    return 0;
                }
            }
        }
    }
    std::cout << "No" << std::endl;
}
