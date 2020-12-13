#include <bits/stdc++.h>


class Solution {
public:
    int stoneGameVII(std::vector<int>& stones) {
        int size = stones.size();
        int left = 0, right = size - 1;

        for (int i = 0; i < size; i++) {
            int left_min = std::min(stones[left + 1], stones[right]);
            int right_min = std::min(stones[right - 1], stones[left]);
            bool is_left = true;
            if (left_min > right_min) {
                is_left = true;
            } else if (left_min < right_min) {
                is_left = false;
            } else if (left > right) {
                is_left = false;
            } else {
                is_left = true;
            }
            if (i % 2 == 1) {

            }
        }
    }
};


int main() {
}
