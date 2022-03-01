/*
 * a.cpp
 *
 * Create Date : 2022-02-27 20:59:26
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

int main() {
    int N;
    std::string S;
    std::cin >> N >> S;

    std::string tmp = "";
    for (auto& c : S) {
        if (c == 'A') {
            tmp += "BB";
        } else {
            tmp += c;
        }
    }

    std::string ans = "";
    for (int i = 0; i < tmp.length(); i++) {
        if (tmp[i] == 'C') {
            ans += tmp[i];
        } else {
            if (i + 1 < tmp.length() && tmp[i + 1] == 'B') {
                ans += 'A';
                i++;
            } else {
                ans += 'B';
            }
        }
    }
    std::cout << ans << std::endl;
}
