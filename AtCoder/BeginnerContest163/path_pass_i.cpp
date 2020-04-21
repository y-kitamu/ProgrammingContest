/*
 * path_pass_i.cpp
 *
 * Create Date : 2020-04-19 22:20:36
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>
#include <vector>


std::vector<std::vector<int>> path;
std::vector<std::vector<int>> P;


int search() {

}


int main() {
    int N;
    std::cin >> N;

    std::vector<int> color(N);
    for (int i = 0; i < N; i++) {
        std::cin >> color[i];
        color[i]--;
    }

    path = std::vector(N, std::vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        int a, b;
        std::cin >> a >> b;
        path[a - 1][b - 1] = 1;
        path[b - 1][a - 1] = 1;
    }


    P = std::vector(N, std::vector<int>(N, -1));
    for (int i = 0; i < N; i++) {
        P[i][i] = color[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

        }
    }

    for (int i = 0; i < N; i++) {

    }
}
