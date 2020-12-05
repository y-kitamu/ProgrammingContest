#include <bits/stdc++.h>


int binary_search(int target, std::vector<int> vec, int start, int last) {
    if (start == last) {
        return start;
    }
    int mid = (start + last) / 2;
    if (target <= vec[mid]) {
        return binary_search(target, vec, start, mid);
    }
    return binary_search(target, vec, mid + 1, last);
}


class Solution {
public:
    std::vector<int> mostCompetitive(std::vector<int>& nums, int k) {
        std::vector<int> ordered = nums;
        std::sort(ordered.begin(), ordered.end(), [](auto &lhs, auto &rhs) { return lhs < rhs; });
        std::vector<int> ans(k, 1e9);
        int length = nums.size();

        int idx = 0;
        for (int i = 0; i < length; i++) {
            int res = length - i;
            int order = binary_search(nums[i], ordered, 0, length);
            idx = std::min(idx, std::max(k - res, order));
            std::cout << i << " " << idx << " " << order << " " << res << std::endl;
             if (idx < k) {
                 while (nums[i] == ans[idx]) {
                     idx++;
                     if (idx == k - 1) {
                         break;
                     }
                 }
                 ans[idx] = nums[i];
                 idx++;
            }
        }
        return ans;
    }
};


int main() {

}
