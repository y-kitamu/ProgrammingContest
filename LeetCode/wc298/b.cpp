/**
 * @file b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-19 11:34:44
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int minimumNumbers(int num, int k) {
        if (num == 0) {
            return 0;
        }
        if (k == 0) {
            if (num % 10 == 0) {
                return 1;
            }
            return -1;
        }
        int cnt = 1;
        int min = k;
        while (num >= min) {
            if ((num - min) % 10 == 0) {
                return cnt;
            }
            cnt++;
            min += k;
        }
        return -1;
    }
};


int main() {}
