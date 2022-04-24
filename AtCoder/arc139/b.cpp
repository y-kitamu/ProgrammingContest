/**
 * @file b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-04-24 21:13:56
 */
#include <bits/stdc++.h>


int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        long long int N, A, B, X, Y, Z;
        std::cin >> N >> A >> B >> X >> Y >> Z;

        if (A * Z > B * Y) {
            std::swap(A, B);
            std::swap(Y, Z);
        }

        if (B * X <= Z) {
            std::cout << N * X << std::endl;
            continue;
        }
        if (A * X <= Y) {
            std::cout << N / B * Z + N % B * X << std::endl;
            continue;
        }

        long long int cost = 1e18;
        long long int max_nb = N / B;
        for (int i = 0; i <= std::min(max_nb, (long long int)4e4); i++) {
            long long int nb = max_nb - i;
            long long int na = (N - nb * B) / A;
            long long int n1 = N - nb * B - na * A;
            cost = std::min(nb * Z + na * Y + n1 * X, cost);
            if (n1 == 0) {
                break;
            }
        }
        std::cout << cost << std::endl;
    }
}
