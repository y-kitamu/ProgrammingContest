#include <bits/stdc++.h>

long long int MOD = 998244353;

long long int pow_kai(long long int a, long long int n) {
    long long int x = 1;
    while (n > 0) {
        if (n & 1) {
            x = x * a % MOD;
        }
        a = a * a % MOD;
        n >>= 1;
    }
    return x;
}

int main() {
    int H, W, K;

    std::cin >> H >> W >> K;

    std::vector<std::vector<char>> block(H, std::vector<char>(W, 'A'));
    for (int i = 0; i < K; i++) {
        char c;
        int h, w;
        std::cin >> h >> w >> c;
        h--;
        w--;
        block[h][w] = c;
    }

    std::vector<std::vector<long long int>> points(H + 1, std::vector<long long int>(W + 1, 0));
    points[0][0] = 1;
    int res = H * W - K;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            switch (block[i][j]) {
                case 'A': {
                    long long int add = points[i][j] * 2 % MOD;
                    points[i + 1][j] = (points[i + 1][j] + add) % MOD;
                    points[i][j + 1] = (points[i][j + 1] + add) % MOD;
                    break;
                }
                case 'X': {
                    long long int add = points[i][j];
                    if (res > 0) {
                        add = points[i][j] * 3 % MOD;
                        res--;
                    }
                    points[i + 1][j] = (points[i + 1][j] + add) % MOD;
                    points[i][j + 1] = (points[i][j + 1] + add) % MOD;
                    break;
                }
                case 'R': {
                    long long int add = points[i][j];
                    if (res > 0) {
                        add = points[i][j] * 3 % MOD;
                        res--;
                    }
                    points[i][j + 1] = (points[i][j + 1] + add) % MOD;
                    break;
                }
                case 'D': {
                    long long int add = points[i][j];
                    if (res > 0) {
                        add = points[i][j] * 3 % MOD;
                        res--;
                    }
                    points[i + 1][j] = (points[i + 1][j] + add) % MOD;
                    break;
                }
            }
        }
    }

    int scale = pow_kai(3, std::max(H * W - K - (H + W), 0));
    std::cout << points[H - 1][W - 1] * scale % MOD << std::endl;
}
