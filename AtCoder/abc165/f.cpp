#include <bits/stdc++.h>


void dfs(int idx, int len, std::vector<int>& lis, std::vector<int>& cnt, const std::vector<int>& a,
         const std::vector<std::vector<int>>& linked_list) {
    auto itr = std::lower_bound(lis.begin(), lis.begin() + len, a[idx]);
    auto preserve = *itr;
    *itr = a[idx];
    if (itr == lis.begin() + len) {
        len++;
    }
    cnt[idx] = len;

    for (auto& next_idx : linked_list[idx]) {
        if (cnt[next_idx] == 0) {
            dfs(next_idx, len, lis, cnt, a, linked_list);
        }
    }

    *itr = preserve;
}


int main() {
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> linked_list(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        linked_list[u].emplace_back(v);
        linked_list[v].emplace_back(u);
    }

    std::vector<int> lis(N, 2e9), cnt(N, 0);
    dfs(0, 0, lis, cnt, a, linked_list);

    for (int i = 0; i < N; i++) {
        std::cout << cnt[i] << std::endl;
    }
}
