/**
 * @file c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-07-16 21:15:06
 */
#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;

    if (N < K * 2) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::vector<int> vals(N);
    std::iota(vals.begin(), vals.end(), 1);
    std::set<int> set(vals.begin(), vals.end());

    std::vector<int> ans(N);
    for (int i = 0; i < N - K * 2; i++) {
        if (i / K % 2 == 0) {
            ans[i] = i + 1 + K;
            set.erase(i + 1 + K);
        } else {
            ans[i] = i + 1 - K;
            set.erase(i + 1 - K);
        }
    }
    for (int i = 0; i < K; i++) {
        ans[N - K * 2 + i] = N - K * 2 + i + 1 + K;
        set.erase(ans[N - K * 2 + i]);
    }

    auto itr = set.begin();
    for (int i = 0; i < K; i++, itr++) {
        ans[N - K + i] = *itr;
    }


    //
    for (int i = 0; i < N; i++) {
        std::cout << ans[i];
        if (i != N - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}
