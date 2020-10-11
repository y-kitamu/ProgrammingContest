#include <bits/stdc++.h>

class Solution {
public:
    int nodes;
    std::vector<std::vector<int>> all_edges;

    std::vector<int> countSubgraphsForEachDiameter(int n, std::vector<std::vector<int>>& edges) {
        nodes = n;
        all_edges = edges;
        return all_search(0, std::vector<std::vector<int>>());
    }

    std::vector<int> all_search(int idx, std::vector<std::vector<int>> edges) {
        std::vector<int> cnts(nodes, 0);
        if (nodes == idx) {
            count(edges, cnts);
            return cnts;
        }
        auto cnts0 = all_search(idx + 1, edges);
        edges.push_back(all_edges[idx]);
        auto cnts1 = all_search(idx + 1, edges);
        for (int i = 0; i < nodes; i++) {
            cnts[i] = cnts0[i] + cnts1[i];
        }
        return cnts;
    }

    void count(std::vector<std::vector<int>> edges, std::vector<int>& cnts) {
        std::vector<int> roots(nodes);
        for (int i = 0; i < nodes; i++) {
            roots[i] = i;
        }
        std::vector<std::vector<int>> linked_list(nodes, std::vector<int>());

        auto find_root = [&roots] (int idx) {
            std::vector<int> replace;
            while (roots[idx] != idx) {
                replace.emplace_back(idx);
                idx = roots[idx];
            }
            for (auto val : replace) {
                roots[val] = idx;
            }
            return idx;
        };
        for (auto edge : edges) {
            int root0 = find_root(edge[0]);
            int root1 = find_root(edge[1]);
            roots[root0] = root1;
            linked_list[edge[1]].emplace_back(edge[0]);
            linked_list[edge[0]].emplace_back(edge[1]);
        }

        for (int i = 0; i < nodes; i++) {
            if (linked_list[i].empty()) {
                continue;
            }
            if (roots[i] != i) {
                continue;
            }
            auto res = count_impl(i, linked_list);
            cnts[std::max(res[0], res[1])]++;
        }
    }

    std::vector<int> count_impl(int idx, std::vector<std::vector<int>>& linked_list) {
        if (linked_list[idx].empty()) {
            return std::vector<int>({1, 1});
        }

        int max0 = 0, max1 = 0, max2 = 0;
        for (int i = 0; i < linked_list[idx].size(); i++) {
            auto res = count_impl(linked_list[idx][i], linked_list);
            if (res[0] > max0) {
                max1 = max0 + res[0];
                max0 = res[0];
            }
            if (i > 0 && max0 == max1) {
                max1 += res[0];
            }
            max2 = std::max(res[1], max2);
        }
        return std::vector<int>({max0, std::max(max1, max2)});
    }
};


int main() {

}
