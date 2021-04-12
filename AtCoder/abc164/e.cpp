#include <bits/stdc++.h>


using ll = long long int;


struct Train {
    ll dst, a, b;
};


struct City {
    ll c, d;
};


struct Status {
    ll cash, time, city;
};


int main() {
    int N, M, S;
    std::cin >> N >> M >> S;
    std::vector<std::vector<Train>> trains(N);
    for (int i = 0; i < M; i++) {
        int u, v, a, b;
        std::cin >> u >> v >> a >> b;
        u--, v--;
        trains[u].emplace_back(Train({v, a, b}));
        trains[v].emplace_back(Train({u, a, b}));
    }

    std::vector<City> cities(N);
    for (int i = 0; i < N; i++) {
        std::cin >> cities[i].c >> cities[i].d;
    }

    auto comp = [](auto& lhs, auto& rhs) {
        if (lhs.time > rhs.time) {
            return true;
        } else if (lhs.time < rhs.time) {
            return false;
        }
        return lhs.cash < rhs.cash;
    };
    std::priority_queue<Status, std::vector<Status>, decltype(comp)> que{comp};
    que.push(Status({S, 0, 0}));

    ll MAX = 1e18;
    std::vector<ll> cost(N, MAX);
    std::vector<ll> cash(N, 0);
    cost[0] = 0;
    while (!que.empty()) {
        auto cur = que.top();
        if (cur.time < cost[cur.city]) {
            cost[cur.city] = cur.time;
            cash[cur.city] = cur.cash;
        }
        que.pop();

        if (cur.cash < 5000) {
            que.push(Status({cur.cash + cities[cur.city].c, cur.time + cities[cur.city].d, cur.city}));
        }
        for (auto& t : trains[cur.city]) {
            if (cur.cash >= t.a) {
                auto nc = cur.cash - t.a;
                auto nt = cur.time + t.b;
                if (nc > cash[t.dst] || nt < cost[t.dst]) {
                    que.push(Status({nc, nt, t.dst}));
                }
            }
        }

        bool flag = true;
        for (int i = 0; i < N; i++) {
            flag &= cost[i] != MAX;
        }
        if (flag) {
            break;
        }
    }

    for (int i = 1; i < N; i++) {
        std::cout << cost[i] << std::endl;
    }
}
