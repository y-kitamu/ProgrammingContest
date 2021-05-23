#include <bits/stdc++.h>


int main() {
    long long int MOD = 998244353;
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> colors(H);
    for (int i = 0; i < H; i++) {
        std::cin >> colors[i];
    }

    std::vector<char> val(H + W, '_');
    for (int i = 0; i < H + W; i++) {
        for (int h = 0; h < H; h++) {
            int w = i - h;
            if (w < 0 || w >= W) {
                continue;
            }
            // std::cout << i << " , " << h << " , " << w << " , " << colors[h][w] << std::endl;
            if (val[i] == '_' || val[i] == '.') {
                val[i] = colors[h][w];
            } else {
                if (colors[h][w] != '.' && colors[h][w] != val[i]) {
                    std::cout << 0 << std::endl;
                    return 0;
                }
            }
        }
    }

    long long int ans = 1;
    for (int i = 0; i < H + W; i++) {
        if (val[i] == '.') {
            ans = (ans * 2) % MOD;
        }
    }
    std::cout << ans << std::endl;
}
