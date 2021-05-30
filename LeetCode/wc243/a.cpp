#include <bits/stdc++.h>


class Solution {
  public:
    bool isSumEqual(std::string firstWord, std::string secondWord, std::string targetWord) {
        return (calc_val(firstWord) + calc_val(secondWord)) == calc_val(targetWord);
    }

    int calc_val(std::string& word) {
        int val = 0;
        for (auto& c : word) {
            val *= 10;
            val += c - 'a';
        }
        return val;
    }
};

int main() {}
