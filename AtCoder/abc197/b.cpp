#include <bits/stdc++.h>


int main() {
    int H, W, X, Y;
    std::cin >> H >> W >> Y >> X;
    X--;
    Y--;

    std::vector<std::string> rows(H);
    for (int i = 0; i < H; i++) {
        std::cin >> rows[i];
    }

    int cnt = 1;
    for (int i = 1; i <= X; i++) {
        if (rows[Y][X - i] == '#') {
            break;
        }
        cnt++;
    }

    for (int i = X + 1; i < W; i++) {
        if (rows[Y][i] == '#') {
            break;
        }
        cnt++;
    }

    for (int i = 1; i <= Y; i++) {
        if (rows[Y - i][X] == '#') {
            break;
        }
        cnt++;
    }

    for (int i = Y + 1; i < H; i++) {
        if (rows[i][X] == '#') {
            break;
        }
        cnt++;
    }
    std::cout << cnt << std::endl;
}
