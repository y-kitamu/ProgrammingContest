#include <bits/stdc++.h>


class Solution {
  public:
    int GCD(int a, int b) { return b == 0 ? a : GCD(b, a % b); }

    int countDifferentSubsequenceGCDs(std::vector<int>& nums) {
        std::vector<int> divs(2 * 1e5, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j <= std::sqrt(nums[i]); j++) {
                if (nums[i] % j == 0) {
                    auto val = nums[i] / j;
                    if (divs[j - 1] != 1) {
                        if (divs[j - 1] == 0) {
                            divs[j - 1] = val;
                        } else {
                            divs[j - 1] = GCD(val, divs[j - 1]);
                        }
                    }
                    if (divs[val - 1] != 1) {
                        if (divs[val - 1] == 0) {
                            divs[val - 1] = j;
                        } else {
                            divs[val - 1] = GCD(j, divs[val - 1]);
                        }
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < divs.size(); i++) {
            if (divs[i] == 1) {
                std::cout << i + 1 << " ";
                cnt++;
            }
        }
        std::cout << std::endl;
        return cnt;
    }
};


int main() {}
