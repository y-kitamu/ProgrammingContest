#include <bits/stdc++.h>


int calc_max_dist(int si, int H, int W, std::vector<char> map) {
    int max = H * W;
    std::vector<int> dist(max, -1);
    dist[si] = 0;
    std::queue<std::pair<int, int>> que;

    auto push_nexts = [&que, &map, &W, &max](int cur) {
        if (cur - W >= 0 && map[cur - W] == '.') {
            que.push(std::make_pair(cur, cur - W));
        }
        if (cur + W < max && map[cur + W] == '.') {
            que.push(std::make_pair(cur, cur + W));
        }
        if (cur % W != 0 && map[cur - 1] == '.') {
            que.push(std::make_pair(cur, cur - 1));
        }
        if (cur % W != W - 1 && map[cur + 1] == '.') {
            que.push(std::make_pair(cur, cur + 1));
        }
    };

    push_nexts(si);

    while (!que.empty()) {
        auto top = que.front();
        que.pop();
        if (dist[top.second] == -1) {
            dist[top.second] = dist[top.first] + 1;
            push_nexts(top.second);
        }
    }

    int far = si;
    for (int i = 0; i < H * W; i++) {
        if (dist[i] > dist[far]) {
            far = i;
        }
    }
    return dist[far];
}


int main() {
    int H, W;
    std::cin >> H >> W;
    int max = H * W;
    std::vector<char> map(H * W);
    int si = 0;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            int idx = y * W + x;
            std::cin >> map[idx];
            if (map[idx] == '.') {
                si = idx;
            }
        }
    }
    int max_dist = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (map[i * W + j] == '.') {
                max_dist = std::max(max_dist, calc_max_dist(i * W + j, H, W, map));
            }
        }
    }
    std::cout << max_dist << std::endl;
}
