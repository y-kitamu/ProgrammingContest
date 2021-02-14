#include <bits/stdc++.h>

class Solution {
  public:
    int minTrioDegree(int n, std::vector<std::vector<int>>& edges) {
        std::vector<bool> is_trio(n, false);

        std::vector<std::vector<int>> linked_list(n);
        std::vector<std::vector<int>> linked_mat(n, std::vector<int>(n, 0));

        for (auto& edge : edges) {
            edge[0]--, edge[1]--;
            linked_list[edge[0]].emplace_back(edge[1]);
            linked_list[edge[1]].emplace_back(edge[0]);
            linked_mat[edge[0]][edge[1]] = 1;
            linked_mat[edge[1]][edge[0]] = 1;
        }

        const int MAX = 1e9;
        int min_edges = MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < linked_list[i].size(); j++) {
                int lj = linked_list[i][j];
                for (int k = j + 1; k < linked_list[i].size(); k++) {
                    int lk = linked_list[i][k];
                    if (linked_mat[lj][lk] == 1) {
                        int num =
                            linked_list[i].size() + linked_list[lj].size() + linked_list[lk].size() - 6;
                        min_edges = std::min(num, min_edges);
                    }
                }
            }
        }
        if (min_edges == MAX) {
            min_edges = -1;
        }

        return min_edges;
    }
};


int main() {}
