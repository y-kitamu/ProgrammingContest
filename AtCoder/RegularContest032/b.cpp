#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> color(N, -1);
    for (int i = 0; i < N; i++)  {
        color[i] = i;
    }

    auto get_root = [&color] (int idx, bool update) {
        std::vector<int> mids;
        while (color[idx] != idx) {
            mids.emplace_back(idx);
            idx = color[idx];
        }
        if (update) {
            for (auto i : mids) {
                color[i] = idx;
            }
        }
        return idx;
    };

    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        int root = get_root(a, true);
        if (color[b] != -1) {
            int sub = get_root(b, true);
            color[sub] = root;
        } else {
            color[b] = root;
        }
    }

    std::set<int> keys;
    for (int i = 0; i < N; i++) {
        keys.insert(get_root(i, true));
    }

    std::cout << keys.size() - 1 << std::endl;
}
