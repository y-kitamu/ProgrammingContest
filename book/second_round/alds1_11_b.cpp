/*
 * alds1_11_b.cpp
 *
 * Create Date : 2020-03-30 23:33:42
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <cstring>
#include <iostream>

static int tp = 1;
static int n;

void depth_first(int node, int *start_ts, int *end_ts, int **adj_list) {
    start_ts[node] = tp;
    tp++;
    for (int i = 0; adj_list[node][i] != -1; i++) {
        int dst = adj_list[node][i];
        if (start_ts[dst] != 0) {
            continue;
        }
        depth_first(dst, start_ts, end_ts, adj_list);
    }
    end_ts[node] = tp;
    tp++;
}

int main() {
    std::cin >> n;
    int *adj_list[n];

    int u, k, v;
    for (int i = 0; i < n; i++) {
        std::cin >> u >> k;
        adj_list[u - 1] = new int[k + 1];
        for (int j = 0; j < k; j++) {
            std::cin >> v;
            adj_list[u - 1][j] = v - 1;
        }
        adj_list[u - 1][k] = -1;
    }

    int start_ts[n], end_ts[n];
    memset(start_ts, 0, sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        if (start_ts[i] == 0) {
            depth_first(i, start_ts, end_ts, adj_list);
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << " " << start_ts[i] << " " << end_ts[i] << std::endl;
    }
}
