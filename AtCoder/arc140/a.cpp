/**
 * @file a.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-15 20:58:28
 */
#include <bits/stdc++.h>


int main() {
    int N, K;
    std::string S;
    std::cin >> N >> K >> S;

    for (int i = 1; i < N; i++) {
        if (N % i != 0) {
            continue;
        }
        std::vector<std::map<char, int>> maps(i);
        for (int j = 0; j < N; j += i) {
            for (int k = 0; k < i; k++) {
                if (j + k < N) {
                    maps[k][S[j + k]]++;
                }
            }
        }
        int sum = 0;
        for (int j = 0; j < i; j++) {
            int cnt = 0;
            int max = 0;
            for (auto& p : maps[j]) {
                cnt += p.second;
                max = std::max(max, p.second);
            }
            sum += cnt - max;
        }
        if (sum <= K) {
            std::cout << i << std::endl;
            return 0;
        }
    }
    std::cout << N << std::endl;
}
