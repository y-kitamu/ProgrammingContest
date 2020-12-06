#include <bits/stdc++.h>


class Solution {
public:
    int maxOperations(std::vector<int>& nums, int k) {
        std::map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) == map.end()) {
                map[nums[i]] = 0;
            }
            map[nums[i]]++;
        }
        int num = 0;
        for (auto pair : map) {
            int i = pair.first;
            int j = k - i;
            if (i > j || map.find(j) == map.end()) {
                continue;
            }
            if (i == j) {
                num += map[i] / 2;
            } else {
                num += std::min(map[i], map[j]);
            }
        }
        return num;
    }
};


int main() {
    std::vector input {1,2,3,4};
    int k = 5;
    std::cout << Solution().maxOperations(input, k) << std::endl;;
}
