#include <bits/stdc++.h>


class Solution {
public:
    int maxDepth(std::string s) {
        int depth = 0;
        int max_depth = 0;
        for (auto c : s) {
            if (c == '(') {
                depth++;
                max_depth = std::max(max_depth, depth);
            }
            if (c == ')') {
                depth--;
            }
        }
        return max_depth;
    }
};


int main() {

}
