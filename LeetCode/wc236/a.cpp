#include <bits/stdc++.h>

class Solution {
  public:
    int arraySign(std::vector<int>& nums) {
        int res = 1;
        for (auto& val : nums) {
            if (val < 0) {
                res *= -1;
            } else if (val == 0) {
                res = 0;
            }
        }
        return res;
    }
};


int main() {}
