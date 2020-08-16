#include <bits/stdc++.h>

struct UnionFind {
    int parent;
};


int search(int idx, std::vector<UnionFind>& islands) {
    std::vector<int> indices;
    while (islands[idx].parent != idx) {
        indices.emplace_back(idx);
        idx = islands[idx].parent;
    }
    for (auto i : indices) {
        islands[i].parent = idx;
    }
    return idx;
}

void update(int idx, std::vector<UnionFind> &islands, int parent) {
    auto before = search(idx, islands);
    islands[before].parent = parent;
}

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<long long int, long long int>> bridges;
    for (int i = 0; i < M; i++) {
        long long int a, b;
        std::cin >> a >> b;
        a--; b--;
        bridges.emplace_back(std::make_pair(a, b));
    }

    std::map<long long int, long long int> counts;
    std::vector<UnionFind> islands(N);
    for (int i = 0; i < N; i++) {
        islands[i].parent = i;
        counts[i] = 1;
    }

    std::vector<long long int> output(M);
    output[M - 1] = N * (N - 1) / 2;
    for (int i = M - 2; i >= 0; i--) {
        auto bridge = bridges[i + 1];

        auto lhs = search(bridge.first, islands);
        auto rhs = search(bridge.second, islands);
        long long int c0 = counts[lhs], c1 = counts[rhs];
        long long int diff = c0 * c1;
        if (lhs < rhs) {
            update(rhs, islands, lhs);
            counts[lhs] += counts[rhs];
            counts.erase(rhs);
        } else if (rhs < lhs) {
            update(lhs, islands, rhs);
            counts[rhs] += counts[lhs];
            counts.erase(lhs);
        } else {
            diff = 0;
        }
        output[i] = output[i + 1] - diff;
    }

    for (auto i : output) {
        std::cout << i << std::endl;
    }
}
