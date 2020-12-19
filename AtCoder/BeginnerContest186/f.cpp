#include <bits/stdc++.h>


int main() {
    int H, W, M;
    std::cin >> H >> W >> M;

    std::vector<int> row_mins(H, W), col_mins(W, H);
    for (int i = 0; i < M; i++) {
        int x, y;
        std::cin >> x >> y;
        x--; y--;
    }
}
