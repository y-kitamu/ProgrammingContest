#include <bits/stdc++.h>


int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> grid(H);
    std::vector<std::vector<int>> hist_h(H, std::vector<int>(W, 0));
    std::vector<std::vector<int>> hist_v(H, std::vector<int>(W, 0));

    for (int i = 0; i < H; i++) {
        std::cin >> grid[i];
    }

    for (int i = 0; i < H; i++) {
        int min = 0, cnt = 0;
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '.') {
                cnt++;
            } else {
                for (int k = min; k < j; k++) {
                    hist_h[i][k] = cnt;
                }
                hist_h[i][j] = 0;
                cnt = 0;
                min = j + 1;
            }
        }
        for (int k = min; k < W; k++) {
            hist_h[i][k] = cnt;
        }
    }

    for (int j = 0; j < W; j++) {
        int min = 0, cnt = 0;
        for (int i = 0; i < H; i++) {
            if (grid[i][j] == '.') {
                cnt++;
            } else {
                for (int k = min; k < i; k++) {
                    hist_v[k][j] = cnt;
                }
                hist_v[i][j] = 0;
                cnt = 0;
                min = i + 1;
            }
        }
        for (int k = min; k < H; k++) {
            hist_v[k][j] = cnt;
        }
    }

    int max = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            max = std::max(max, hist_h[i][j] + hist_v[i][j]);
        }
    }
    std::cout << max - 1 << std::endl;
}
