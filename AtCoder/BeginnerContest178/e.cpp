#include <bits/stdc++.h>


long long int bruteforce(std::vector<std::pair<long long int, long long int>>& points) {
    int n = points.size();
    long long int max = 0;
    for (int i = 0; i < n - 1; i++) {
        long long int xi = points[i].first, yi = points[i].second;
        for (int j = 1; j < n; j++) {
            long long int dist = std::abs(xi - points[j].first) + std::abs(yi - points[j].second);
            max = std::max(max, dist);
        }
    }
    return max;
}


long long int answer(std::vector<std::pair<long long int, long long int>> & points) {
    int n = points.size();
    std::vector<long long int> xs(n);
    std::vector<long long int> ys(n);

    long long int maxx = -1e9, maxy = -1e9, minx = 1e9, miny = 1e9;
    for (int i = 0; i < n; i++) {
        auto pt = points[i];
        long long int x = pt.first + pt.second;
        long long int y = pt.first - pt.second;
        maxx = std::max(x, maxx);
        minx = std::min(x, minx);
        maxy = std::max(y, maxy);
        miny = std::min(y, miny);
    }
    return std::max(maxx - minx, maxy - miny);
}


int main() {
    int N;
    std::cin >> N;

    std::vector<std::pair<long long int, long long int>> points(N);
    for (int i = 0; i < N; i++) {
        std::cin >> points[i].first >> points[i].second;
    }

    std::cout << answer(points) << std::endl;
}
