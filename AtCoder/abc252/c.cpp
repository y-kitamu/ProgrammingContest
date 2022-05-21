/**
 * @file c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-21 21:08:00
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<std::string> S(N);
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
    }

    int min = 1e5;
    for (int i = 0; i < 10; i++) {
        std::vector<int> cnts(10, 0);
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 10; k++) {
                if (S[j][k] == '0' + i) {
                    cnts[k]++;
                    break;
                }
            }
        }
        int cur = 0;
        int cnt = 0;
        while (cnt < N) {
            if (cnts[cur % 10] != 0) {
                cnts[cur % 10]--;
                cnt++;
            }
            cur++;
        }
        cur--;
        min = std::min(cur, min);
    }
    std::cout << min << std::endl;
}
