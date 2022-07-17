/**
 * @file c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-07-17 21:16:22
 */
#include <bits/stdc++.h>


int main() {
    int N, X, Y;
    std::cin >> N >> X >> Y;

    long long int red = 1, blue = 0;
    for (int i = 0; i < N - 1; i++) {
        blue += red * X;
        red += blue;
        blue *= Y;
    }
    std::cout << blue << std::endl;
}
