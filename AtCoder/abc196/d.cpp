#include <bits/stdc++.h>


int dfs(int i, int H, int W, int A, int B, int used) {
    if (used == (1 << (H * W)) - 1) {
        return 1;
    }

    if (used >> i & 1) {
        return dfs(i + 1, H, W, A, B, used);
    }

    int sum = 0;
    if (B) {
        sum += dfs(i + 1, H, W, A, B - 1, used | 1 << i);
    }
    if (A) {
        if (i % W < W - 1 && !(used >> (i + 1) & 1)) {
            sum += dfs(i + 2, H, W, A - 1, B, used | 1 << i | (1 << (i + 1)));
        }
        if (!(used >> (i + W) & 1)) {
            sum += dfs(i + 1, H, W, A - 1, B, used | 1 << i | 1 << (i + W));
        }
    }
    return sum;
}


int main() {
    int H, W, A, B;
    std::cin >> H >> W >> A >> B;

    auto sum = dfs(0, H, W, A, B, 0);
    std::cout << sum << std::endl;
}
