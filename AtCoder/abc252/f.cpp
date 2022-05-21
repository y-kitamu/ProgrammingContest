/**
 * @file f.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-21 21:45:20
 */
#include <bits/stdc++.h>


int main() {
    long long N, L;
    std::cin >> N >> L;

    std::priority_queue<long long, std::vector<long long>, std::greater<>> que{std::greater<>()};
    for (int i = 0; i < N; i++) {
        long long a;
        std::cin >> a;
        que.push(a);
    }

    long long sum = 0;
    while (!que.empty()) {
        auto top = que.top();
        que.pop();
        auto second = que.top();
        que.pop();
        long long merge = top + second;
        if (que.empty()) {
            if (L == merge) {
                sum += L;
            } else {
                sum += std::min(2ll * L - top, L + top + second);
            }
            break;
        }
        sum += merge;
        que.push(merge);
    }
    std::cout << sum << std::endl;
}
