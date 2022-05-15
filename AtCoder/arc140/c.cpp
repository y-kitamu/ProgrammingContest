/**
 * @file c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-15 21:22:19
 */
#include <bits/stdc++.h>


int main() {
    int N, X;
    std::cin >> N >> X;
    X--;
    if (N % 2 == 0) {
        int mid = N / 2;
        if (mid == X) {
            std::cout << X + 1 << " ";
            int cur = X;
            int factor = 1;
            for (int i = 0; i < N - 1; i++) {
                cur += factor * (i + 1);
                std::cout << cur + 1;
                if (i < N - 2) {
                    std::cout << " ";
                }
                factor *= -1;
            }
            std::cout << std::endl;
        } else {
            int factor = 1;
            if (X > mid) {
                factor = -1;
            }
            std::cout << X + 1 << " ";
            int cur = mid;
            for (int i = 0; i < N; i++) {
            }
            std::cout << std::endl;
        }
    } else {
        int mid0 = (N - 1) / 2;
        int mid1 = (N + 1) / 2;
        if (X == mid0 || X == mid1) {
            int factor = 1;
            if (X == mid1) {
                factor = -1;
            }
            std::cout << X + 1 << " ";
            int cur = X;
            for (int i = 0; i < N - 1; i++) {
                cur += factor * (i + 1);
                std::cout << cur + 1;
                if (i < N - 2) {
                    std::cout << " ";
                }
                factor *= -1;
            }
            std::cout << std::endl;
        } else {
            int factor = -1;
            int cur = mid1;
            if (X > mid1) {
                factor = 1;
                cur = mid0;
            }
            std::cout << X + 1 << " ";
            for (int i = 0; i < N; i++) {
                cur += factor * (i + 1);
                if (cur == X) {
                    cur += factor;
                    i++;
                }
                std::cout << cur + 1;
                if (i < N - 1) {
                    std::cout << " ";
                }
                factor *= -1;
            }
            std::cout << std::endl;
        }
    }
}
