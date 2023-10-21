/**
 * @file grl_1_c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2023-10-21 23:13:29
 */
#include <bits/stdc++.h>


constexpr int MAX = 2e9;

int main(int argc, char** argv) {
    int v, e;
    std::cin >> v >> e;

    std::vector<std::vector<int>> dist(v, std::vector<int>(v, MAX));
    for (int i = 0; i < v; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < e; i++) {
        int s, t, d;
        std::cin >> s >> t >> d;
        dist[s][t] = d;
    }


    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            for (int k = 0; k < v; k++) {
                for (int l = 0; l < v; l++) {
                    if (dist[j][l] == MAX || dist[l][k] == MAX) {
                        continue;
                    }
                    dist[j][k] = std::min(dist[j][l] + dist[l][k], dist[j][k]);
                }
            }
        }
    }

    for (int i = 0; i < v; i++) {
        if (dist[i][i] < 0) {
            std::cout << "NEGATIVE CYCLE" << std::endl;
            return 0;
        }
    }

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == MAX) {
                std::cout << "INF";
            } else {
                std::cout << dist[i][j];
            }
            if (j != v - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}
