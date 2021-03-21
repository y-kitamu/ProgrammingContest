#include <bits/stdc++.h>


int main() {
    long long int MOD = 998244353;

    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> linked_list(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        linked_list[a].emplace_back(b);
        linked_list[b].emplace_back(a);
    }
}
