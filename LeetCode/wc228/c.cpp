#include <bits/stdc++.h>


class Solution {
  public:
    int minimumSize(std::vector<int>& nums, int maxOperations) {
        const int MAX = 1e9;
        return binarySearch(1, MAX, nums, maxOperations);
    }

    int binarySearch(int min, int max, std::vector<int>& nums, int maxOps) {
        if (min == max) {
            return min;
        }
        int mid = (min + max) / 2;
        if (countOps(mid, nums) <= maxOps) {
            return binarySearch(min, mid, nums, maxOps);
        }
        return binarySearch(mid + 1, max, nums, maxOps);
    }

    long long int countOps(int val, std::vector<int>& nums) {
        long long int cnt = 0;
        for (auto num : nums) {
            if (num > val) {
                cnt += num / val - 1;
                if (num % val > 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


int main() {}
