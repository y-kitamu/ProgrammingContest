#include <bits/stdc++.h>

class Solution {
public:
    int maximalNetworkRank(int n, std::vector<std::vector<int>>& roads) {
        std::vector<std::vector<int>> linked_list(n, std::vector<int>(n, 0));
        std::vector<int> counts(n, 0);
        for (auto road : roads) {
            linked_list[road[1]][road[0]]++;
            linked_list[road[0]][road[1]]++;
            counts[road[0]]++;
            counts[road[1]]++;
        }

        int max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                max = std::max(max, counts[i] + counts[j] - linked_list[i][j]);
            }
        }
        return max;
    }
};


int main() {

}
