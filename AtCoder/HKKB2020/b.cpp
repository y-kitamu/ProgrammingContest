#include <bits/stdc++.h>


int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> rows(H);
    for (int i = 0; i < H; i++) {
        std::cin >> rows[i];
    }

    int cnt = 0;
    for (int y = 0; y < H - 1; y++) {
        for (int x = 0; x < W - 1; x++) {
            if (rows[y][x] == '.' && rows[y][x + 1] == '.') {
                cnt++;
            }
            if (rows[y][x] == '.' && rows[y + 1][x] == '.') {
                cnt++;
            }
        }
        if (rows[y][W - 1] == '.' && rows[y + 1][W - 1] == '.') {
            cnt++;
        }
    }
    for (int x = 0; x < W - 1; x++) {
        if (rows[H - 1][x] == '.' && rows[H - 1][x + 1] == '.') {
            cnt++;
        }
    }
    std::cout << cnt << std::endl;
}
