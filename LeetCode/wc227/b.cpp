#include <bits/stdc++.h>


class Solution {
  public:
    int maximumScore(int a, int b, int c) {
        int cnt = 0;
        while ((a == 0) + (b == 0) + (c == 0) < 2) {
            if (a >= c && b >= c) {
                a--;
                b--;
            } else if (b >= a && c >= a) {
                b--;
                c--;
            } else {
                c--;
                a--;
            }
            cnt++;
        }
        return cnt;
    }
};

int main() {}
