#include <bits/stdc++.h>

int N, M, S, T;
std::vector<std::vector<int>> linked_list;
std::vector<std::set<int>> one_step;

void calc_step(int step, int idx, int start_idx) {
    if (step == 3) {
        one_step[start_idx].insert(idx);
        return;
    }
    for (auto next_idx : linked_list[idx]) {
        calc_step(step + 1, next_idx, start_idx);
    }
}

int main() {
    std::cin >> N >> M;

    linked_list = std::vector<std::vector<int>>(N, std::vector<int>());
    for (int i = 0; i < M ; i++) {
        int u, v;
        std::cin >> u >> v;
        linked_list[u - 1].emplace_back(v - 1);
    }

    one_step = std::vector<std::set<int>>(N, std::set<int>());
    for (int i = 0; i < N; i++) {
        calc_step(0, i, i);
    }

    std::cin >> S >> T;
    S--;
    T--;

    std::vector<int> nodes(N, -1);
    std::queue<std::pair<int, int>> queue;

    nodes[S] = 0;
    queue.push(std::make_pair(S, 1));
    while (!queue.empty()) {
        auto q = queue.front();
        queue.pop();
        for (auto idx : one_step[q.first]) {
            if (nodes[idx] == -1) {
                nodes[idx] = q.second;
                queue.push(std::make_pair(idx, q.second + 1));
            }
        }
    }

    std::cout << nodes[T] << std::endl;
}
