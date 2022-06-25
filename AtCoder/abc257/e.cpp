/**
 * @file e.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-25 21:50:07
 */
#include <bits/stdc++.h>

struct BigVal {
    int digit;
    std::string top = "";
};

int main() {
    int N;
    std::cin >> N;

    std::vector<long long int> C(9);
    for (int i = 0; i < 9; i++) {
        std::cin >> C[i];
    }

    std::vector<BigVal> vals(9);
    for (int i = 0; i < 9; i++) {
        vals[i].digit = N / C[i];
        int res = N - vals[i].digit * C[i];
        for (int j = 8; j >= 0; j--) {
            if (i == j) {
                continue;
            }
            int diff = (C[j] - C[i]);
            if (diff <= 0) {
                continue;
            }
            int cnt = res / diff;
            res -= cnt * diff;
            for (int k = 0; k < cnt; k++) {
                vals[i].top += (char)('1' + j);
            }
        }
    }

    auto max_idx = 0;
    for (int i = 1; i < 9; i++) {
        if (vals[i].digit > vals[max_idx].digit) {
            max_idx = i;
        } else if (vals[i].digit == vals[max_idx].digit) {
            auto lhs = vals[max_idx].top + (char)('1' + max_idx);
            auto rhs = vals[i].top + (char)('1' + i);
            int diff = lhs.length() - rhs.length();
            if (diff > 0) {
                for (int j = 0; j < diff; j++) {
                    rhs += (char)('1' + i);
                }
            } else {
                for (int j = 0; j < -diff; j++) {
                    lhs += (char)('1' + max_idx);
                }
            }
            if (lhs < rhs) {
                max_idx = i;
            }
        }
    }
    int digit = vals[max_idx].digit - vals[max_idx].top.length();
    std::string ans = vals[max_idx].top;
    char c = (char)('1' + max_idx);
    for (int i = 0; i < digit; i++) {
        ans += c;
    }
    std::cout << ans << std::endl;
}
