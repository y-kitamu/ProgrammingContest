#include <bits/stdc++.h>

class Solution {
public:
    std::vector<bool> checkArithmeticSubarrays(std::vector<int>& nums, std::vector<int>& l, std::vector<int>& r) {
        std::vector<bool> flags(l.size(), true);
        for (int i = 0; i < l.size(); i++) {
            int min_idx = l[i];
            int max_idx = r[i] + 1;
            std::vector<int> sub_vector(nums.begin() + min_idx, nums.begin() + max_idx);
            std::sort(sub_vector.begin(), sub_vector.end());
            for (int j = 1; j < sub_vector.size(); j++) {
                if (sub_vector[j] - sub_vector[j - 1] != sub_vector[1] - sub_vector[0]) {
                    flags[i] = false;
                    break;
                }
            }
        }
        return flags;
    }
};

int main() {

}
