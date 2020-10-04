#include <bits/stdc++.h>

class Solution {
public:
    int specialArray(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](auto lhs, auto rhs) { return lhs < rhs; });
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            if (N - i <= nums[i]) {
                if (i > 0) {
                    if (N - i > nums[i - 1]) {
                        return N - i;
                    }
                } else {
                    return N - i;
                }
            }
        }
        return -1;
    }
};


int main() {
    std::vector<int> input {0, 0};
    std::cout << Solution().specialArray(input) << std::endl;;
}
