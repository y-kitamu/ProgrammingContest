#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> linked_list(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        linked_list[u].emplace_back(v);
    }
    int S, T;
    std::cin >> S >> T;
    S--; T--;

    std::vector<int> count(N, -1);
    std::queue<std::pair<int, int>> que;
    que.push(std::make_pair(S, 0));

}
