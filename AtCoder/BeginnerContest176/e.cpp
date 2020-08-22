#include <bits/stdc++.h>


int main() {
    int H, W, M;
    std::cin >> H >> W >> M;

    std::vector<std::pair<int, int>> pos;
    std::vector<int> hist_h(H, 0), hist_w(W, 0);

    for (int i = 0; i < M; i++) {
        int h, w;
        std::cin >> h >> w;
        h--; w--;
        hist_h[h] += 1;
        hist_w[w] += 1;
        pos.emplace_back(h, w);
    }

    int max = 0;
    long long int count = 0;
    for (auto p : pos) {
        int val = hist_h[p.first] + hist_w[p.second] - 1;
        if (val > max) {
            max = val;
            count = 1;
        } else if (val == max) {
            count++;
        }
    }

    int max_h = hist_h[0];
    long long int count_h = 1;
    for (int i = 1; i < H; i++) {
        if (hist_h[i] == max_h) {
            count_h++;
        } else if (hist_h[i] > max_h){
            max_h = hist_h[i];
            count_h = 1;
        }
    }

    int max_w = hist_w[0];
    long long int count_w = 1;
    for (int i = 1; i < W; i++) {
        if (hist_w[i] == max_w) {
            count_w++;
        } else if (hist_w[i] > max_w) {
            max_w = hist_w[i];
            count_w = 1;
        }
    }

    if (max == max_h + max_w - 1 && count_h * count_w <= count) {
        std::cout << max_h + max_w - 1 << std::endl;
    } else {
        std::cout << max_h + max_w << std::endl;
    }
}
