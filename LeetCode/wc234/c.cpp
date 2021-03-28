#include <bits/stdc++.h>


class Solution {
  public:
    std::string evaluate(std::string s, std::vector<std::vector<std::string>>& knowledge) {
        std::map<std::string, std::string> map;
        for (auto& pair_vec : knowledge) {
            map[pair_vec[0]] = pair_vec[1];
        }

        std::string res = "";
        std::string key = "";
        bool in_bracket = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                in_bracket = true;
                continue;
            } else if (s[i] == ')') {
                if (map.find(key) == map.end()) {
                    res += "?";
                } else {
                    res += map[key];
                }
                in_bracket = false;
                key = "";
                continue;
            }

            if (in_bracket) {
                key += s[i];
            } else {
                res += s[i];
            }
        }
        return res;
    }
};


int main() {}
