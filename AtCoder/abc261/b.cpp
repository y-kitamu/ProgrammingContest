/**
 * @file b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-07-23 21:03:40
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<char>> map(N, std::vector<char>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            if ((map[i][j] == 'W' && map[j][i] == 'L') || (map[i][j] == 'L' && map[j][i] == 'W') ||
                (map[i][j] == 'D' && map[j][i] == 'D')) {
                continue;
            }
            std::cout << "incorrect" << std::endl;
            return 0;
        }
    }
    std::cout << "correct" << std::endl;
}
