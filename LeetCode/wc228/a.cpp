#include <bits/stdc++.h>

class Solution {
  public:
    int minOperations(std::string s) {
        int first0 = 0;
        int first1 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                if (i % 2 == 0) {
                    first1++;
                } else if (i % 2 == 1) {
                    first0++;
                }
            } else {
                if (i % 2 == 0) {
                    first0++;
                } else if (i % 2 == 1) {
                    first1++;
                }
            }
        }
        return std::min(first0, first1);
    }
};


int main() {}
