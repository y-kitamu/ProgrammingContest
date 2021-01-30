#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> roots(N);
    for (int i = 0; i < N; i++) {
        roots[i] = i;
    }

    auto find_root = [&roots](int idx) {
        std::vector<int> renews;
        while (roots[idx] != idx) {
            renews.emplace_back(idx);
            idx = roots[idx];
        }
        for (auto val : renews) {
            roots[val] = idx;
        }
        return idx;
    };

    std::vector<std::set<int>> linked_list(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        linked_list[a].insert(b);
        linked_list[b].insert(a);

        int ra = find_root(a);
        int rb = find_root(b);
        roots[rb] = ra;
    }

    int K;
    std::cin >> K;
    std::set<int> sets;
    std::vector<int> rs(K);
    for (int i = 0; i < K; i++) {
        int c;
        std::cin >> c;
        c--;
        sets.insert(c);
        rs[i] = find_root(c);
    }

    bool flag = true;
    for (int i = 0; i < K - 1; i++) {
        flag &= rs[i] == rs[i + 1];
    }
    if (!flag) {
        std::cout << -1 << std::endl;
        return 0;
    }
}
