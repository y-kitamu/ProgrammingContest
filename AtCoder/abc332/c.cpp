/**
 * @file c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2023-12-10 21:15:41
 */
#include <bits/stdc++.h>


int main(int argc, char** argv) {
    int N, M;
    std::string S;
    std::cin >> N >> M >> S;

    int cur_m = 0, cur_t = 0;
    int max_m = M, max_t = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '0') {
            max_t = std::max(max_t, cur_t);
            cur_m = 0;
            cur_t = 0;
        } else if (S[i] == '1') {
            if (cur_m == M) {
                cur_t++;
            } else {
                cur_m++;
            }
        } else {
            cur_t++;
        }
    }
    max_t = std::max(max_t, cur_t);

    std::cout << max_m + max_t - M << std::endl;
}
