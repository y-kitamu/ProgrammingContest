#include <bits/stdc++.h>


int main()  {
    int H, W;
    std::cin >> H >> W;

    std::vector<int> counts(W, 0);
    int min_idx = 0;
    for (int i = 0; i < H; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        if (min_idx >= a) {
            min_idx = b + 1;
        }
        for (int j = min_idx; j < W; j++) {
            if (a <= j && j <= b) {
                counts[j] = counts[j - 1] + 1;
            } else {
                counts[j]++;
            }
        }
        if (min_idx >= W) {
            std::cout << -1 << std::endl;
        } else {
            int min = counts[min_idx];
            for (int j = min_idx + 1; j < W; j++) {
                min = std::min(min, counts[j]);
            }
            std::cout << min << std::endl;
        }
    }
}
