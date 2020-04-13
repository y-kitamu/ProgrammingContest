/*
 * rgbtriples.cpp
 *
 * Create Date : 2020-04-12 21:24:37
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>


int main() {
    int N;
    std::string S;
    std::cin >> N >> S;
    std::map<char, std::vector<int>> idx_lists;
    idx_lists['R'] = std::vector<int>();
    idx_lists['G'] = std::vector<int>();
    idx_lists['B'] = std::vector<int>();

    for (int i = 0; i < N; i++) {
        idx_lists[S[i]].emplace_back(i);
    }

    long long int sum = idx_lists['R'].size() * idx_lists['G'].size() * idx_lists['B'].size();
    long long int not_cond = 0;

    auto count = [&S, &N] (int i1, int i2) {
        long long int cnt = 0;
        int diff = i2 - i1;
        int i_b0 = i1 - diff;
        int i_b1 = i2 + diff;
        if (i_b0 >= 0 && S[i_b0] == 'B') {
            cnt++;
        }
        if (i_b1 < N && S[i_b1] == 'B') {
            cnt++;
        }
        if (diff % 2 == 0) {
            int i_b2 = i1 + diff / 2;
            if (S[i_b2] == 'B') {
                cnt++;
            }
        }
        return cnt;
    };
    
    for (auto &i_r : idx_lists['R']) {
        for (auto &i_g : idx_lists['G']) {
            if (i_r < i_g) {
                not_cond += count(i_r, i_g);
            } else {
                not_cond += count(i_g, i_r);
            }
        }
    }
    std::cout << sum - not_cond << std::endl;
}
