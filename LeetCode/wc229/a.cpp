#include <bits/stdc++.h>

class Solution {
  public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        std::string merged = "";
        int min = std::min(word1.length(), word2.length());
        for (int i = 0; i < min; i++) {
            merged += word1[i];
            merged += word2[i];
        }

        if (word1.length() > min) {
            merged += word1.substr(min);
        }
        if (word2.length() > min) {
            merged += word2.substr(min);
        }
        return merged;
    }
};


int main() {}
