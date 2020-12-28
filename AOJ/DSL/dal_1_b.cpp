#include <bits/stdc++.h>


int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n, 0), roots(n);
    for (int i = 0; i < n; i++) {
        roots[i] = i;
    }

    auto find_root = [&roots, &a] (int idx) {
        std::vector<int> indices;
        int diff = 0;
        while (roots[idx] != idx) {
            indices.emplace_back(idx);
            diff += a[idx];
            idx = roots[idx];
        }
        for (auto i : indices) {
            auto tmp = diff - a[i];
            a[i] = diff;
            diff = tmp;
            roots[i] = idx;
        }
        return idx;
    };

    for (int i = 0; i < q; i++) {
        int val, x, y, z;
        std::cin >> val >> x >> y;
        int root_x = find_root(x);
        int root_y = find_root(y);
        if (val == 0) {
            std::cin >> z;
            a[root_y] = a[root_x] + z + a[x] - a[y];
            roots[root_y] = roots[root_x];
        } else {
            if (root_x != root_y) {
                std::cout << '?' << std::endl;
            } else {
                std::cout << a[y] - a[x] << std::endl;
            }
        }
    }
}
