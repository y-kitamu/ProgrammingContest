#include <bits/stdc++.h>

class Solution {
public:
    int maximumWealth(std::vector<std::vector<int>>& accounts) {
        int max = 0;
        for (auto customer : accounts) {
            int wealth = 0;
            for (auto val : customer) {
                wealth += val;
            }
            max = std::max(wealth, max);
        }
        return max;
    }
};

int main() {

}
