/*
 * c.cpp
 *
 * Create Date : 2022-04-09 21:41:03
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<long long int> A(N), SA;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    SA = A;
    std::sort(SA.begin(), SA.end());
    int mid_idx = N / 2 - 1;
    int cnt = 1;
    while (cnt <= mid_idx && SA[mid_idx - cnt] == SA[mid_idx]) {
        cnt++;
    }

    long long int ans = 0;
    std::vector<int> flag(N, 1);
    for (int i = 0; i < N; i++) {
        if (A[i] < SA[mid_idx]) {
            flag[i] = -1;
        } else if (A[i] == SA[mid_idx] && cnt > 0) {
            flag[i] = -1;
            cnt--;
        } else {
            ans += A[i];
        }
    }

    int k = 0;
    int cur_val = 0;
    int min_val = 0;
    int max_val = 0;
    int max_diff = 0;
    for (int i = 0; i < 2 * N; i++) {
        int idx = i % N;
        cur_val += flag[idx];
        if (cur_val < min_val) {
            min_val = cur_val;
        } else if (cur_val > max_val) {
            max_val = cur_val;
        }
        int diff = max_val - min_val;
        if (diff > max_diff) {
            max_diff = diff;
            k = (idx + 1) % N;
        }
    }
    std::cout << k << " " << ans << std::endl;
}
