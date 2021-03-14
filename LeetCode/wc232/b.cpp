#include <bits/stdc++.h>


class Solution {
  public:
    int findCenter(std::vector<std::vector<int>>& edges) {
        int c0 = edges[0][0];
        int c1 = edges[0][1];
        int c2 = edges[1][0];
        int c3 = edges[1][1];
        if (c0 == c2 || c0 == c3) {
            return c0;
        }
        return c1;
    }
};


int main() {}
