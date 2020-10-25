#include <bits/stdc++.h>


std::vector<std::vector<int>> values;

class Solution {
public:
    struct Step {
        Step(int from_x, int from_y, int to_x, int to_y): pos_x(to_x), pos_y(to_y) {
            cost = std::abs(values[from_y][from_x] - values[to_y][to_x]);
        };
        int cost;
        int pos_x, pos_y;
    };

    int minimumEffortPath(std::vector<std::vector<int>>& heights) {
        values = heights;
        int rows = heights.size();;
        int cols = heights[0].size();
        int pos_x = 0, pos_y = 0;
        std::vector<std::vector<int>> cost(rows, std::vector<int>(cols, 1e9));
        std::vector<std::vector<bool>> flag(rows, std::vector<bool>(cols, true));
        cost[pos_x][pos_y] = 0;

        auto compare = [] (Step lhs, Step rhs) {
            return lhs.cost > rhs.cost;
        };
        std::priority_queue<Step, std::vector<Step>, decltype(compare)> que {compare};
        if (pos_y + 1 < rows) {
            que.push(Step(pos_x, pos_y, pos_x, pos_y + 1));
        }
        if (pos_x + 1 < cols) {
            que.push(Step(pos_x, pos_y, pos_x + 1, pos_y));
        }
        flag[0][0] = false;
        int max_cost = 0;
        while (!que.empty()) {
            auto step = que.top();
            que.pop();
            pos_x = step.pos_x;
            pos_y = step.pos_y;
            if (flag[pos_y][pos_x] == false) {
                continue;
            }
            max_cost = std::max(max_cost, step.cost);
            if (pos_x == cols - 1 && pos_y == rows - 1) {
                break;
            }
            flag[pos_y][pos_x] = false;
            if (pos_y + 1 < rows && flag[pos_y + 1][pos_x]) {
                que.push(Step(pos_x, pos_y, pos_x, pos_y + 1));
            }
            if (pos_x + 1 < cols && flag[pos_y][pos_x + 1]) {
                que.push(Step(pos_x, pos_y, pos_x + 1, pos_y));
            }
            if (pos_x - 1 >= 0 && flag[pos_y][pos_x - 1]) {
                que.push(Step(pos_x, pos_y, pos_x - 1, pos_y));
            }
            if (pos_y - 1 >= 0 && flag[pos_y - 1][pos_x]) {
                que.push(Step(pos_x, pos_y, pos_x, pos_y - 1));
            }
        }
        return max_cost;
    }
};


int main() {

}
