/*
 * a.cpp
 *
 * Create Date : 2021-10-24 11:28:44
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int countValidWords(std::string sentence) {
        std::string str = "";
        int cnt = 0;
        for (auto& c : sentence) {
            if (c == ' ') {
                if (str.length() > 0) {
                    if (check(str)) {
                        cnt++;
                    }
                }
                str = "";
            } else {
                str += c;
            }
        }
        if (str.length() > 0 && check(str)) {
            cnt++;
        }
        return cnt;
    }

    bool check(std::string cand) {
        int cnt = 0;
        for (int i = 0; i < cand.length(); i++) {
            int val = cand[i] - '0';
            // std::cout << val << " , " << cand[i] << std::endl;
            if (0 <= val && val <= 9) {
                return false;
            }
            if (i < cand.length() - 1) {
                if (cand[i] == '!' || cand[i] == '.' || cand[i] == ',') {
                    return false;
                }
            }
            if (cand[i] == '-') {
                if (cnt > 0) {
                    return false;
                }
                if (i == 0 || i == cand.length() - 1) {
                    return false;
                }
                int res = cand[i - 1] - 'a';
                if (res < 0 || 26 <= res) {
                    return false;
                }
                res = cand[i + 1] - 'a';
                if (res < 0 || 26 <= res) {
                    return false;
                }
                cnt++;
            }
        }
        return true;
    }
};

int main() {}
