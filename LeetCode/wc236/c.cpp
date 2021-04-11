#include <bits/stdc++.h>

class Solution {
  public:
    int min(int a, int b, int c) { return std::min(std::min(a, b), c); }

    int minSideJumps(std::vector<int>& obstacles) {
        int MAX = 1e9;
        std::vector<int> prev(3, 0), next(3);
        prev[0] = 1;
        prev[1] = 0;
        prev[2] = 1;
        for (int i = 0; i < obstacles.size(); i++) {
            switch (obstacles[i + 1]) {
                case 1:
                    next[0] = MAX;
                    next[1] = std::min(prev[1], prev[2] + 1);
                    next[2] = std::min(prev[1] + 1, prev[2]);
                    break;
                case 2:
                    next[0] = std::min(prev[0], prev[2] + 1);
                    next[1] = MAX;
                    next[2] = std::min(prev[0] + 1, prev[2]);
                    break;
                case 3:
                    next[0] = std::min(prev[0], prev[1] + 1);
                    next[1] = std::min(prev[0] + 1, prev[1]);
                    next[2] = MAX;
                    break;
                default:
                    next[0] = min(prev[0], prev[1] + 1, prev[2] + 1);
                    next[1] = min(prev[0] + 1, prev[1], prev[2] + 1);
                    next[2] = min(prev[0] + 1, prev[1] + 1, prev[2]);
                    break;
            }
            std::cout << next[0] << " " << next[1] << " " << next[2] << std::endl;
            prev = next;
        }
        return min(next[0], next[1], next[2]);
    }
};

int main() {}
