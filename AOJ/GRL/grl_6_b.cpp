#include <bits/stdc++.h>


constexpr int INF = 1e9;


struct Edge {
    int to, capacity = 0, distance = INF, rev;
};


int main() {
    int V, E, F;
    std::cin >> V >> E >> F;

    std::vector<std::vector<Edge>> linked_list(V);
    for (int i = 0; i < E; i++) {
        int u, v, c, d;
        std::cin >> u >> v >> c >> d;
        linked_list[u].emplace_back((Edge){v, c, d, (int)linked_list[v].size()});
        linked_list[v].emplace_back((Edge){u, 0, -d, (int)linked_list[u].size() - 1});
    }

    int cost = 0;
    bool update = true;
    while (F > 0) {
        update = false;
        std::vector<int> dist(V, INF);
        std::vector<int> prevv(V, INF), preve(V, INF);

        dist[0] = 0;
        for (int k = 0; k <= linked_list.size(); k++) {
            update = false;
            for (int i = 0; i < linked_list.size(); i++) {
                for (int j = 0; j < linked_list[i].size(); j++) {
                    auto& edge = linked_list[i][j];
                    if (dist[i] == INF || edge.capacity == 0) {
                        continue;
                    }
                    int d = edge.distance + dist[i];
                    if (dist[edge.to] > d) {
                        dist[edge.to] = d;
                        prevv[edge.to] = i;
                        preve[edge.to] = j;
                        update = true;
                    }
                }
            }
            if (!update) {
                break;
            }
        }

        if (dist[V - 1] == INF || update) {
            cost = -1;
            break;
        }

        int max_flow = F;
        for (int i = V - 1; i != 0; i = prevv[i]) {
            max_flow = std::min(max_flow, linked_list[prevv[i]][preve[i]].capacity);
        }
        cost += max_flow * dist[V - 1];

        for (int i = V - 1; i != 0; i = prevv[i]) {
            auto& edge = linked_list[prevv[i]][preve[i]];
            edge.capacity -= max_flow;
            linked_list[i][edge.rev].capacity += max_flow;
        }

        F -= max_flow;
    }

    std::cout << cost << std::endl;
}
