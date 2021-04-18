#include <bits/stdc++.h>


class Solution {
  public:
    std::vector<int> getOrder(std::vector<std::vector<int>>& tasks) {
        std::vector<int> indices(tasks.size());
        std::iota(indices.begin(), indices.end(), 0);
        std::sort(indices.begin(), indices.end(),
                  [&tasks](auto& lhs, auto& rhs) { return tasks[lhs][0] < tasks[rhs][0]; });

        // 0 : idx, 1 : processing time
        auto comp = [](auto& lhs, auto& rhs) {
            if (lhs.second > rhs.second) {
                return true;
            } else if (lhs.second < rhs.second) {
                return false;
            }
            return lhs.first > rhs.first;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> que{
            comp};
        que.push(std::make_pair(indices[0], tasks[indices[0]][1]));
        long long int time = tasks[indices[0]][0];
        int idx = 1;
        std::vector<int> order;
        while (true) {
            while (idx < tasks.size() && tasks[indices[idx]][0] <= time) {
                que.push(std::make_pair(indices[idx], tasks[indices[idx]][1]));
                idx++;
            }
            if (que.empty()) {
                time = tasks[indices[idx]][0];
                que.push(std::make_pair(indices[idx], tasks[indices[idx]][1]));
                idx++;
            }
            auto top = que.top();
            que.pop();
            order.emplace_back(top.first);
            time += top.second;
            if (idx >= tasks.size() && que.empty()) {
                break;
            }
        }
        return order;
    }
};

int main() {}
