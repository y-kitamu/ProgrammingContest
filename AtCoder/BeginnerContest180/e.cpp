#include <bits/stdc++.h>


struct City {
    int X, Y, Z;
};

int main() {
    int N;
    std::cin >> N;

    std::vector<City> cities(N);
    for (int i = 0; i < N; i++) {
        std::cin >> cities[i].X >> cities[i].Y >> cities[i].Z;
    }

    std::vector<std::vector<int>> costs(N, std::vector<int>(N, 0));
    for (int start = 0; start < N; start++) {
        for (int end = 0; end < N; end++) {
            if (start == end) {
                continue;
            }
            auto s = cities[start];
            auto e = cities[end];
            costs[start][end] = std::abs(s.X - e.X) + std::abs(s.Y - e.Y) + std::max(0, s.Z -e.Z);
        }
    }


}
