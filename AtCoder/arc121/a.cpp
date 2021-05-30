#include <bits/stdc++.h>

std::vector<int> sort_index(std::vector<long long int>& vec) {
    std::vector<int> idx(vec.size());
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&vec](auto& lhs, auto& rhs) { return vec[lhs] > vec[rhs]; });
    return idx;
}


int main() {
    int N;
    std::cin >> N;

    std::vector<long long int> x(N), y(N);
    for (int i = 0; i < N; i++) {
        std::cin >> x[i] >> y[i];
    }

    auto ix_sort = sort_index(x);
    auto iy_sort = sort_index(y);

    auto x0 = ix_sort[0], x1 = ix_sort[1], xn0 = ix_sort[N - 2], xn1 = ix_sort[N - 1];
    auto y0 = iy_sort[0], y1 = iy_sort[1], yn0 = iy_sort[N - 2], yn1 = iy_sort[N - 1];

    auto dx0 = x[x0] - x[xn1], dx1 = std::max(x[x1] - x[xn1], x[x0] - x[xn0]);
    auto dy0 = y[y0] - y[yn1], dy1 = std::max(y[y1] - y[yn1], y[y0] - y[yn0]);

    if (dx1 >= dy0) {
        std::cout << dx1 << std::endl;
    } else if (dy1 >= dx0) {
        std::cout << dy1 << std::endl;
    } else if (x0 != y0 || xn1 != yn1) {
        if (dx0 >= dy0) {
            std::cout << dy0 << std::endl;
        } else {
            std::cout << dx0 << std::endl;
        }
    } else if (dx1 >= dy1) {
        std::cout << dx1 << std::endl;
    } else {
        std::cout << dy1 << std::endl;
    }
}
