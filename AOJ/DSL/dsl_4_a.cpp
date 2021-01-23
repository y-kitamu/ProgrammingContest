#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<long long int>> rects(N, std::vector<long long int>(4));
    std::set<long long int> xs, ys;
    for (int i = 0; i < N; i++) {
        std::cin >> rects[i][0] >> rects[i][1] >> rects[i][2] >> rects[i][3];
        xs.insert(rects[i][0]);
        xs.insert(rects[i][2]);
        ys.insert(rects[i][1]);
        ys.insert(rects[i][3]);
    }

    std::vector<long long int> cmp_x(xs.size()), cmp_y(ys.size());
    std::vector<std::vector<long long int>> tiles(ys.size(), std::vector<long long int>(xs.size(), 0));
    for (int i = 0; i < N; i++) {
        int x1 = std::distance(xs.begin(), xs.lower_bound(rects[i][0]));
        int y1 = std::distance(ys.begin(), ys.lower_bound(rects[i][1]));
        int x2 = std::distance(xs.begin(), xs.lower_bound(rects[i][2]));
        int y2 = std::distance(ys.begin(), ys.lower_bound(rects[i][3]));
        cmp_x[x1] = rects[i][0];
        cmp_x[x2] = rects[i][2];
        cmp_y[y1] = rects[i][1];
        cmp_y[y2] = rects[i][3];
        tiles[y1][x1] += 1;
        tiles[y2][x1] += -1;
        tiles[y1][x2] += -1;
        tiles[y2][x2] += 1;
    }

    long long int sum = 0;
    for (int y = 0; y < ys.size(); y++) {
        for (int x = 1; x < xs.size(); x++) {
            tiles[y][x] += tiles[y][x - 1];
        }
    }

    for (int y = 1; y < ys.size(); y++) {
        for (int x = 0; x < xs.size(); x++) {
            tiles[y][x] += tiles[y - 1][x];
        }
    }

    for (int y = 0; y < ys.size(); y++) {
        for (int x = 0; x < xs.size(); x++) {
            if (tiles[y][x] > 0) {
                sum += (cmp_x[x + 1] - cmp_x[x]) * (cmp_y[y + 1] - cmp_y[y]);
            }
            // std::cout << tiles[y][x] << " , ";
        }
        // std::cout << std::endl;
    }
    std::cout << sum << std::endl;
}
