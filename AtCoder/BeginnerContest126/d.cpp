#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<std::pair<int,int>>> linked_list(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--; v--;
        linked_list[u].emplace_back(std::make_pair(v, w));
        linked_list[v].emplace_back(std::make_pair(u, w));
    }

    std::vector<int> output(N, -1);
    std::queue<std::tuple<int, int, int>> que; // before, after, weight
    output[0] = 0;
    que.push(std::make_tuple(0, 0, 0));
    while (!que.empty()) {
        auto q = que.front();
        que.pop();
        int before = std::get<0>(q);
        int after = std::get<1>(q);
        int weight = std::get<2>(q);
        output[after] = (output[before] + weight) % 2;
        for (auto next: linked_list[after]) {
            if (output[next.first] == -1) {
                que.push(std::make_tuple(after, next.first, next.second));
            }
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << output[i] << std::endl;
    }
}
