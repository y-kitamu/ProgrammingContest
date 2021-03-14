#include <bits/stdc++.h>

class Solution {
  public:
    bool areAlmostEqual(std::string s1, std::string s2) {
        if (s1 == s2) {
            return true;
        }

        int flag = false;
        int cnt = 0;
        char c1, c2;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (cnt == 0) {
                    c1 = s1[i];
                    c2 = s2[i];
                } else if (cnt == 1) {
                    flag = c1 == s2[i] && c2 == s1[i];
                } else {
                    return false;
                }
                cnt++;
            }
        }
        return flag;
    }
};

int main() {}
