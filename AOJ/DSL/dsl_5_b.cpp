#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    int max_size = 1001;
    std::vector<std::vector<int>> tiles(max_size, std::vector<int>(max_size, 0));
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        tiles[y1][x1]++;
        tiles[y1][x2]--;
        tiles[y2][x1]--;
        tiles[y2][x2]++;
    }

    for (int y = 0; y < max_size; y++) {
        for (int x = 1; x < max_size; x++) {
            tiles[y][x] += tiles[y][x - 1];
        }
    }

    for (int y = 1; y < max_size; y++) {
        for (int x = 0; x < max_size; x++) {
            tiles[y][x] += tiles[y - 1][x];
        }
    }

    int max = 0;
    for (int y = 0; y < max_size; y++) {
        for (int x = 0; x < max_size; x++) {
            max = std::max(tiles[y][x], max);
        }
    }

    std::cout << max << std::endl;
}
