#include <bits/stdc++.h>


class Solution {
  public:
    int maxDistance(std::vector<int>& nums1, std::vector<int>& nums2) {
        int i = 0, j = 0;
        int max = 0;
        for (;;) {
            if (nums1[i] <= nums2[j]) {
                max = std::max(max, j - i);
                j++;
            } else {
                i++;
            }
            if (j == nums2.size() || i == nums1.size()) {
                break;
            }
        }
        return max;
    }
};


int main() {}
