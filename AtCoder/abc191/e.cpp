#include <bits/stdc++.h>


struct Road {
    Road(int from, int to, int time) : from(from), to(to), time(time) {}
    int from, to, time;
};


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<Road>> linked_list(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--;
        b--;
        linked_list[a].emplace_back(Road(a, b, c));
    }

    auto compare = [](std::pair<int, Road>& lhs, std::pair<int, Road>& rhs) {
        return lhs.first > rhs.first;
    };

    for (int i = 0; i < N; i++) {
        std::vector<int> weight(N, -1);
        weight[i] = 0;
        std::priority_queue<std::pair<int, Road>, std::vector<std::pair<int, Road>>, decltype(compare)>
            que{compare};
        for (auto road : linked_list[i]) {
            que.push(std::make_pair(road.time, road));
        }
        bool flag = false;
        while (!que.empty()) {
            auto pair = que.top();
            que.pop();
            auto road = pair.second;
            if (road.to == i) {
                flag = true;
                weight[i] = pair.first;
                break;
            }
            // std::cout << pair.first << " ,  " << road.from << " , " << road.to << std::endl;
            if (weight[road.to] != -1) {
                continue;
            }
            weight[road.to] = pair.first;
            for (auto next : linked_list[road.to]) {
                if (next.to != i && weight[next.to] != -1) {
                    continue;
                }
                que.push(std::make_pair(weight[next.from] + next.time, next));
            }
        }

        if (flag) {
            std::cout << weight[i] << std::endl;
        } else {
            std::cout << -1 << std::endl;
        }
    }
}
