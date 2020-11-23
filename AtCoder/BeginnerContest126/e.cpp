#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> roots(N);
    for (int i = 0; i < N; i++) {
        roots[i] = i;
    }

    auto find_root = [&roots] (int idx) {
        std::vector<int> vals;
        while (idx != roots[idx]) {
            vals.emplace_back(idx);
            idx = roots[idx];
        }
        for (auto val : vals) {
            roots[val] = idx;
        }
        return idx;
    };

    for (int i = 0; i < M; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        x--; y--;
        int rx = find_root(x);
        int ry = find_root(y);
        roots[ry] = rx;
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (i == roots[i]) {
            cnt++;
        }
    }

    std::cout << cnt << std::endl;
}
