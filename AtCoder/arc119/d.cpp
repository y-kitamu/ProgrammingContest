#include <bits/stdc++.h>


int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> rows(H);
    for (int i = 0; i < H; i++) {
        std::cin >> rows[i];
    }

    std::vector<int> rrow(H, 0), rcol(W, 0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (rows[i][j] == 'R') {
                rrow[i]++;
                rcol[j]++;
            }
        }
    }
    int cnt = 0;

    int resH = H, resW = W;
    while (resH > 0 || resW > 0) {
    }
}
