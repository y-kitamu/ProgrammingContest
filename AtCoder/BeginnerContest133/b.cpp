#include <bits/stdc++.h>


int main() {
    int N, D;
    std::cin >> N >> D;

    std::vector<std::vector<int>> points(N, std::vector<int>(D));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            std::cin >> points[i][j];
        }
    }

    auto calc_dist = [&D] (const std::vector<int>& pt0, const std::vector<int>& pt1) {
        int square = 0;
        for (int i = 0; i < D; i++) {
            square += (pt0[i] - pt1[i]) * (pt0[i] - pt1[i]);
        }
        return square;
    };

    std::vector<int> squares;
    int idx = 1;
    int maximum = std::sqrt(40 * 40 * 10) + 1;
    while (idx <= maximum) {
        squares.emplace_back(idx * idx);
        idx++;
    }

    int count = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int val = calc_dist(points[i], points[j]);
            if (std::find(squares.begin(), squares.end(), val) != squares.end()) {
                count++;
            }
        }
    }
    std::cout << count << std::endl;
}
