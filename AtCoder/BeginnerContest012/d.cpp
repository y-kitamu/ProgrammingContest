#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<std::pair<int, int>>> linked_list(N);
    for (int i = 0; i < M; i++) {
        int a, b, t;
        std::cin >> a >> b >> t;
        a--; b--;
        linked_list[a].emplace_back(std::make_pair(b, t));
        linked_list[b].emplace_back(std::make_pair(a, t));
    }

    int min_cost = (int)1e9;
    auto compare = [] (auto lhs, auto rhs) {
        return lhs.second > rhs.second;
    };
    for (int i = 0; i < N; i++) {
        std::vector<int> cost(N, -1);
        std::priority_queue <std::pair<int, int>,
                             std::vector<std::pair<int, int>>, decltype(compare)> que{compare};
        // std::queue<std::pair<int, int>> que;
        que.push(std::make_pair(i, 0));
        while (!que.empty()) {
            auto q = que.top();
            // auto q = que.front();
            que.pop();
            if (cost[q.first] == -1 || q.second < cost[q.first]) {
                cost[q.first] = q.second;
                for (auto pair : linked_list[q.first]) {
                    int weight = pair.second + cost[q.first];
                    if (cost[pair.first] == -1 || weight < cost[pair.first]) {
                        que.push(std::make_pair(pair.first, weight));
                    }
                }
            }
        }
        int max = 0;
        for (int i = 0; i < N; i++) {
            max = std::max(max, cost[i]);
        }
        if (max < min_cost) {
            min_cost = max;
        }
    }
    std::cout << min_cost <<  std::endl;
}
