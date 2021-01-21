#include <bits/stdc++.h>


int dfs(int idx, int cnt, std::vector<int>& numbers, std::vector<int>& parent, std::vector<int>& lowest,
        std::vector<std::vector<int>>& linked_list) {
    if (numbers[idx] != -1) {
        return cnt;
    }
    numbers[idx] = cnt;
    lowest[idx] = cnt;
    for (auto next : linked_list[idx]) {
        if (numbers[next] == -1) {
            parent[next] = idx;
            cnt = dfs(next, cnt + 1, numbers, parent, lowest, linked_list);
            lowest[idx] = std::min(lowest[idx], lowest[next]);
        } else if (next != parent[idx] && lowest[next] != -1) {
            lowest[idx] = std::min(lowest[idx], numbers[next]);
        }
    }
    return cnt;
}


int main() {
    int V, E;
    std::cin >> V >> E;

    std::vector<std::vector<int>> linked_list(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        std::cin >> s >> t;
        linked_list[s].emplace_back(t);
        linked_list[t].emplace_back(s);
    }

    std::vector<int> numbers(V, -1), parents(V, -1), lowest(V, -1);
    dfs(0, 0, numbers, parents, lowest, linked_list);

    std::vector<std::pair<int, int>> pairs;
    for (int i = 0; i < V; i++) {
        for (auto j : linked_list[i]) {
            if (i > j) {
                continue;
            }
            if (numbers[i] < numbers[j]) {
                if (numbers[i] < lowest[j]) {
                    pairs.emplace_back(std::make_pair(i, j));
                }
            } else {
                if (numbers[j] < lowest[i]) {
                    pairs.emplace_back(std::make_pair(i, j));
                }
            }
        }
    }

    std::sort(pairs.begin(), pairs.end(), [](auto& lhs, auto& rhs) {
        if (lhs.first < rhs.first) {
            return true;
        } else if (lhs.first > rhs.first) {
            return false;
        }
        return lhs.second < rhs.second;
    });

    for (auto pair : pairs) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}
