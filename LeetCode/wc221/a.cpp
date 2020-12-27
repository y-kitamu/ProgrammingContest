#include <bits/stdc++.h>

class Solution {
public:
    bool halvesAreAlike(std::string s) {
        std::vector<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int lcnt = 0, rcnt = 0;
        int offset = s.length() / 2;
        for (int i = 0; i < offset; i++) {
            for (auto vowel : vowels) {
                if (vowel == s[i]) {
                    lcnt++;
                }
                if (vowel == s[i + offset]) {
                    rcnt++;
                }
            }
        }
        return lcnt == rcnt;
    }
};


int main() {

}
