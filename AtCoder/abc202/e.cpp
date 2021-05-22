#include <bits/stdc++.h>

struct Query {
    int idx;
    int depth;
};


std::vector<int> dfs(int idx, int depth, std::vector<int>& ans, std::vector<int>& counts,
                     const std::vector<std::vector<int>>& ll,
                     const std::vector<std::vector<Query>>& qs) {
    auto var = counts;
    var[depth]++;
    for (auto& child : ll[idx]) {
        dfs(child, depth + 1, ans, var, ll, qs);
    }

    for (auto& q : qs[idx]) {
        ans[q.idx] = var[q.depth];
    }
    return counts;
}


int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> ll(N);
    for (int i = 1; i <= N; i++) {
        int p;
        std::cin >> p;
        p--;
        ll[p].emplace_back(i);
    }

    int Q;
    std::cin >> Q;
    std::vector<std::vector<Query>> qs(N, std::vector<Query>());
    for (int i = 0; i < Q; i++) {
        int u, d;
        std::cin >> u >> d;
        u--;
        qs.emplace_back(Query({i, d}));
    }

    std::vector<int> ans(Q, 0), counts(N, 0);
    dfs(0, ans, counts, ll, qs);

    for (int i = 0; i < Q; i++) {
        std::cout << ans[i] << std::endl;
    }
}
