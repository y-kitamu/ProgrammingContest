#include <bits/stdc++.h>


class Solution {
public:
    int maxLengthBetweenEqualCharacters(std::string s) {
        std::vector<int> chars(26, -1);
        int max = -1;
        for (int i = 0; i < s.length(); i++) {
            int idx = s[i] - 'a';
            if (chars[idx] != -1) {
                max = std::max(i - chars[idx] - 1, max);
            } else {
                chars[idx] = i;
            }
        }
        return max;
    }
};

int main() {
    std::string str = "aa";
    Solution().maxLengthBetweenEqualCharacters(str);
}
