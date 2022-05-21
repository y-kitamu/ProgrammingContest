/**
 * @file e.CPO
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-21 21:33:43
 */
#include <bits/stdc++.h>

struct Node {
    long long a, b, c, idx;
};


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<Node*>> linked_list(N);
    for (int i = 0; i < M; i++) {
        long long a, b, c;
        std::cin >> a >> b >> c;
        a--, b--;
        auto node = new Node{a, b, c, i};
        linked_list[a].emplace_back(node);
        linked_list[b].emplace_back(node);
    }

    auto comp = [](std::vector<long long>& lhs, std::vector<long long>& rhs) { return lhs[1] > rhs[1]; };
    std::priority_queue<std::vector<long long>, std::vector<std::vector<long long>>, decltype(comp)> que{
        comp};
    for (auto& next : linked_list[0]) {
        auto idx = next->b;
        que.push({idx, next->c, next->idx});
    }

    std::vector<int> flag(N, 0);
    flag[0] = 1;
    std::vector<int> ans;
    while (!que.empty()) {
        auto top = que.top();
        que.pop();
        if (flag[top[0]] == 0) {
            ans.emplace_back(top[2]);
            flag[top[0]] = 1;
            for (auto& next : linked_list[top[0]]) {
                auto idx = next->a == top[0] ? next->b : next->a;
                if (flag[idx] == 0) {
                    que.push({idx, top[1] + next->c, next->idx});
                }
            }
        }
        if (ans.size() == N - 1) {
            break;
        }
    }

    for (int i = 0; i < N - 1; i++) {
        std::cout << ans[i] + 1;
        if (i < N - 2) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}
