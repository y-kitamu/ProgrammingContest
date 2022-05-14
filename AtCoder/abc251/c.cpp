/**
 * @file c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-14 21:08:26
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> S(N);
    std::vector<int> T(N);
    std::map<std::string, int> map;

    int ians = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> S[i] >> T[i];
        if (map.find(S[i]) == map.end()) {
            map[S[i]] = T[i];
            if (T[ians] < T[i]) {
                ians = i;
            }
        }
    }
    std::cout << ians + 1 << std::endl;
}
