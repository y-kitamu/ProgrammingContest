/*
 * alds1_11_c.cpp
 *
 * Create Date : 2020-03-31 21:19:36
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <cstring>
#include <iostream>

static int n;
static int ts = 0;

void breadthfirst(int *next, int *timestamp, int **adj_list) {
    int new_next[n];
    int next_cnt = 0;
    for (int i = 0; i < n; i++) {
        if (next[i] != 1) {
            continue;
        }
        timestamp[i] = ts;
        for (int j = 0; adj_list[i][j] != -1; j++) {
            int idx = adj_list[i][j];
            if (timestamp[idx] == -1 && next[idx] != 1) {
                new_next[idx] = 1;
                next_cnt++;
            }
        }
    }
    ts++;
    if (next_cnt > 0) {
        breadthfirst(new_next, timestamp, adj_list);
    }
}

int main() {
    std::cin >> n;

    int *adj_list[n];
    int u, v, k;
    for (int i = 0; i < n; i++) {
        std::cin >> u >> k;
        adj_list[u - 1] = new int[k + 1];
        adj_list[u - 1][k] = -1;
        for (int j = 0; j < k; j++) {
            std::cin >> v;
            adj_list[u - 1][j] = v - 1;
        }
    }

    int status[n], timestamp[n];
    memset(status, 0, sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        timestamp[i] = -1;
    }
    status[0] = 1;
    breadthfirst(status, timestamp, adj_list);

    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << " " << timestamp[i] << std::endl;
    }
}
