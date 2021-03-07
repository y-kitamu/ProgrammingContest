#include <bits/stdc++.h>

class Solution {
  public:
    struct Edge {
        int src, dst, weight;
    };

    std::vector<int> index_sort(std::vector<int>& vec) {
        std::vector<int> idx(vec.size());
        std::iota(idx.begin(), idx.end(), 0);

        auto comp = [&vec] (auto lhs, auto rhs) {
            return vec[lhs] > vec[rhs];
        };
        std::sort(idx.begin(), idx.end(), comp);
        return idx;
    }

    int countRestrictedPaths(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<Edge>> linked_list(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0] - 1, v = edges[i][1] - 1;
            linked_list[u].emplace_back(Edge({u, v, edges[i][2]}));
            linked_list[v].emplace_back(Edge({v, u, edges[i][2]}));
        }

        auto compare = [](auto& lhs, auto& rhs) { return lhs.weight > rhs.weight; };
        std::priority_queue<Edge, std::vector<Edge>, decltype(compare)> que(compare);
        for (auto& edge : linked_list[n - 1]) {
            que.push(edge);
        }
        std::vector<int> dist(n, -1);
        dist[n - 1] = 0;
        while (!que.empty()) {
            auto top = que.top();
            que.pop();
            if (dist[top.dst] != -1) {
                continue;
            }
            dist[top.dst] = top.weight;
            for (auto next : linked_list[top.dst]) {
                if (dist[next.dst] == -1) {
                    next.weight += dist[top.dst];
                    que.push(next);
                }
            }
        }

        std::vector<std::vector<int>> res_ll(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0] - 1, v = edges[i][1] - 1;
            if (dist[u] > dist[v]) {
                res_ll[u].emplace_back(v);
                // std::cout << u << " , " << v << std::endl;
            } else if (dist[u] < dist[v]) {
                res_ll[v].emplace_back(u);
                // std::cout << v << " , " << u << std::endl;
            }
        }

        std::vector<int> sorted = index_sort(dist);

        std::vector<long long int> cnts(n, 0);
        cnts[0] = 1;
        for (int i = 0; i < n; i++) {
            int idx = sorted[i];
            for (auto&& next : res_ll[idx]) {
                cnts[next] = (cnts[idx] + cnts[next]) % MOD;
            }
        }
        // std::cout << cnts[n - 1] << std::endl;
        return cnts[n - 1];
        // std::vector<long long int> counts(n, -1);
        // counts[n - 1] = 1;
        // return search(0, counts, res_ll);
    }

    // long long int search(int idx, std::vector<long long int>& counts,
    //                      std::vector<std::vector<int>> llist) {
    //     if (counts[idx] != -1) {
    //         return counts[idx];
    //     }
    //     counts[idx] = 0;
    //     for (auto next : llist[idx]) {
    //         counts[idx] = (counts[idx] + search(next, counts, llist)) % MOD;
    //     }
    //     return counts[idx];
    // }

    long long int MOD = 1e9 + 7;
};


int main() {}
