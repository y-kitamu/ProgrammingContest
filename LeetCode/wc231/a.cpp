#include <bits/stdc++.h>

class Solution {
  public:
    bool checkOnesSegment(std::string s) {
        int prev_pos = -1;
        bool flag = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                flag &= (prev_pos == -1 || prev_pos == i - 1);
                prev_pos = i;
            }
        }
        return flag;
    }
};


int main() {}
