#include <bits/stdc++.h>

struct Link {
    Link() {}
    Link(int from, int to, long long int weight): from(from), to(to), weight(weight) {}
    void print() {
        std::cout << from << " , " << to << " , " << weight << std::endl;
    }
    int from, to;
    long long int weight;
};


bool has_root(int from, int to, const std::vector<std::vector<int>> ll) {
    int N = ll.size();
    std::vector<bool> reached(N, false);
    std::queue<int> que;
    que.push(from);

    bool has_root = false;
    while (!que.empty()) {
        int node = que.front();
        que.pop();
        if (reached[node] == true) {
            continue;
        }
        reached[node] = true;
        if (node == to) {
            has_root = true;
            break;
        }
        for (auto next : ll[node]) {
            if (reached[next] == false) {
                que.push(next);
            }
        }
    }
    return has_root;
}


int main() {
    int N, M, P;
    std::cin >> N >> M >> P;

    std::vector<Link> linked_list(M);
    std::vector<std::vector<int>> ll(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--; b--;
        c -= P;
        linked_list[i] = Link(a, b, c);
        ll[a].emplace_back(b);
    }

    std::vector<long long int> cost(N, -1e9);
    cost[0] = 0;
    std::vector<int> loop_indices;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            Link link = linked_list[j];
            // std::cout << cost[link.to] << " , "; link.print();
            if (cost[link.to] < cost[link.from] + link.weight) {
                cost[link.to] = cost[link.from] + link.weight;
                if (i == N) {
                    loop_indices.emplace_back(link.to);
                }
            }
        }
    }

    bool has_loop = false;
    for (auto idx : loop_indices) {
        if (has_root(0, idx, ll) & has_root(idx, N - 1, ll)) {
            has_loop = true;
            break;
        }
    }

    if (has_loop) {
        std::cout << -1 << std::endl;
    } else if (cost[N - 1] < 0) {
      std::cout << 0 << std::endl;
    } else {
        std::cout << cost[N - 1] << std::endl;
    }
}
