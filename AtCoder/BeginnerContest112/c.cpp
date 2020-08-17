#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    int positive_idx;
    std::vector<std::vector<int>> points(N, std::vector<int>(3));
    for (int i = 0; i < N; i++) {
        std::cin >> points[i][0] >> points[i][1] >> points[i][2];
        if (points[i][2] > 0) {
            positive_idx = i;
        }
    }

    bool is_detect = false;
    int x, y, height;
    std::map<int, int> projs;
    for (y = 0; y <= 100; y++) {
        for (x = 0; x <= 100; x++) {
            bool success = true;
            auto pos_pt = points[positive_idx];
            height = pos_pt[2] + std::abs(x - pos_pt[0]) + std::abs(y - pos_pt[1]);
            for (auto pt : points) {
                if (std::max(height - std::abs(pt[0] - x) - std::abs(pt[1] - y), 0) != pt[2]) {
                    success = false;
                    break;
                }
            }
            if (success) {
                is_detect = true;
                break;
            }
        }
        if (is_detect) {
            break;
        }
    }

    std::cout << x << " " << y << " " << height << std::endl;
}
