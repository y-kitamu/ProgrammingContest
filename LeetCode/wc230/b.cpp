#include <bits/stdc++.h>

class Solution {
  public:
    int closestCost(std::vector<int>& baseCosts, std::vector<int>& toppingCosts, int target) {
        int n = baseCosts.size(), m = toppingCosts.size();

        int min_diff = 1e5;
        int min_val = 0;

        for (int i = 0; i < n; i++) {
            std::vector<int> costs(1 << m, 0);
            for (int j = 0; j < 1 << m; j++) {
                for (int k = 0; k < m; k++) {
                    if (j >> k & 1) {
                        costs[j] += toppingCosts[k];
                    }
                }
            }
            std::sort(costs.begin(), costs.end());
            int left = 0, right = (1 << m) - 1;
            while (left <= right) {
                int val = costs[left] + costs[right] + baseCosts[i];
                int diff = std::abs(val - target);
                if (diff < min_diff) {
                    min_diff = diff;
                    min_val = val;
                } else if (diff == min_diff && val < min_val) {
                    min_val = val;
                }
                if (val < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return min_val;
    }
};


int main() {}
