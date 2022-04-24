/**
 * @file b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-04-24 11:33:31
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int countLatticePoints(std::vector<std::vector<int>>& circles) {
        auto judge = [](int x, int y, std::vector<int>& circle) {
            int dx = x - circle[0];
            int dy = y - circle[1];
            return dx * dx + dy * dy <= circle[2] * circle[2];
        };

        int ans = 0;
        for (int y = 0; y <= 200; y++) {
            for (int x = 0; x <= 200; x++) {
                for (auto& circle : circles) {
                    if (judge(x, y, circle)) {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {}
