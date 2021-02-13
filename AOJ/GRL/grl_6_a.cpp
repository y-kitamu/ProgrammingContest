#include <bits/stdc++.h>


struct Edge {
    Edge() {}
    Edge(int capacity) : capacity(capacity) {}
    int capacity = 0;
};


int dfs(int idx, int max_flow, std::vector<bool>& used, std::vector<std::vector<Edge>>& linked_mat) {
    if (idx == linked_mat.size() - 1) {
        return max_flow;
    }

    used[idx] = true;
    int max = max_flow;
    for (int i = 0; i < linked_mat.size(); i++) {
        int flow = std::min(max_flow, linked_mat[idx][i].capacity);
        if (flow == 0 || used[i]) {
            continue;
        }
        flow = dfs(i, flow, used, linked_mat);
        linked_mat[idx][i].capacity -= flow;
        linked_mat[i][idx].capacity += flow;
        max_flow -= flow;
        if (max_flow == 0) {
            break;
        }
    }

    return max - max_flow;
}


int main() {
    int V, E;
    std::cin >> V >> E;

    std::vector<std::vector<Edge>> linked_mat(V, std::vector<Edge>(V));
    for (int i = 0; i < E; i++) {
        int u, v, c;
        std::cin >> u >> v >> c;
        linked_mat[u][v] = Edge(c);
    }

    int flaw = 0;
    for (;;) {
        std::vector<bool> used(V, false);
        int f = dfs(0, 10000 * 1000, used, linked_mat);
        if (f == 0) {
            break;
        }
        flaw += f;
    }
    std::cout << flaw << std::endl;
}
