#include <bits/stdc++.h>


int dfs(int idx, int cnt, std::vector<int>& visited, std::vector<int>& order,
        std::vector<std::vector<int>>& linked_list) {
    if (visited[idx] == 1) {
        return cnt;
    }
    visited[idx] = 1;
    for (auto next : linked_list[idx]) {
        cnt = dfs(next, cnt, visited, order, linked_list);
    }
    order.emplace_back(idx);
    return cnt++;
}

void rdfs(int idx, int cnt, std::vector<int>& comp, std::vector<std::vector<int>>& linked_list) {
    if (comp[idx] != -1) {
        return;
    }
    comp[idx] = cnt;
    for (auto next : linked_list[idx]) {
        rdfs(next, cnt, comp, linked_list);
    }
}


int main() {
    int V, E;
    std::cin >> V >> E;

    std::vector<std::vector<int>> linked_list(V);
    std::vector<std::vector<int>> rlinked_list(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        std::cin >> s >> t;
        linked_list[s].emplace_back(t);
        rlinked_list[t].emplace_back(s);
    }

    int Q;
    std::cin >> Q;

    int cnt = 0;
    std::vector<int> visited(V, 0);
    std::vector<int> order;
    for (int i = 0; i < V; i++) {
        if (visited[i] == 0) {
            cnt = dfs(i, cnt, visited, order, linked_list);
        }
    }
    std::reverse(order.begin(), order.end());

    cnt = 0;
    std::vector<int> comp(V, -1);
    for (auto idx : order) {
        if (comp[idx] == -1) {
            rdfs(idx, cnt, comp, rlinked_list);
            cnt++;
        }
    }

    for (int i = 0; i < Q; i++) {
        int s, t;
        std::cin >> s >> t;
        if (comp[s] == comp[t]) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }

    // for (int i = 0; i < V; i++) {
    //     std::cout << order[i] << " ";
    // }
    // std::cout << std::endl;
}
