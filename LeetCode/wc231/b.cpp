#include <bits/stdc++.h>

class Solution {
  public:
    int minElements(std::vector<int>& nums, int limit, int goal) {
        long long int sum = 0;
        for (auto& val : nums) {
            sum += (long long int)val;
        }
        return (std::abs(sum - goal) + limit - 1) / (long long int)limit;
    }
};


int main() {}
