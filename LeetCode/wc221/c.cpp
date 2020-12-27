#include <bits/stdc++.h>


class Solution {
public:
    std::vector<int> findBall(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        std::vector<int> answer(cols, -1);
        for (int start = 0; start < cols; start++) {
            int col = start;
            for (int row = 0; row < rows; row++) {
                if (grid[row][col] == 1) {
                    if (col == cols - 1 || grid[row][col + 1] == -1) {
                        col = -1;
                        break;
                    } else {
                        col++;
                    }
                } else {
                    if (col == 0 || grid[row][col - 1] == 1) {
                        col = -1;
                        break;
                    } else {
                        col--;
                    }
                }
            }
            answer[start] = col;
        }
        return answer;
    }
};

int main() {

}
