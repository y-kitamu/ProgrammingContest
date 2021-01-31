#include <bits/stdc++.h>


class Solution {
  public:
    std::vector<int> restoreArray(std::vector<std::vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        std::map<int, std::multiset<int>> linked_list;
        for (auto pair : adjacentPairs) {
            linked_list[pair[0]].insert(pair[1]);
            linked_list[pair[1]].insert(pair[0]);
        }

        auto order = [&linked_list](int idx, bool include_first) {
            std::vector<int> forward;
            if (include_first) {
                forward.emplace_back(idx);
            }
            while (linked_list[idx].size() > 0) {
                int next = *linked_list[idx].begin();
                forward.emplace_back(next);
                int cnt = linked_list[idx].erase(next);
                for (int i = 0; i < cnt - 1; i++) {
                    linked_list[idx].insert(next);
                }
                cnt = linked_list[next].erase(idx);
                for (int i = 0; i < cnt - 1; i++) {
                    linked_list[next].insert(idx);
                }
                idx = next;
            }
            return forward;
        };
        std::vector<int> forward = order(adjacentPairs[0][0], true);

        if (forward.size() < n) {
            std::vector<int> backward = order(adjacentPairs[0][0], false);
            std::reverse(backward.begin(), backward.end());
            backward.insert(backward.end(), forward.begin(), forward.end());
            forward = backward;
        }

        for (auto val : forward) {
            std::cout << val << " " << std::endl;
        }
        std::cout << std::endl;
        return forward;
    }
};


int main() {}
