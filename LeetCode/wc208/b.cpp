#include <bits/stdc++.h>


class Solution {
public:
    int minOperationsMaxProfit(std::vector<int>& customers, int boardingCost, int runningCost) {
        int n_rotations = customers.size();
        int max_profit = 0, max_cnt = 0, profit = 0, cnt = 0;
        int waiting = 0;
        for (cnt = 0; cnt < n_rotations; cnt++) {
            int n_customer = customers[cnt] + waiting;
            if (n_customer >= 4) {
                waiting = n_customer - 4;
                n_customer = 4;
            }
            profit += boardingCost * n_customer - runningCost;
            if (max_profit < profit) {
                max_profit = profit;
                max_cnt = cnt + 1;
            }
        }
        while (waiting > 0) {
            int n_customer = std::min(4, waiting);
            profit += boardingCost * n_customer - runningCost;
            waiting -= n_customer;
            cnt++;
            if (max_profit < profit) {
                max_profit = profit;
                max_cnt = cnt;
            }
        }

        if (max_profit == 0) {
            max_cnt = -1;
        }
        return max_cnt;
    }
};


int main() {
    std::vector<int> customers {
        10,10,1,0,0
        // 3,4,0,5,1
        // 10, 10, 6, 4, 7
    };
    int boardingCost = 4, runningCost = 4;
    std::cout << Solution().minOperationsMaxProfit(customers, boardingCost, runningCost) << std::endl;;
}
