#include <bits/stdc++.h>


int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::vector<int>> tiles_hist(H, std::vector<int>(W, 0));
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            int val;
            std::cin >> val;
            if (val == 1) {
                tiles_hist[y][x] = 0;
            } else {
                if (y > 0) {
                    tiles_hist[y][x] = tiles_hist[y - 1][x] + 1;
                } else {
                    tiles_hist[y][x] = 1;
                }
            }
        }
    }

    int max_area = 0;
    for (int y = 0; y < H; y++) {
        std::stack<std::pair<int, int>> stack;
        for (int x = 0; x < W; x++) {
            int min_x = x;
            while (!stack.empty() && stack.top().second > tiles_hist[y][x]) {
                int area = (x - stack.top().first) * stack.top().second;
                max_area = std::max(area, max_area);
                min_x = stack.top().first;
                stack.pop();
            }
            stack.push(std::make_pair(min_x, tiles_hist[y][x]));
        }
        while (!stack.empty()) {
            int area = (W - stack.top().first) * stack.top().second;
            max_area = std::max(area, max_area);
            stack.pop();
        }
    }

    std::cout << max_area << std::endl;
}
