#include <bits/stdc++.h>

int H, W, K;

int count(std::vector<std::vector<int>>& color) {
    int cnt = 0;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (color[y][x] == 1) {
                cnt++;
            }
        }
    }
    return cnt;
}


int search(int num, std::vector<std::vector<int>> color) {
    if (num == H + W) {
        if (count(color) == K) {
            return 1;
        }
        return 0;
    }
    int cnt = 0;
    cnt += search(num + 1, color);
    if (num < H) {
        for (int x = 0; x < W; x++) {
            color[num][x] = 0;
        }
    } else {
        for (int y = 0; y < H; y++) {
            color[y][num - H] = 0;
        }
    }
    if (count(color) >= K) {
        cnt += search(num + 1, color);
    }
    return cnt;
}


int main() {
    std::cin >> H >> W >> K;

    std::vector<std::vector<int>> c(H, std::vector<int>(W, 0));
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            char val;
            std::cin >> val;
            if (val == '#') {
                c[y][x] = 1;
            }
        }
    }

    int cnt = search(0, c);
    std::cout << cnt << std::endl;
}
