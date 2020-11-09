#include <bits/stdc++.h>


struct Node {
    Node(int h, int w, int dh, int dw): h(h), w(w), dh(dh), dw(dw) {}
    int h, w, dh, dw;
};

int main() {
    int H, W, N, M;
    std::cin >> H >> W >> N >> M;
    std::vector<std::vector<int>> mas(H, std::vector<int>(W, 0));

    for (int i = 0; i < N; i++) {
        int h, w;
        std::cin >> h >> w;
        h--; w--;
        mas[h][w] = 2;
    }

    for (int i = 0; i < M; i++) {
        int h, w;
        std::cin >> h >> w;
        mas[h - 1][w - 1] = -1;
    }

    auto process_mas = [&mas] (int h, int w, bool flag) {
        if (mas[h][w] == 2) {
            flag = true;
        } else if (mas[h][w] == -1) {
            flag = false;
        }
        if (flag && mas[h][w] == 0) {
            mas[h][w] = 1;
        }
        return flag;
    };

    // left to right
    for (int h = 0; h < H; h++) {
        bool flag = mas[h][0] == 2;
        for (int w = 1; w < W; w++) {
            flag = process_mas(h, w, flag);
        }
    }

    // right to left
    for (int h = 0; h < H; h++) {
        bool flag = mas[h][W - 1] == 2;
        for (int w = W - 2; w >= 0; w--) {
            flag = process_mas(h, w, flag);
        }
    }

    // top to bottom
    for (int w = 0; w < W; w++) {
        bool flag = mas[0][w] == 2;
        for (int h = 0; h < H; h++) {
            flag = process_mas(h, w, flag);
        }
    }

    // bottom to top
    for (int w = 0 ; w < W; w++) {
        bool flag = mas[H - 1][w] == 2;
        for (int h = H - 2; h >= 0; h--) {
            flag = process_mas(h, w, flag);
        }
    }

    int cnt = 0;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (mas[h][w] > 0) {
                cnt++;
            }
        }
    }
    std::cout << cnt << std::endl;
}
