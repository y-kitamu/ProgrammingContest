/*
 * d.cpp
 *
 * Create Date : 2021-06-26 21:17:20
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> S(N, std::vector<int>(2)), T(N, std::vector<int>(2));

    for (int i = 0; i < N; i++) {
        std::cin >> S[i][0] >> S[i][1];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> T[i][0] >> T[i][1];
    }

    auto match = [&N](std::vector<std::vector<double>> s, std::vector<std::vector<double>> t) {
        double dx = 0;
        double dy = 0;
        for (int i = 0; i < N; i++) {
            dx += t[i][0] - s[i][0];
            dy += t[i][1] - s[i][1];
        }
        dx /= N;
        dy /= N;

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (std::abs(s[i][0] + dx - t[j][0]) < 1e-4 && std::abs(s[i][1] + dy - t[j][1]) < 1e-4) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt == N;
    };

    std::vector<double> rotate{0, acos(0.6), acos(0.8)};

    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < N; i++) {
            int x = S[i][0], y = S[i][1];
            S[i][0] = -y;
            S[i][1] = x;
        }
        for (int k = 0; k < 3; k++) {
            std::vector<std::vector<double>> a(N, std::vector<double>(2)), b(N, std::vector<double>(2));
            for (int i = 0; i < N; i++) {
                a[i][0] = std::cos(rotate[k]) * S[i][0] - std::sin(rotate[k]) * S[i][1];
                a[i][1] = std::sin(rotate[k]) * S[i][0] + std::cos(rotate[k]) * S[i][1];
                b[i][0] = T[i][0];
                b[i][1] = T[i][1];
            }
            if (match(a, b)) {
                std::cout << "Yes" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "No" << std::endl;
}
