#include <bits/stdc++.h>

class Solution {
  public:
    int numDifferentIntegers(std::string word) {
        std::set<std::string> set;
        std::string str = "";
        for (int i = 0; i < word.length(); i++) {
            if (word[i] - '0' < 10) {
                str += word[i];
            } else {
                if (str.length() > 0) {
                    int idx = 0;
                    while (str[idx] == '0') {
                        idx++;
                    }
                    set.insert(str.substr(idx));
                }
                str = "";
            }
        }
        if (str.length() > 0) {
            int idx = 0;
            while (str[idx] == '0') {
                idx++;
            }
            set.insert(str.substr(idx));
        }
        return set.size();
    }
};


int main() {}
