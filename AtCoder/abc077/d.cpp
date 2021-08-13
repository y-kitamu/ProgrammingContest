/*
 * d.cpp
 *
 * Create Date : 2021-08-12 20:42:58
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int K;
    std::cin >> K;

    std::vector<int> vals(K, 1e9);
    vals[1] = 1;

    std::deque<int> que;
    que.push_back(1);
    while (!que.empty()) {
        auto front = que.front();
        que.pop_front();
        if (front == 0) {
            break;
        }
        auto n0 = front * 10 % K;
        if (vals[front] < vals[n0]) {
            vals[n0] = vals[front];
            que.push_front(n0);
        }
        auto n1 = (front + 1) % K;
        if (vals[front] + 1 < vals[n1]) {
            vals[n1] = vals[front] + 1;
            que.push_back(n1);
        }
    }
    std::cout << vals[0] << std::endl;
}
