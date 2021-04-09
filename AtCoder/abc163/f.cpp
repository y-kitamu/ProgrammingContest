#include <bits/stdc++.h>


using ll = long long int;


ll count_path(ll n) {
    auto ans = n * (n - 1) / 2;
    return ans + n;
}


int dfs(int idx, int parent, int cnt, std::vector<ll>& count, std::vector<ll>& sum,
        const std::vector<int>& colors, const std::vector<std::vector<ll>>& linked_list) {
    auto cur = cnt;
    cnt++;
    ll bef;
    if (parent >= 0) {
        bef = count[colors[parent]];
    }
    for (auto& next : linked_list[idx]) {
        if (next != parent) {
            cnt = dfs(next, idx, cnt, count, sum, colors, linked_list);
        }
    }
    if (parent >= 0) {
        sum[colors[parent]] += count_path(cnt - cur - (count[colors[parent]] - bef));
        count[colors[parent]] = bef + cnt - cur;
    }
    count[colors[idx]] += 1;
    return cnt;
}


int main() {
    int N;
    std::cin >> N;

    std::vector<int> colors(N);
    for (int i = 0; i < N; i++) {
        std::cin >> colors[i];
        colors[i]--;
    }

    std::vector<std::vector<ll>> linked_list(N);

    for (int i = 0; i < N - 1; i++) {
        ll a, b;
        std::cin >> a >> b;
        a--, b--;
        linked_list[a].emplace_back(b);
        linked_list[b].emplace_back(a);
    }

    std::vector<ll> counts(N, 0), sum(N, 0);
    dfs(0, -1, 0, counts, sum, colors, linked_list);
    for (int i = 0; i < N; i++) {
        if (colors[0] == i) {
            continue;
        }
        sum[i] += count_path(N - counts[i]);
    }

    ll all = count_path(N);
    for (int i = 0; i < N; i++) {
        std::cout << all - sum[i] << std::endl;
    }
}
