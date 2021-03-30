#include <bits/stdc++.h>


int main() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<std::vector<int>> linked_list(N);
    std::vector<int> roots(N);
    std::iota(roots.begin(), roots.end(), 0);

    auto find_root = [&roots](int a) {
        std::vector<int> idx;
        while (roots[a] != a) {
            idx.emplace_back(a);
            a = roots[a];
        }
        for (auto& i : idx) {
            roots[i] = a;
        }
        return a;
    };

    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        roots[find_root(b)] = find_root(a);
        linked_list[a].emplace_back(b);
        linked_list[b].emplace_back(a);
    }

    for (int i = 0; i < K; i++) {
        int c, d;
        std::cin >> c >> d;
        c--;
        d--;
        if (find_root(c) == find_root(d)) {
            linked_list[c].emplace_back(d);
            linked_list[d].emplace_back(c);
        }
    }

    std::map<int, int> counts;
    for (int i = 0; i < N; i++) {
        int idx = find_root(i);
        if (counts.find(idx) == counts.end()) {
            counts[idx] = 0;
        }
        counts[idx]++;
    }

    for (int i = 0; i < N; i++) {
        std::cout << counts[find_root(i)] - linked_list[i].size() - 1;
        if (i < N - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}
