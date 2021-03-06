#include <bits/stdc++.h>


using ll = long long int;


struct Node {
    ll dst, weight;
};

struct Status {
    ll dst, tank, cnt;
};


int main() {
    ll N, M, L;
    std::cin >> N >> M >> L;

    std::vector<std::vector<Node>> linked_list(N);

    for (int i = 0; i < M; i++) {
        ll a, b, c;
        std::cin >> a >> b >> c;
        a--;
        b--;
        if (c > L) {
            continue;
        }
        linked_list[a].emplace_back(Node({b, c}));
        linked_list[b].emplace_back(Node({a, c}));
    }

    auto compare = [](Status& lhs, Status& rhs) {
        if (lhs.cnt == rhs.cnt) {
            return lhs.tank < rhs.tank;
        }
        return lhs.cnt > rhs.cnt;
    };

    ll MAX = 1e18;
    std::vector<std::vector<ll>> counts(N, std::vector<ll>(N, MAX));
    for (int i = 0; i < N; i++) {
        // std::cout << i << std::endl;
        std::priority_queue<Status, std::vector<Status>, decltype(compare)> que{compare};
        for (auto& next : linked_list[i]) {
            que.push({next.dst, L - next.weight, 0});
        }

        while (!que.empty()) {
            auto top = que.top();
            que.pop();
            if (counts[i][top.dst] != MAX) {
                continue;
            }
            // std::cout << top.dst << " , " << top.cnt << " , " << top.tank << std::endl;
            counts[i][top.dst] = top.cnt;

            for (auto& next : linked_list[top.dst]) {
                if (counts[i][next.dst] != MAX) {
                    continue;
                }
                if (next.weight > top.tank) {
                    que.push({next.dst, L - next.weight, top.cnt + 1});
                } else {
                    que.push({next.dst, top.tank - next.weight, top.cnt});
                }
            }
        }
    }

    int Q;
    std::cin >> Q;
    for (int i = 0; i < Q; i++) {
        int s, t;
        std::cin >> s >> t;
        s--;
        t--;
        if (counts[s][t] == MAX) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << counts[s][t] << std::endl;
        }
    }
}
