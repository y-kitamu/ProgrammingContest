#include <bits/stdc++.h>

class Solution {
  public:
    int minSwaps(std::string s) {
        int cnt_0 = 0, cnt_1 = 0;
        for (auto& c : s) {
            if (c == '0') {
                cnt_0++;
            } else {
                cnt_1++;
            }
        }
        if (std::abs(cnt_1 - cnt_0) > 1) {
            return -1;
        }

        std::vector<std::vector<int>> cnts(2, std::vector<int>(2, 0));
        for (int i = 0; i < s.length(); i++) {
            cnts[s[i] - '0'][i % 2]++;
        }

        int res = 0;
        if (cnt_0 == cnt_1) {
            res = std::min(cnts[0][0], cnts[0][1]);
        } else if (cnt_0 > cnt_1) {
            res = cnts[0][1];
        } else {
            res = cnts[0][0];
        }
        return res;
    }
};

int main() {}
