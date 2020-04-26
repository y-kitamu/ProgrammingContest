/*
 * multiple_of_2019.cpp
 *
 * Create Date : 2020-04-26 21:10:34
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>


static constexpr int multiple = 2019;

int main() {
    std::string c;
    std::cin >> c;

    int len = c.length();
    std::vector<int> str(len);
    for (auto i = 0; i < len; i++) {
        str[i] = c[i] - '0';
    }

    std::vector<int> mods(len);
    mods[0] = 1;
    for (auto i = 1; i < len; i++) {
        mods[i] = mods[i - 1] * 10 % multiple;
    }

    std::vector<int> sum_mods(len + 1);
    std::map<int, std::vector<int>> same_mod;
    sum_mods[len] = 0;
    same_mod[0].emplace_back(len);
    for (auto i = len - 1; i >= 0; i--) {
        sum_mods[i] = (sum_mods[i + 1] + str[i] * mods[len - i - 1]) % multiple;
        same_mod[sum_mods[i]].emplace_back(i);
    }

    int count = 0;
    for (auto vec : same_mod) {
        int len = vec.second.size();
        count += len * (len - 1) / 2;
    }

    std::cout << count << std::endl;
}
