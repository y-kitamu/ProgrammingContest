#include <bits/stdc++.h>


struct Edge {
    int from, to, dist;
};


int main() {
    constexpr int INF = 1e9;

    int V, E;
    std::cin >> V >> E;

    std::vector<std::vector<Edge>> linked_list(V);
    std::vector<std::vector<int>> dist(V, std::vector<int>(V, INF));
    int total = 0;
    for (int i = 0; i < E; i++) {
        int s, t, d;
        std::cin >> s >> t >> d;
        linked_list[s].emplace_back((Edge){s, t, d});
        linked_list[t].emplace_back((Edge){t, s, d});
        dist[s][t] = std::min(d, dist[s][t]);
        dist[t][s] = std::min(d, dist[t][s]);
        total += d;
    }

    std::vector<int> odds;
    for (int i = 0; i < V; i++) {
        if (linked_list[i].size() & 1) {
            odds.emplace_back(i);
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int k = odds.size();
    std::vector<int> dp(1 << k, INF);
    dp[0] = 0;
    for (int S = 0; S < 1 << k; S++) {
        for (int i = 0; i < k; i++) {
            if (~S >> i & 1) {
                for (int j = 0; j < i; j++) {
                    if (~S >> j & 1) {
                        dp[S | 1 << i | 1 << j] =
                            std::min(dp[S | 1 << i | 1 << j], dp[S] + dist[odds[i]][odds[j]]);
                    }
                }
            }
        }
    }
    std::cout << total + dp[(1 << k) - 1] << std::endl;
}
