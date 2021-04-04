#include <bits/stdc++.h>

class Solution {
  public:
    std::vector<std::string> split(std::string str, char separator) {
        std::vector<std::string> res;
        int s_pos = 0;
        while (s_pos != std::string::npos) {
            int next = str.find(separator, s_pos + 1);
            if (next == std::string::npos) {
                res.emplace_back(str.substr(s_pos));
            } else {
                res.emplace_back(str.substr(s_pos, next - s_pos));
            }
            s_pos = next;
        }
        return res;
    }

    std::string truncateSentence(std::string s, int k) {
        auto sep = split(s, ' ');
        std::string res = "";
        for (int i = 0; i < k; i++) {
            res += sep[i];
        }
        return res;
    }
};


int main() {}
