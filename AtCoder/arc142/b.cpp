/**
 * @file b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-19 21:13:01
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> vals(N, std::vector<int>(N, 0));
    int cur_min = 1;
    int cur_max = (N * N + 1) / 2 + 1;
    for (int i = 0; i < N; i++) {
        bool flag = i % 2 == 0;
        for (int j = 0; j < N; j++) {
            if (flag) {
                vals[i][j] = cur_min;
                cur_min++;
            } else {
                vals[i][j] = cur_max;
                cur_max++;
            }
            flag = !flag;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << vals[i][j];
            if (j < N - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}
