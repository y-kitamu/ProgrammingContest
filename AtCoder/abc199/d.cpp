#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> linked_list(N);
    std::vector<int> roots(N);
    std::iota(roots.begin(), roots.end(), 0);

    auto find_root = [&roots](int idx) {
        std::vector<int> updates;
        while (roots[idx] != idx) {
            updates.emplace_back(idx);
            idx = roots[idx];
        }
        for (auto& i : updates) {
            roots[i] = idx;
        }
        return idx;
    };

    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        linked_list[a].emplace_back(b);
        linked_list[b].emplace_back(a);
        auto ra = find_root(a);
        auto rb = find_root(b);
        roots[rb] = ra;
    }

    long long int sum = 1;
    std::vector<int> cols(N, 0);
    for (int i = 0; i < N; i++) {
        if (find_root(i) == i) {
        }
    }

    std::cout << sum << std::endl;
}
