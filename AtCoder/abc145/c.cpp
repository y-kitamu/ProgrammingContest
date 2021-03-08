#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> pts(N, std::vector<int>(2));
    for (int i = 0; i < N; i++) {
        std::cin >> pts[i][0] >> pts[i][1];
    }

    auto calc_dist = [&pts](int lhs, int rhs) {
        auto dx = pts[lhs][0] - pts[rhs][0];
        auto dy = pts[lhs][1] - pts[rhs][1];
        double dist = std::pow((double)(dx * dx + dy * dy), 0.5);
        return dist;
    };

    double sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += calc_dist(i, j);
        }
    }

    sum /= N;
    std::cout << std::fixed << std::setprecision(10) << sum << std::endl;
}
