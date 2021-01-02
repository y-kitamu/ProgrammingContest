#include <bits/stdc++.h>




int main() {
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> edges(N - 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        edges.emplace_back(std::make_pair(a, b));
    }

    int Q;
    std::cin >> Q;
    for (int i = 0; i < Q; i++) {
        int t, e, x;
        std::cin >> t >> e >> x;
        if (t == 1) {

        } else {

        }
    }
}
