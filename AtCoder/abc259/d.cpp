/**
 * @file d.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-07-09 21:21:03
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    long long int sx, sy, tx, ty;
    std::cin >> sx >> sy >> tx >> ty;

    std::vector<std::vector<long long int>> circles(N, std::vector<long long int>(3));

    for (int i = 0; i < N; i++) {
        std::cin >> circles[i][0] >> circles[i][1] >> circles[i][2];
    }

    std::vector<std::vector<int>> ll(N);

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            auto p1 = circles[i];
            auto p2 = circles[j];
            long long int dx = p1[0] - p2[0], dy = p1[1] - p2[1];
            long long int d = p1[2] + p2[2];
            if (dx * dx + dy * dy == d * d) {
                ll[i].emplace_back(j);
                ll[j].emplace_back(i);
            } else if (dx * dx + dy * dy < d * d) {
                double delta = sqrt((double)dx * dx + (double)dy * dy);
                if (delta >= (double)std::abs(p1[2] - p2[2])) {
                    ll[i].emplace_back(j);
                    ll[j].emplace_back(i);
                }
            }
        }
    }


    std::queue<int> que;
    std::vector<int> flag(N, 0);
    for (int i = 0; i < N; i++) {
        auto pt = circles[i];
        auto dx = sx - pt[0], dy = sy - pt[1];
        if (dx * dx + dy * dy == pt[2] * pt[2]) {
            que.push(i);
            flag[i] = 1;
        }
    }


    auto judge = [&tx, &ty](std::vector<long long int> pt) {
        auto dx = tx - pt[0], dy = ty - pt[1];
        return dx * dx + dy * dy == pt[2] * pt[2];
    };

    while (!que.empty()) {
        auto top = que.front();
        que.pop();

        if (judge(circles[top])) {
            std::cout << "Yes" << std::endl;
            return 0;
        }

        for (auto& next : ll[top]) {
            if (flag[next] == 0) {
                que.push(next);
                flag[next] = 1;
            }
        }
    }

    std::cout << "No" << std::endl;
}
