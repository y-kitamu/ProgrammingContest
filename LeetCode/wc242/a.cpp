#include <bits/stdc++.h>


class Solution {
  public:
    bool checkZeroOnes(std::string s) {
        int max0 = 0, max1 = 1;
        int cnt0 = 0, cnt1 = 0;
        for (auto& c : s) {
            if (c == '0') {
                cnt0++;
                max0 = std::max(max0, cnt0);
                cnt1 = 0;
            } else if (c == '1') {
                cnt1++;
                max1 = std::max(max1, cnt1);
                cnt0 = 0;
            }
        }
        return max1 > max0;
    }
};


int main() {}
