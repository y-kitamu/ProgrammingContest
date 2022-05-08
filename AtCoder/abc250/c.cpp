/**
 * @file c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-08 21:09:50
 */
#include <bits/stdc++.h>


int main() {
    int N, Q;

    std::cin >> N >> Q;
    std::vector<int> idx(N);
    std::iota(idx.begin(), idx.end(), 0);
    std::vector<int> x(N);
    std::iota(x.begin(), x.end(), 0);

    for (int i = 0; i < Q; i++) {
        int val;
        std::cin >> val;
        int ilhs = idx[--val];
        if (ilhs == N - 1) {
            ilhs--;
        }
        int vrhs = x[ilhs + 1];
        std::swap(idx[val], idx[vrhs]);
        std::swap(x[ilhs], x[ilhs + 1]);
    }

    for (int i = 0; i < N; i++) {
        std::cout << x[i] + 1;
        if (i < N - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}
