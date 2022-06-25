/**
 * @file d.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-25 21:18:22
 */
#include <bits/stdc++.h>


struct Jump {
    long long int x, y, p;
};


bool judge(int root, long long int power, std::vector<std::vector<long long int>>& dist) {
    std::vector<int> flag(dist.size(), 0);
    flag[root] = 1;
    std::queue<int> que;
    que.push(root);
    while (!que.empty()) {
        auto front = que.front();
        que.pop();
        for (int i = 0; i < dist.size(); i++) {
            if (dist[front][i] <= power && flag[i] == 0) {
                que.push(i);
                flag[i] = 1;
            }
        }
    }
    for (int i = 0; i < flag.size(); i++) {
        if (flag[i] == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<Jump> vec(N);
    for (int i = 0; i < N; i++) {
        std::cin >> vec[i].x >> vec[i].y >> vec[i].p;
    }

    std::vector<std::vector<long long int>> dist(N, std::vector<long long int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            long long int d = (std::abs(vec[i].x - vec[j].x) + std::abs(vec[i].y - vec[j].y));
            dist[i][j] = (d + vec[i].p - 1) / vec[i].p;
        }
    }

    long long int ans = 1e12;
    for (int i = 0; i < N; i++) {
        long long int min = 1, max = 1e12;
        while (min != max) {
            long long int mid = (min + max) / 2;
            if (judge(i, mid, dist)) {
                max = mid;
            } else {
                min = mid + 1;
            }
        }
        ans = std::min(min, ans);
    }
    std::cout << ans << std::endl;
}
