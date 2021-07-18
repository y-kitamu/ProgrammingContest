/*
 * c.cpp
 *
 * Create Date : 2021-07-18 21:29:05
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int T;
    std::cin >> T;

    // std::random_device seed_gen;
    // std::mt19937 engine(seed_gen());
    // std::uniform_int_distribution<long long> dist(1, 1e18);
    for (int t = 0; t < T; t++) {
        // std::string N = std::to_string(dist(engine));

        std::string N;
        std::cin >> N;

        size_t i = 0;
        for (; i < N.length(); i++) {
            if (N[i] == '1' || N[i] == '2' || N[i] == '3') {
                continue;
            }
            break;
        }

        if (i == N.length()) {
            std::cout << 1 << std::endl;
            continue;
        }

        std::vector<int> vals(N.length() - i);
        for (int j = i; j < N.length(); j++) {
            vals[j - i] = int(N[j] - '0');
        }
        int ans = 2;
        while (true) {
            int min = ans * 1;
            int max = ans * 3;
            bool ok = true;
            for (size_t j = vals.size() - 1; j >= 0; j--) {
                if (vals[j] < min) {
                    vals[j] += 10;
                    if (j > 0) {
                        vals[j - 1]--;
                    }
                }
                if (vals[j] < min || max < vals[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                break;
            }
            ans++;
        }
        std::cout << ans << std::endl;
    }
}
