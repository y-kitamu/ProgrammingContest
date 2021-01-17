#include <bits/stdc++.h>

class Solution {
  public:
    int tupleSameProduct(std::vector<int>& nums) {
        std::map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int val = nums[i] * nums[j];
                if (map.find(val) == map.end()) {
                    map[val] = 0;
                }
                map[val]++;
            }
        }
        int count = 0;
        for (auto pair : map) {
            count += pair.second * (pair.second - 1) * 2 * 2;
        }
        return count;
    }
};

int main() {
    std::vector<int> nums(1000);

    std::random_device rng;
    std::uniform_int_distribution<> dist(1, 1e4);
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = dist(rng);
    }
    Solution sol;
    std::cout << sol.tupleSameProduct(nums) << std::endl;
}
