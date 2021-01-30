#include <bits/stdc++.h>


void bfs(int root, std::vector<int>& dist,
         const std::vector<std::vector<std::pair<int, int>>>& linked_list) {
    std::queue<std::vector<int>> que;
    dist[root] = 0;
    que.push({root, root, 0});
    while (!que.empty()) {
        auto top = que.front();
        que.pop();
        dist[top[1]] = dist[top[0]] + top[2];
        for (auto next : linked_list[top[1]]) {
            if (next.first != top[0] && dist[next.first] == 0) {
                que.push({top[1], next.first, next.second});
            }
        }
    }
}


int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<std::pair<int, int>>> linked_list(n);
    for (int i = 0; i < n - 1; i++) {
        int s, t, w;
        std::cin >> s >> t >> w;
        linked_list[s].emplace_back(std::make_pair(t, w));
        linked_list[t].emplace_back(std::make_pair(s, w));
    }

    std::vector<int> dist1(n, 0);
    bfs(0, dist1, linked_list);
    int max_idx = 0;
    for (int i = 0; i < n; i++) {
        if (dist1[i] > dist1[max_idx]) {
            max_idx = i;
        }
    }

    std::vector<int> dist2(n, 0);
    bfs(max_idx, dist2, linked_list);
    int other_idx = 0;
    for (int i = 0; i < n; i++) {
        if (dist2[i] > dist2[other_idx]) {
            other_idx = i;
        }
    }

    std::vector<int> dist3(n, 0);
    bfs(other_idx, dist3, linked_list);

    for (int i = 0; i < n; i++) {
        std::cout << std::max(dist2[i], dist3[i]) << std::endl;
    }
}
