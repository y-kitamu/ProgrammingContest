#include <bits/stdc++.h>


class Solution {
  public:
    int minimumBoxes(int n) {
        int idx = 1;
        int val = 1;
        while (n - val >= 0) {
            n -= val;
            idx++;
            val += idx;
        }
        val -= idx;

        if (n > 0) {
            int res = 1;
            while (n > res) {
                n -= res;
                res++;
            }
            val += res;
        }
        return val;
    }
};


int main() {}
