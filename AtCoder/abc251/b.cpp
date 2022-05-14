/**
 * @file b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-14 21:01:35
 */
#include <bits/stdc++.h>


int main() {
    int N, W;
    std::cin >> N >> W;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> flag(W + 1, 0);
    for (int i = 0; i < N; i++) {
        if (A[i] <= W) {
            flag[A[i]]++;
        }
        for (int j = i + 1; j < N; j++) {
            if (A[i] + A[j] <= W) {
                flag[A[i] + A[j]]++;
            }
            for (int k = j + 1; k < N; k++) {
                if (A[i] + A[j] + A[k] <= W) {
                    flag[A[i] + A[j] + A[k]]++;
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= W; i++) {
        if (flag[i] > 0) {
            cnt++;
        }
    }
    std::cout << cnt << std::endl;
}
