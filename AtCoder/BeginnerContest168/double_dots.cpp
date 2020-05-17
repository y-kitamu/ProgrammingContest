#include <bits/stdc++.h>

struct Node {
    int idx;
    int parent = -1;
};

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> links(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        links[a].emplace_back(b);
        links[b].emplace_back(a);
    }

    std::vector<Node> nodes(N);
    for (int i = 0; i < N; i++) {
        nodes[i].idx = i;
    }

    std::queue<Node> que;
    que.push(nodes[0]);

    while (!que.empty()) {
        auto q = que.front();
        que.pop();
        for (auto && link : links[q.idx]) {
            if (nodes[link].parent == -1) {
                nodes[link].parent = q.idx;
                que.push(nodes[link]);
            }
        }
    }

    std::cout << "Yes" << std::endl;
    for (int i = 1; i < N; i++) {
        std::cout << nodes[i].parent + 1 << std::endl;
    }
}
