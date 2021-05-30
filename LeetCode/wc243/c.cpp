#include <bits/stdc++.h>


class Solution {
  public:
    std::vector<int> assignTasks(std::vector<int>& servers, std::vector<int>& tasks) {
        auto comp = [&servers](auto& lhs, auto& rhs) {
            if (servers[lhs] == servers[rhs]) {
                return lhs > rhs;
            }
            return servers[lhs] > servers[rhs];
        };
        auto comp0 = [](auto& lhs, auto& rhs) { return lhs[0] > rhs[0]; };
        std::priority_queue<int, std::vector<int>, decltype(comp)> sque{comp};
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(comp0)> pque{
            comp0};
        for (size_t i = 0; i < servers.size(); i++) {
            sque.push(i);
        }

        std::vector<int> ans(tasks.size());
        int time = 0;
        int task_idx = 0;
        while (task_idx < tasks.size()) {
            if (sque.empty()) {
                time = pque.top()[0];
            }
            while (!pque.empty() && pque.top()[0] <= time) {
                auto p = pque.top();
                pque.pop();
                sque.push(p[1]);
            }

            while (!sque.empty() && task_idx <= time) {
                auto server_idx = sque.top();
                sque.pop();
                ans[task_idx] = server_idx;
                pque.push({time + tasks[task_idx], server_idx});
                task_idx++;
                if (task_idx == tasks.size()) {
                    break;
                }
            }
            if (task_idx == tasks.size()) {
                break;
            }
            time++;
        }
        return ans;
    }
};


int main() {}
