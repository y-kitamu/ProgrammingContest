#include <bits/stdc++.h>


int main() {
    int H, W;
    std::cin >> H >> W;
    std::vector<char> grid(H * W);
    std::map<char, std::vector<int>> teleport;
    std::vector<std::vector<int>> linked_list(H * W);
    int start, goal;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int idx = i * W + j;
            std::cin >> grid[idx];
            if (grid[idx] == 'S') {
                start = idx;
            } else if (grid[idx] == 'G') {
                goal = idx;
            } else if (grid[idx] != '.' && grid[idx] != '#') {
                teleport[grid[idx]].emplace_back(idx);
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int idx = i * W + j;
            if (j - 1 >= 0 && grid[idx - 1] != '#') {
                linked_list[idx].emplace_back(idx - 1);
            }
            if (j + 1 < W && grid[idx + 1] != '#') {
                linked_list[idx].emplace_back(idx + 1);
            }
            if (i - 1 >= 0 && grid[idx - W] != '#') {
                linked_list[idx].emplace_back(idx - W);
            }
            if (i + 1 < H && grid[idx + W] != '#') {
                linked_list[idx].emplace_back(idx + W);
            }
        }
    }

    std::vector<int> distances(H * W, -1);
    distances[start] = 0;

    std::queue<std::pair<int, int>> que; // (weight, to)
    for (auto val : linked_list[start]) {
        que.push(std::make_pair(1, val));
    }

    while (!que.empty()) {
        auto pair = que.front();
        que.pop();
        auto weight = pair.first, to = pair.second;
        if (distances[to] != -1) {
            continue;
        }
        distances[to] = weight;
        if (to == goal) {
            break;
        }
        for (auto val : linked_list[to]) {
            if (distances[val] == -1) {
                que.push(std::make_pair(weight + 1, val));
            }
        }

        for (auto val : teleport[grid[to]]) {
            if (distances[val] == -1) {
                que.push(std::make_pair(weight + 1, val));
            }
        }
        teleport.erase(grid[to]);
    }
    std::cout << distances[goal] << std::endl;
}
