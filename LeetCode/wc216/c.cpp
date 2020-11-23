#include <bits/stdc++.h>

class Solution {
public:
    int waysToMakeFair(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> odd_sums(n / 2 + 1, 0), even_sums(n / 2 + n % 2 + 1, 0);
        for (int i = 0; i < (n + 1) / 2; i++) {
            even_sums[i + 1]  = even_sums[i] + nums[i * 2];
            if (i * 2 + 1 < n) {
                odd_sums[i + 1] = odd_sums[i] + nums[i * 2 + 1];
            }
        }
        int n_odd = odd_sums.size() - 1;
        int n_even = even_sums.size() - 1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int idx = (i + 1) / 2;
            int offset = (i + 1) % 2;

            int even = even_sums[idx];
            int odd = odd_sums[idx - 1 + offset];

            even += odd_sums[n_odd] - odd_sums[idx];
            odd += even_sums[n_even] - even_sums[idx + offset];
            if (even == odd) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    std::vector<int> vec { 1, 1, 1 };
    Solution().waysToMakeFair(vec);
}
