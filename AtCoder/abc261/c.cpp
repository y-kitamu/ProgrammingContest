/**
 * @file c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-07-23 21:07:54
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::map<std::string, int> map;

    for (int i = 0; i < N; i++) {
        std::string s;
        std::cin >> s;
        if (map.find(s) == map.end()) {
            std::cout << s << std::endl;
            map[s] = 1;
        } else {
            std::cout << s << "(" << map[s] << ")" << std::endl;
            map[s]++;
        }
    }
}
