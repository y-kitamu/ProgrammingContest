#include <bits/stdc++.h>

bool judge(double cx, double cy, double r, std::vector<int>& x, std::vector<int>& y) {}


int main() {
    int N;
    std::cin >> N;

    std::vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) {
        std::cin >> x[i] >> y[i];
    }

    double max = 1e5;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double cx = (x[i] + x[j]) / 2.0;
            double cy = (y[i] + y[j]) / 2.0;
            double r = std::hypot(x[i] - x[j], y[i] - y[j]);
            if (judge(cx, cy, r, x, y)) {
                max = std::min(max, r);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
            }
        }
    }
}
