#include <bits/stdc++.h>


class Solution {
public:
    int maximumUniqueSubarray(std::vector<int>& nums) {
        int left = 0, right = 0;
        std::set<int> values;
        int sum = 0;
        int max = 0;

        while (right < nums.size()) {
            if (values.find(nums[right]) == values.end()) {
                sum += nums[right];
                max = std::max(sum, max);
                values.insert(nums[right]);
                right++;
            } else {
                values.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
        }
        return max;
    }
};


int main() {

}
