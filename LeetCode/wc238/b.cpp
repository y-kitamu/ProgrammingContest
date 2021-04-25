#include <bits/stdc++.h>

class Solution {
  public:
    int maxFrequency(std::vector<int>& nums, int k) {
        long long int N = nums.size();
        std::sort(nums.begin(), nums.end());

        long long int max = 0;
        std::vector<long long int> cost(N, 0);
        for (long long int i = 0; i < N - 1; i++) {
            cost[i + 1] = cost[i] + (i + 1) * (nums[i + 1] - nums[i]);
        }
        // prlong long int_vec(cost);
        for (long long int i = 0; i < N; i++) {
            long long int idx = search(0, i, i, k, cost, nums);
            max = std::max(max, i + 1 - idx);
        }

        return max;
    }

    void print_vec(std::vector<int>& vec) {
        for (auto& val : vec) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    int search(long long int min, long long int max, const long long int idx, const long long int val,
               std::vector<long long int>& cost, std::vector<int>& nums) {
        if (min == max) {
            return min;
        }
        long long int mid = (min + max) / 2;
        long long int c = cost[mid] + mid * (nums[idx] - nums[mid]);
        // std::cout << min << " , " << max << " , " << mid << " , " << c << std::endl;
        if (cost[idx] - c <= val) {
            return search(min, mid, idx, val, cost, nums);
        }
        return search(mid + 1, max, idx, val, cost, nums);
    }
};

int main() {}
