#include <bits/stdc++.h>


struct Edge {
    Edge() {}
    Edge(int to, int capacity, int dist, int rev) : to(to), capacity(capacity), dist(dist), rev(rev) {}
    int to, capacity = 1, dist = 1, rev;
};


int dfs(int idx, int flaw, int to, std::vector<std::vector<Edge>>& linked_list,
        std::vector<bool>& used) {
    if (idx == to) {
        return flaw;
    }

    used[idx] = true;
    int max_flaw = flaw;
    for (auto& next : linked_list[idx]) {
        if (next.capacity > 0 && !used[next.to]) {
            int f = std::min(flaw, next.capacity);
            f = dfs(next.to, f, to, linked_list, used);
            flaw -= f;
            next.capacity -= f;
            linked_list[next.to][next.rev].capacity += f;
        }
        if (flaw == 0) {
            break;
        }
    }
    return max_flaw - flaw;
}


int max_flow(int X, int Y, int start, int to, std::vector<std::vector<Edge>>& linked_list) {
    int flaw = 0;
    for (;;) {
        std::vector<bool> used(X + Y + 2, false);
        int f = dfs(start, X, to, linked_list, used);
        flaw += f;
        if (f == 0) {
            break;
        }
    }
    return flaw;
}


int main() {
    int X, Y, E;
    std::cin >> X >> Y >> E;

    int start = 0, to = X + Y + 1;
    std::vector<std::vector<Edge>> linked_list(to + 1);

    for (int i = 0; i < X; i++) {
        linked_list[start].emplace_back(Edge(i + 1, 1, 1, linked_list[i + 1].size()));
        linked_list[i + 1].emplace_back(Edge(start, 0, -1, linked_list[start].size() - 1));
    }

    for (int i = 0; i < Y; i++) {
        linked_list[X + i + 1].emplace_back(Edge(to, 1, 1, linked_list[to].size()));
        linked_list[to].emplace_back(Edge(X + i + 1, 0, -1, linked_list[X + i + 1].size()));
    }

    for (int i = 0; i < E; i++) {
        int x, y;
        std::cin >> x >> y;
        x++, y++;
        linked_list[x].emplace_back(Edge(X + y, 1, 1, linked_list[X + y].size()));
        linked_list[X + y].emplace_back(Edge(x, 0, -1, linked_list[x].size() - 1));
    }

    std::cout << max_flow(X, Y, start, to, linked_list) << std::endl;
}
