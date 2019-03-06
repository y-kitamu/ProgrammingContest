#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<std::tuple<int, int, int>>> ada_arr(
        n, std::vector<std::tuple<int, int, int>>());
    std::vector<int> min_cost(n, -1);

    for (int i = 0; i < n; i++) {
        int u, k;
        std::cin >> u >> k;
        for (int j = 0; j < k; j++) {
            int idx, weight;
            std::cin >> idx >> weight;
            ada_arr[u].push_back(std::make_tuple(u, idx, weight));
        }
    }

    min_cost[0]= 0;
    std::queue<std::tuple<int, int, int>> queue;

    for (auto && route : ada_arr[0]) {
        queue.push(route);
    }

    while (!queue.empty()) {
        std::tuple<int, int, int> route = queue.front();
        queue.pop();

        int from = std::get<0>(route);
        int to = std::get<1>(route);
        int weight = std::get<2>(route);

        if (min_cost[to] == -1 || min_cost[from] + weight < min_cost[to]) {
            min_cost[to] = min_cost[from] + weight;
            for (auto && r : ada_arr[to]) {
                queue.push(r);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << i << " " << min_cost[i] << std::endl;
    }
}
