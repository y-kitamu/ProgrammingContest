#include <bits/stdc++.h>


struct Point {
    int x, y;
    double dist(Point pt) { return std::hypot((double)pt.x - x, (double)pt.y - y); }
};


int main() {
    const int INF = 1e9;

    int N;
    std::cin >> N;

    std::vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        std::cin >> points[i].x >> points[i].y;
    }

    std::vector<std::vector<double>> dp(N, std::vector<double>(N, 0.0));

    for (int j = 1; j < N; j++) {
        for (int i = 0; i < j; i++) {
            if (i == 0 && j == 1) {
                dp[i][j] = points[0].dist(points[1]);
            } else if (i < j - 1) {
                dp[i][j] = dp[i][j - 1] + points[j - 1].dist(points[j]);
            } else {
                dp[i][j] = std::numeric_limits<double>::infinity();
                for (int k = 0; k < i; k++) {
                    dp[i][j] = std::min(dp[i][j], dp[k][i] + points[k].dist(points[j]));
                }
            }
        }
    }
    double min_dist = std::numeric_limits<double>::infinity();
    for (int k = 0; k < N - 1; k++) {
        min_dist = std::min(min_dist, dp[k][N - 1] + points[k].dist(points[N - 1]));
    }

    std::cout << std::fixed << std::setprecision(10) << min_dist << std::endl;
}
