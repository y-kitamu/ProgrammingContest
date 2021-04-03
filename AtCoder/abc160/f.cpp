#include <bits/stdc++.h>

using ll = long long int;

const int MAX = 510000;
const int MOD = 1000000007;


struct Node {
    ll n_nodes, n_orders;
};


ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


ll calc(int root, int parent, std::map<std::pair<int, int>, Node>& dp,
        std::vector<std::vector<int>>& linked_list) {
    auto idx = std::make_pair(root, parent);
    if (dp.find(idx) != dp.end()) {
        return dp[idx].n_nodes;
    }
    ll cnt = linked_list[root].size() - 1;
    if (cnt == 0 && parent != -1) {
        dp[idx] = Node({1, 1});
        return dp[idx].n_nodes;
    }

    for (auto& idx : linked_list[root]) {
        if (idx != parent) {
            cnt += calc(idx, root, dp, linked_list);
        }
    }

    ll n_nodes = cnt;
    ll n_orders = 1;
    for (auto& idx : linked_list[root]) {
        auto& node = dp[std::make_pair(idx, root)];
        ll comb = COM(cnt, node.n_nodes);
        n_orders = n_orders * (comb * node.n_orders % MOD) % MOD;
        cnt -= node.n_nodes;
    }

    dp[idx] = Node({n_nodes, n_orders});
    return dp[idx].n_nodes;
}


int main() {
    COMinit();

    int N;
    std::cin >> N;

    std::vector<std::vector<int>> linked_list(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        linked_list[a].emplace_back(b);
        linked_list[b].emplace_back(a);
    }

    std::map<std::pair<int, int>, Node> dp;
    for (int i = 0; i < N; i++) {
        calc(i, -1, dp, linked_list);
        std::cout << dp[std::make_pair(i, -1)].n_orders << std::endl;
    }
}
