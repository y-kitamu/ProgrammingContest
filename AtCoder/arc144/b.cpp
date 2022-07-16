/**
 * @file b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-07-16 21:09:10
 */
#include <bits/stdc++.h>


int main() {
    long long int N, a, b;
    std::cin >> N >> a >> b;

    std::vector<long long int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    long long int min = 1, max = 1e9;

    while (min != max) {
        long long int mid = (min + max + 1) / 2;

        long long int sum = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] >= mid) {
                sum += (A[i] - mid) / b;
            } else {
                sum -= (mid - A[i] + a - 1) / a;
            }
        }
        if (sum < 0) {
            max = mid - 1;
        } else {
            min = mid;
        }
    }
    std::cout << min << std::endl;
}
