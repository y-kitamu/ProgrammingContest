/**
 * @file f.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-08 22:11:18
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    long long int area = 0;
    std::vector<long long int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i] >> Y[i];
        if (i > 0) {
            area += X[i - 1] * Y[i] - X[i] * Y[i - 1];
        }
    }
    area += X[N - 1] * Y[0] - X[0] * Y[N - 1];
    area = std::abs(area);

    auto calc_area = [&X, &Y](int i0, int i1, int i2) {
        return 4 * (X[i0] * Y[i1] - X[i1] * Y[i0] + X[i1] * Y[i2] - X[i2] * Y[i1] + X[i2] * Y[i0] -
                    X[i0] * Y[i2]);
    };

    int left = 0, right = 2;
    long long int cur = calc_area(left, left + 1, right);
    long long int min_diff = std::abs(area - cur);
    while (left < N) {
        if (right >= N) {
            right -= N;
        }
        if (area - std::abs(cur) == 0) {
            min_diff = 0;
            break;
        }
        if (area - cur < 0) {
            cur -= calc_area(left, (left + 1) % N, right);
            min_diff = std::min(min_diff, std::abs(area - std::abs(cur)));
            left++;
        } else {
            cur += calc_area(left, right, (right + 1) % N);
            min_diff = std::min(min_diff, std::abs(area - std::abs(cur)));
            right++;
        }
    }
    std::cout << min_diff << std::endl;
}
