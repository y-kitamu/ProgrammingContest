/**
 * @file b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2023-12-10 21:07:47
 */
#include <bits/stdc++.h>


int main(int argc, char** argv) {
    int K, G, M;
    std::cin >> K >> G >> M;

    int cur_g = 0, cur_m = 0;
    for (int i = 0; i < K; i++) {
        if (cur_g == G) {
            cur_g = 0;
        } else if (cur_m == 0) {
            cur_m = M;
        } else {
            int add = std::min(G - cur_g, cur_m);
            cur_g += add;
            cur_m -= add;
        }
    }
    std::cout << cur_g << " " << cur_m << std::endl;
}
