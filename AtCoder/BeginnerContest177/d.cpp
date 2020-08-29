#include <bits/stdc++.h>




int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> F(N, -1);

    auto get_parent = [&F] (int idx) {
        int parent = idx;
        while (F[parent] != -1) {
            parent = F[parent];
        }
        int i = idx;
        while (F[i] != -1) {
            F[i] = parent;
            i = F[i];
        }
        return parent;
    };

    std::vector<int> count(N, 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        int pa = get_parent(a);
        int pb = get_parent(b);
        if (pa != pb) {
            F[pb] = pa;
            F[b] = pa;
            count[pa] += count[pb];
            count[pb] = 0;
        }
    }

    int max = count[0];
    for (int i = 0; i < N; i++) {
        max = std::max(max, count[i]);
    }
    std::cout << max << std::endl;
}
