#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> union_find(N);
    for (int i = 0; i < N; i++) {
        union_find[i] = i;
    }

    auto find_root = [&union_find](int idx) {
        std::vector<int> inter;
        while (union_find[idx] != idx) {
            inter.emplace_back(idx);
            idx = union_find[idx];
        }
        for (auto i : inter) {
            union_find[i] = idx;
        }
        return idx;
    };

    int a, b;
    for (int i = 0; i < M; i++) {
        std::cin >> a >> b;
        a--; b--;
        int root_a = find_root(a);
        int root_b = find_root(b);
        if (root_a != root_b) {
            union_find[root_a] = root_b;
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int root = find_root(i);
        if (root == i) {
            cnt++;
        }
    }
    std::cout << cnt - 1 << std::endl;
}
