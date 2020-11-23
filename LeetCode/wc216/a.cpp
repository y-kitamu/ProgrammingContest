#include <bits/stdc++.h>

class Solution {
public:
    bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2) {
        std::string w1 = "", w2 = "";
        for (auto w : word1) {
            w1 += w;
        }
        for (auto w : word2) {
            w2 += w;
        }
        return w1 == w2;
    }
};


int main() {

}
