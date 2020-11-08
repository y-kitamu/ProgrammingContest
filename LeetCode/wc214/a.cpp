#include <bits/stdc++.h>

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) {
            return 1;
        }
        std::vector<int> nums(n + 1, 0);
        nums[1] = 1;
        int max = 1;
        for (int i = 2; i < n + 1; i += 2){
            nums[i] = nums[i / 2];
            max = std::max(nums[i], max);
            if (i + 1 < n + 1) {
                nums[i + 1] = nums[i / 2] + nums[i / 2 + 1];
                max = std::max(nums[i + 1], max);
            }
        }
        return max;
    }
};


int main() {

}
