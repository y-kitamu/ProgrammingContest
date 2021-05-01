#include <bits/stdc++.h>


int main() {
    int N, D, H;
    std::cin >> N >> D >> H;

    double max = 0.0;
    for (int i = 0; i < N; i++) {
        int d, h;
        std::cin >> d >> h;

        max = std::max(max, h - (double)d * (H - h) / (D - d));
    }

    std::cout << std::fixed << std::setprecision(10) << max << std::endl;
}
