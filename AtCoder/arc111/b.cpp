#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> colors(400000);
    for (int i = 0; i < N; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        colors[a].emplace_back(b);
        colors[b].emplace_back(a);
    }

    int sum = 0;
    std::vector<bool> flag(colors.size(), false);
    for (int i = 0; i < colors.size(); i++) {
        if (flag[i] || colors[i].size() == 0) {
            continue;
        }
        bool loop = false;
        int num = 0;
        std::queue<int> que;
        que.push(i);
        while (!que.empty()) {
            auto idx = que.front();
            que.pop();
            if (flag[idx]) {
                loop = true;
                continue;
            }
            flag[idx] = true;
            num++;
            int cnt = 0;
            for (auto next : colors[idx]) {
                if (!flag[next]) {
                    que.push(next);
                } else {
                    cnt++;
                }
            }
            if (cnt > 1) {
                loop = true;
            }
        }
        // std::cout << i << " , " << num << " , " << loop << std::endl;
        if (!loop) {
            num--;
        }
        sum += num;
    }
    std::cout << sum << std::endl;
}
