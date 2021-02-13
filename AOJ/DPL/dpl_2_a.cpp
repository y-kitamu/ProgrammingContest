#include <bits/stdc++.h>

int main() {
    constexpr int INF = 1e9;
    int V, E;
    std::cin >> V >> E;

    std::vector<std::vector<int>> linked_mat(V, std::vector<int>(V, INF));
    for (int i = 0; i < E; i++) {
        int s, t, d;
        std::cin >> s >> t >> d;
        linked_mat[s][t] = d;
    }

    std::vector<std::vector<int>> dp(1 << V, std::vector<int>(V, INF));
    dp[(1 << V) - 1][0] = 0;

    for (int S = (1 << V) - 2; S >= 0; S--) {
        for (int v = 0; v < V; v++) {
            for (int u = 0; u < V; u++) {
                if (!(S >> u & 1)) {
                    dp[S][v] = std::min(dp[S][v], dp[S | (1 << u)][u] + linked_mat[v][u]);
                }
            }
            // std::cout << dp[S][v] << " ";
        }
        // std::cout << std::endl;
    }
    if (dp[0][0] == INF) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << dp[0][0] << std::endl;
    }
}
