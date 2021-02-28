#include <bits/stdc++.h>

class Solution {
  public:
    int countMatches(std::vector<std::vector<std::string>>& items, std::string ruleKey,
                     std::string ruleValue) {
        int idx = 0;
        if (ruleKey == "color") {
            idx = 1;
        } else if (ruleKey == "name") {
            idx = 2;
        }

        int cnt = 0;
        for (auto item : items) {
            cnt += item[idx] == ruleValue;
        }
        return cnt;
    }
};

int main() {}
