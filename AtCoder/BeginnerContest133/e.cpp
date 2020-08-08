#include <bits/stdc++.h>


struct Node {
    int idx;
    int parent = -1;
    std::vector<int> childs;
};

long long int N, K;
long long int MOD = 1000000007;

long long int search(int idx, long long int val, std::vector<Node>& nodes) {
    long long int next_val = std::max(val - 1, K - 2);
    for (int i = 0; i < nodes[idx].childs.size(); i++) {
        val = (val * search(nodes[idx].childs[i], next_val - i, nodes)) % MOD;
    }
    return val;
}

int main() {
    std::cin >> N >> K;

    std::vector<std::vector<int>> linked_list(N);
    std::vector<Node> nodes(N);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        linked_list[a].emplace_back(b);
        linked_list[b].emplace_back(a);
    }

    nodes[0].parent = 0;
    std::queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int idx = que.front();
        que.pop();
        for (auto next_idx : linked_list[idx]) {
            if (nodes[next_idx].parent == -1) {
                que.push(next_idx);
                nodes[next_idx].parent = idx;
                nodes[idx].childs.emplace_back(next_idx);
            }
        }
    }


    std::cout << search(0, K, nodes) << std::endl;;
}
