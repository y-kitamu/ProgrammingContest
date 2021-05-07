#include <bits/stdc++.h>


bool check(int idx, std::vector<int>& color, std::vector<std::vector<int>>& ll) {
    auto c = color[idx];
    for (auto& i : ll[idx]) {
        if (c == color[i]) {
            return false;
        }
    }
    return true;
}


long long int dfs(int c, int idx, std::vector<int> color, std::vector<int>& reached,
                  std::vector<std::vector<int>>& ll) {
    color[idx] = c;
    reached[idx] = 1;

    if (!check(idx, color, ll)) {
        return 0;
    }

    long long int sum = 1;
    for (auto& next : ll[idx]) {
        if (reached[next] == 0) {
            auto cnt = 0;
            std::vector<int> cr = reached;
            cnt += dfs((color[idx] + 1) % 3, next, color, cr, ll);
            cnt += dfs((color[idx] + 2) % 3, next, color, reached, ll);
            sum *= cnt;
        }
    }
    return sum;
}


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> ll(N);
    std::vector<int> roots(N);
    std::iota(roots.begin(), roots.end(), 0);
    auto find_root = [&roots](auto idx) {
        std::vector<int> update;
        while (roots[idx] != idx) {
            update.emplace_back(idx);
            idx = roots[idx];
        }
        for (auto& i : update) {
            roots[i] = idx;
        }
        return idx;
    };

    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        auto ra = find_root(a);
        auto rb = find_root(b);
        roots[rb] = ra;
        ll[a].emplace_back(b);
        ll[b].emplace_back(a);
    }

    long long int sum = 1;
    std::vector<int> reached(N, 0), color(N, -1);
    for (int i = 0; i < N; i++) {
        if (roots[i] != i) {
            continue;
        }
        sum *= 3 * dfs(0, i, color, reached, ll);
    }

    std::cout << sum << std::endl;
}
