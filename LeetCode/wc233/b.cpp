#include <bits/stdc++.h>

class Solution {
  public:
    int getNumberOfBacklogOrders(std::vector<std::vector<int>>& orders) {
        auto less = [](auto& lhs, auto& rhs) { return lhs.first < rhs.first; };
        auto greater = [](auto& lhs, auto& rhs) { return lhs.first > rhs.first; };

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(greater)>
            sell{greater};
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(less)> buy{
            less};

        for (auto& order : orders) {
            if (order[2] == 0) {
                update(order, sell, std::less_equal<int>());
                if (order[1] > 0) {
                    buy.push(std::make_pair(order[0], order[1]));
                }
            } else {
                update(order, buy, std::greater_equal<int>());
                if (order[1] > 0) {
                    sell.push(std::make_pair(order[0], order[1]));
                }
            }
        }
        return (count(buy) + count(sell)) % MOD;
    }

    template <class T, class Comp>
    void update(std::vector<int>& order, T& backlog, Comp compare) {
        while (order[1] > 0 && !backlog.empty() && compare(backlog.top().first, order[0])) {
            auto top = backlog.top();
            backlog.pop();
            if (order[1] >= top.second) {
                order[1] -= top.second;
            } else {
                backlog.push(std::make_pair(top.first, top.second - order[1]));
                order[1] = 0;
                break;
            }
        }
    }

    template <class T>
    long long int count(T& backlog) {
        // std::cout << std::endl;
        long long int sum = 0;
        while (!backlog.empty()) {
            auto top = backlog.top();
            backlog.pop();
            long long int cnt = top.second;
            // std::cout << top.first << ", " << top.second << std::endl;
            sum = (sum + cnt) % MOD;
        }
        return sum;
    }

    long long int MOD = 1e9 + 7;
};


int main() {}
