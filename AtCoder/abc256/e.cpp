/**
 * @file e.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-18 21:27:40
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<long long int> X(N), C(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i];
        X[i]--;
    }
    for (int i = 0; i < N; i++) {
        std::cin >> C[i];
    }

    long long int sum = 0;

    std::vector<int> flag(N, 0);
    for (int i = 0; i < N; i++) {
        if (flag[i] > 0) {
            continue;
        }
        auto idx = X[i];
        while (flag[idx] == 0) {
            flag[idx] = i + 1;
            idx = X[idx];
        }

        if (flag[idx] != i + 1) {
            continue;
        }

        long long int min = C[idx];
        auto cur = X[idx];
        // std::cout << idx << " ";
        while (cur != idx) {
            // std::cout << cur << " ";
            min = std::min(min, C[cur]);
            cur = X[cur];
        }
        // std::cout << std::endl;
        sum += min;
    }
    std::cout << sum << std::endl;
}
