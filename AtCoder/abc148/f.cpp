#include <bits/stdc++.h>

std::vector<int> calc_dist(int root, std::vector<std::vector<int>>& ll,
                           std::vector<int> counter = std::vector<int>(100000, 100000)) {
    std::vector<int> dist(ll.size(), -1);
    dist[root] = 0;
    std::queue<std::pair<int, int>> que;
    for (auto& next : ll[root]) {
        if (counter[next] > 1) {
            que.push(std::make_pair(next, 1));
        }
    }
    while (!que.empty()) {
        auto top = que.front();
        que.pop();
        dist[top.first] = top.second;
        for (auto& next : ll[top.first]) {
            if (dist[next] == -1 && top.second + 1 < counter[next]) {
                que.push(std::make_pair(next, top.second + 1));
            }
        }
    }
    return dist;
}


int main() {
    int N, u, v;
    std::cin >> N >> u >> v;
    u--, v--;
    std::vector<std::vector<int>> linked_list(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        linked_list[a].emplace_back(b);
        linked_list[b].emplace_back(a);
    }

    auto dist_v = calc_dist(v, linked_list);
    auto dist_u = calc_dist(u, linked_list, dist_v);

    auto max_u = 0;
    for (int i = 0; i < N; i++) {
        if (dist_u[i] != -1) {
            max_u = std::max(dist_v[i] - 1, max_u);
        }
    }

    std::cout << max_u << std::endl;
}
