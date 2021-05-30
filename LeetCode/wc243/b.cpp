#include <bits/stdc++.h>


class Solution {
  public:
    std::string maxValue(std::string n, int x) {
        std::string out = "";
        int idx = 0;
        if (n[0] == '-') {
            out += '-';
            idx++;
            while (idx < n.length() && n[idx] - '0' <= x) {
                out += n[idx];
                idx++;
            }
        } else {
            while (idx < n.length() && n[idx] - '0' >= x) {
                out += n[idx];
                idx++;
            }
        }
        out += std::to_string(x);
        for (; idx < n.length(); idx++) {
            out += n[idx];
        }
        return out;
    }
};


int main() {}
