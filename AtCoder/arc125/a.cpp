/*
 * a.cpp
 *
 * Create Date : 2021-08-22 20:57:56
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> a(N), b(M);
    std::vector<int> flag_a(2, 0), flag_b(2, 0);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
        flag_a[a[i]] = 1;
    }
    for (int i = 0; i < M; i++) {
        std::cin >> b[i];
        flag_b[b[i]] = 1;
    }

    if ((flag_b[0] == 1 && flag_a[0] == 0) || (flag_b[1] == 1 && flag_a[1] == 0)) {
        std::cout << -1 << std::endl;
        return 0;
    }

    int min_shift = 0;
    for (int i = 1; i < N / 2 + 1; i++) {
        if ((a[0] != a[i]) || (a[0] != a[N - i])) {
            min_shift = i;
            break;
        }
    }

    int cnt = M;
    int cur_a = a[0];
    for (int i = 0; i < M; i++) {
        if (b[i] != cur_a) {
            cnt += min_shift;
            cur_a = b[i];
            min_shift = 1;
        }
    }
    std::cout << cnt << std::endl;
}
