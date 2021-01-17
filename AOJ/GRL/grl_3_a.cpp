#include <bits/stdc++.h>

long long int cnt = 0;

void dfs(int idx, std::vector<int>& number, std::vector<int>& parent, std::vector<int>& lowest,
         const std::vector<std::vector<int>>& linked_list) {
    // std::cout << idx << " , " << cnt << std::endl;
    lowest[idx] = number[idx] = cnt;
    cnt++;
    for (auto next : linked_list[idx]) {
        if (number[next] == -1) {
            parent[next] = idx;
            dfs(next, number, parent, lowest, linked_list);
            lowest[idx] = std::min(lowest[idx], lowest[next]);
        } else if (next != parent[idx] && lowest[next] != -1) {
            lowest[idx] = std::min(lowest[idx], number[next]);
        }
    }
}

int main() {
    int V, E;
    std::cin >> V >> E;

    std::vector<std::vector<int>> linked_list(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        std::cin >> s >> t;
        linked_list[s].emplace_back(t);
        linked_list[t].emplace_back(s);
    }

    std::vector<int> number(V, -1), parent(V, -1), lowest(V, -1);
    parent[0] = 0;
    dfs(0, number, parent, lowest, linked_list);
    std::set<int> aps;
    int cnt = 0;
    for (int i = 1; i < V; i++) {
        // std::cout << i << ", " << parent[i] << " , " << number[i] << ", " << lowest[i] << std::endl;
        if (parent[i] == 0) {
            cnt++;
            continue;
        }
        if (number[parent[i]] <= lowest[i]) {
            aps.insert(parent[i]);
        }
    }
    if (cnt >= 2) {
        aps.insert(0);
    }
    for (std::set<int>::iterator it = aps.begin(); it != aps.end(); it++) {
        std::cout << *it << std::endl;
    }
}
