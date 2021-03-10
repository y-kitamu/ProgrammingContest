#include <bits/stdc++.h>

struct Edge {
    int dst, idx;
};


void dfs(int idx, int color, std::vector<int>& colors, std::vector<std::vector<Edge>>& ll) {
    int next_color = 1;
    if (next_color == color) {
        next_color++;
    }
    for (auto next : ll[idx]) {
        if (colors[next.idx] != -1) {
            continue;
        }
        colors[next.idx] = next_color;
        dfs(next.dst, next_color, colors, ll);
        next_color++;
        if (next_color == color) {
            next_color++;
        }
    }
}


int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<Edge>> linked_list(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        linked_list[a].emplace_back(Edge({b, i}));
        linked_list[b].emplace_back(Edge({a, i}));
    }

    std::vector<int> colors(N - 1, -1);
    dfs(0, 0, colors, linked_list);
    int max = 0;
    for (int i = 0; i < colors.size(); i++) {
        max = std::max(max, colors[i]);
    }
    std::cout << max << std::endl;
    for (auto c : colors) {
        std::cout << c << std::endl;
    }
}
