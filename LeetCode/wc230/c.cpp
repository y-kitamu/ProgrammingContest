#include <bits/stdc++.h>


class Solution {
  public:
    int minOperations(std::vector<int>& nums1, std::vector<int>& nums2) {
        int sum1 = 0, sum2 = 0;
        for (auto val : nums1) {
            sum1 += val;
        }
        for (auto val : nums2) {
            sum2 += val;
        }

        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        std::vector<int> n1 = nums1, n2 = nums2;
        if (sum2 < sum1) {
            std::swap(sum1, sum2);
            n1.swap(n2);
        }

        int cnt = 0;
        int i1 = 0, i2 = n2.size() - 1;

        if (n1.size() * 6 < n2.size()) {
            return -1;
        }

        while (sum1 < sum2) {
            if (i1 >= n1.size() && i2 < 0) {
                break;
            }
            // std::cout << i1 << " , " << i2 << " , " << sum1 << " , " << sum2 << std::endl;
            int d1 = 6, d2 = 1;
            if (i1 < n1.size()) {
                d1 = n1[i1];
            }
            if (i2 >= 0) {
                d2 = n2[i2];
            }
            if (6 - d1 > d2 - 1) {
                sum1 += 6 - d1;
                i1++;
            } else {
                sum2 -= d2 - 1;
                i2--;
            }
            cnt++;
        }

        return cnt;
    }
};


int main() {}
