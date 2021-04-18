#include <bits/stdc++.h>

class Solution {
  public:
    bool checkIfPangram(std::string sentence) {
        std::vector<int> count(26, 0);
        for (auto& c : sentence) {
            count[c - 'a']++;
        }

        bool flag = true;
        for (int i = 0; i < 26; i++) {
            flag &= count[i] > 0;
        }
        return flag;
    }
};


int main() {}
