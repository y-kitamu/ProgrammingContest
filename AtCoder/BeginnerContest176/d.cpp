#include <bits/stdc++.h>


struct Point {
    int x, y;
    Point() {}
    Point(int x, int y): x(x), y(y) {}
};


int main() {
    int H, W;
    std::cin >> H >> W;
    Point start, goal;
    std::cin >> start.y >> start.x >> goal.y >> goal.x;
    start.x--; start.y--; goal.x--; goal.y--;

    std::vector<std::vector<char>> road(H, std::vector<char>(W));
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            std::cin >> road[y][x];
        }
    }

    auto compare = [](std::pair<int, Point> a, std::pair<int, Point> b) {
        return a.first > b.first;
    };
    std::priority_queue<std::pair<int, Point>, std::vector<std::pair<int, Point>>, decltype(compare)> que {compare};

    std::vector<std::vector<int>> map(H, std::vector<int>(W, -1));
    map[start.y][start.x] = 0;
    que.push(std::make_pair(0, start));
    while (!que.empty()) {
        auto top = que.top();
        que.pop();
        auto pos = top.second;
        if (pos.x == goal.x && pos.y == goal.y) {
            std::cout << map[pos.y][pos.x] << std::endl;
            return 0;
        }
        if (pos.y + 1 < H && road[pos.y + 1][pos.x] == '.') {
            if (map[pos.y + 1][pos.x] == -1 || top.first < map[pos.y + 1][pos.x]) {
                Point next(pos.x, pos.y + 1);
                map[next.y][next.x] = top.first;
                que.push(std::make_pair(top.first, next));
            }
        }
        if (pos.y - 1 >= 0 && road[pos.y - 1][pos.x] == '.') {
            if (map[pos.y - 1][pos.x] == -1 || top.first < map[pos.y - 1][pos.x]) {
                Point next(pos.x, pos.y - 1);
                map[next.y][next.x] = top.first;
                que.push(std::make_pair(top.first, next));
            }
        }
        if (pos.x + 1 < W && road[pos.y][pos.x + 1] == '.') {
            if (map[pos.y][pos.x + 1] == -1 || top.first < map[pos.y][pos.x + 1]) {
                Point next(pos.x + 1, pos.y);
                map[next.y][next.x] = top.first;
                que.push(std::make_pair(top.first, next));
            }
        }
        if (pos.x - 1 >= 0 && road[pos.y][pos.x - 1] == '.') {
            if (map[pos.y][pos.x - 1] == -1 ||
                top.first < map[pos.y][pos.x - 1]) {
                Point next(pos.x - 1, pos.y);
                map[next.y][next.x] = top.first;
                que.push(std::make_pair(top.first, next));
            }
        }

        for (int y = std::max(0, pos.y - 2); y < std::min(pos.y + 3, H); y++) {
            for (int x = std::max(0, pos.x - 2); x < std::min(pos.x + 3, W); x++) {
                if (map[y][x] == -1 && road[y][x] == '.') {
                    map[y][x] = top.first + 1;
                    que.push(std::make_pair(top.first + 1, Point(x, y)));
                }
            }
        }
    }
    std::cout << map[goal.y][goal.x] << std::endl;
}
