#include <bits/stdc++.h>

struct Node {
    int min = 2e9, max = 0;
};

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> prices(N);
    for (int i = 0; i < N; i++) {
        std::cin >> prices[i];
    }

    std::vector<std::vector<int>> linked_list(N);

    for (int i = 0; i < M; i++) {
        int x, y;
        std::cin >> x >> y;
        x--; y--;
        linked_list[y].emplace_back(x);
    }

    std::vector<int> nodes(N, 2e9);

    int out = -2e9;
    for (int i = 0; i < N; i++) {
        int min_buy = 2e9;
        for (auto prev : linked_list[i]) {
            min_buy = std::min(min_buy, nodes[prev]);
        }
        if (linked_list[i].size() > 0) {
            out = std::max(out, prices[i] - min_buy);
        }
        nodes[i] = std::min(min_buy, prices[i]);
    }
    std::cout << out << std::endl;
}
