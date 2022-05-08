/**
 * @file b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-08 21:05:33
 */
#include <bits/stdc++.h>


int main() {
    int N, A, B;
    std::cin >> N >> A >> B;

    for (int i = 0; i < N; i++) {
        for (int a = 0; a < A; a++) {
            for (int j = 0; j < N; j++) {
                char c = (i + j) % 2 == 0 ? '.' : '#';
                for (int b = 0; b < B; b++) {
                    std::cout << c;
                }
            }
            std::cout << std::endl;
        }
    }
}
