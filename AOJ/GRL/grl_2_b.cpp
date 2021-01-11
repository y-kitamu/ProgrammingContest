#include <bits/stdc++.h>

constexpr int MAX = 1e7;

struct Edge {
    int src = -1, dst = -1, weight = MAX;
};


int chi_liu_edmonds(int V, int root, std::vector<Edge> edges) {
    std::vector<Edge> nodes(V);
    for (auto edge : edges) {
        if (edge.weight < nodes[edge.dst].weight) {
            nodes[edge.dst] = edge;
        }
    }
    nodes[root] = Edge();

    std::vector<bool> used(V, false);
    std::vector<bool> compressed(V, false);
    std::vector<int> group(V);
    int cnt = 0;
    for (int i = 0; i < V; i++) {
        if (used[i]) {
            continue;
        }
        std::vector<int> chain;
        int cur = i;
        while (cur != -1 && !used[cur]) {
            chain.emplace_back(cur);
            used[cur] = true;
            cur = nodes[cur].src;
        }
        if (cur != -1) {
            bool flag = false;
            for (auto idx : chain) {
                group[idx] = cnt;
                if (cur == idx) {
                    flag = true;
                    compressed[cnt] = true;
                }
                if (!flag) {
                    cnt++;
                }
            }
            if (flag) {
                cnt++;
            }
        } else {
            for (auto idx : chain) {
                group[idx] = cnt;
                cnt++;
            }
        }
    }

    if (cnt == V) {
        long long int sum = 0;
        for (int i = 0; i < V; i++) {
            if (i != root) {
                sum += nodes[i].weight;
            }
        }
        return sum;
    }

    long long int res = 0;
    for (int i = 0; i < V; i++) {
        if (compressed[group[i]]) {
            res += nodes[i].weight;
        }
    }
    std::vector<Edge> new_edges;
    for (auto edge : edges) {
        if (group[edge.src] == group[edge.dst]) {
            continue;
        } else if (compressed[group[edge.dst]]) {
            Edge e;
            e.src = group[edge.src];
            e.dst = group[edge.dst];
            e.weight = edge.weight - nodes[edge.dst].weight;
            new_edges.emplace_back(e);
        } else {
            Edge e;
            e.src = group[edge.src];
            e.dst = group[edge.dst];
            e.weight = edge.weight;
            new_edges.emplace_back(e);
        }
    }
    return res + chi_liu_edmonds(cnt, group[root], new_edges);
}


int main() {
    int V, E, r;
    std::cin >> V >> E >> r;

    std::vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        std::cin >> edges[i].src >> edges[i].dst >> edges[i].weight;
    }

    std::vector<Edge> nodes(V);
    std::cout << chi_liu_edmonds(V, r, edges) << std::endl;
}
