#include <bits/stdc++.h>


class Solution {
  public:
    int maxIceCream(std::vector<int>& costs, int coins) {
        std::sort(costs.begin(), costs.end());
        int idx = 0;
        while (idx < costs.size() && coins - costs[idx] >= 0) {
            coins -= costs[idx];
            idx++;
        }
        return idx;
    }
};

int main() {}
