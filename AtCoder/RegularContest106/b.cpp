#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<long long int> a(N), b(N);

    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> b[i];
    }

    std::vector<int> root(N);
    for (int i = 0; i < N; i++) {
        root[i] = i;
    }
    auto find_root = [&root] (int idx) {
        std::vector<int> replace_list;
        while (idx != root[idx]) {
            replace_list.emplace_back(idx);
            idx = root[idx];
        }
        for (auto val: replace_list) {
            root[val] = idx;
        }
        return idx;
    };

    for (int i = 0; i < M; i++) {
        int c, d;
        std::cin >> c >> d;
        c--; d--;
        int root_c = find_root(c);
        int root_d = find_root(d);
        root[root_d] = root_c;
    }

    std::map<int, long long int> sums_a, sums_b;
    for (int i = 0; i < N; i++) {
        int r = find_root(i);
        if (sums_a.find(r) == sums_a.end()) {
            sums_a[r] = 0;
            sums_b[r] = 0;
        }
        sums_a[r] += a[i];
        sums_b[r] += b[i];
    }

    for (auto pair : sums_a) {
        if (pair.second != sums_b[pair.first]) {
            std::cout << "No" <<std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
    return 0;
}
