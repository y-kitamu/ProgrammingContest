#include <bits/stdc++.h>

class Solution {
public:
    int furthestBuilding(std::vector<int>& heights, int bricks, int ladders) {
        int used_bricks = 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> ladder_heights;
        for (int i = 0; i < heights.size() - 1; i++) {
            int step = heights[i + 1] - heights[i];
            if (step <= 0) {
                continue;
            }
            if (ladder_heights.size() < ladders) {
                ladder_heights.push(step);
            } else {
                if (ladder_heights.empty()) {
                    bricks -= step;
                    if (bricks < 0) {
                        return i;
                    }
                } else {
                    int top = ladder_heights.top();
                    if (top < step) {
                        ladder_heights.pop();
                        ladder_heights.push(step);
                        bricks -= top;
                    } else {
                        bricks -= step;
                    }
                    if (bricks < 0) {
                        return i;
                    }
                }
            }
        }
        return heights.size() - 1;
    }
};


int main() {
    std::vector<int> heights {
        4,12,2,7,3,18,20,3,19
    };
    std::cout << Solution().furthestBuilding(heights, 10, 2) << std::endl;;
}
