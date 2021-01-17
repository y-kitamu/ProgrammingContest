#include <bits/stdc++.h>

class Solution {
  public:
    int countGoodRectangles(std::vector<std::vector<int>>& rectangles) {
        int max = 0;
        for (auto vec : rectangles) {
            max = std::max(std::min(vec[0], vec[1]), max);
        }
        int cnt = 0;
        for (auto vec : rectangles) {
            if (std::min(vec[0], vec[1]) == max) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {}
