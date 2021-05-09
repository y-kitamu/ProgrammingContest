#include <bits/stdc++.h>

class Solution {
  public:
    int maximumPopulation(std::vector<std::vector<int>>& logs) {
        auto comp = [](auto& lhs, auto& rhs) {
            if (lhs.first == rhs.first) {
                return lhs.second > rhs.second;
            }
            return lhs.first > rhs.first;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> que{
            comp};

        for (auto& val : logs) {
            que.push(std::make_pair(val[0], 1));
            que.push(std::make_pair(val[1], -1));
        }

        int max = 0;
        int max_year = 0;
        int sum = 0;
        while (!que.empty()) {
            auto top = que.top();
            que.pop();
            sum += top.second;
            if (sum > max) {
                max_year = top.first;
                max = sum;
            }
        }
        return max_year;
    }
};


int main() {}
