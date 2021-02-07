#include <bits/stdc++.h>


class Solution {
  public:
    int n1, n2;
    std::string w1, w2;

    int search(int pos1, int pos2, std::vector<std::vector<int>>& dp) {
        if (dp[pos2][pos1] != -1) {
            return dp[pos2][pos1];
        }

        if (w1[pos1] == w2[pos2]) {
            return search(pos1 + 1, pos2 + 1, dp);
        } else if (w1[pos1] > w2[pos2]) {
            dp[pos2][pos1] = 1;
            return dp[pos2][pos1];
        }
        dp[pos2][pos1] = 2;
        return dp[pos2][pos1];
    }

    std::string largestMerge(std::string word1, std::string word2) {
        w1 = word1;
        w2 = word2;
        n1 = w1.size();
        n2 = w2.size();
        std::vector<std::vector<int>> dp(n2 + 1, std::vector<int>(n1 + 1, -1));
        // 0 : even, 1 : word1 is larger, 2: word2 is larger
        dp[n2][n1] = 0;
        for (int i = 0; i < n2; i++) {
            dp[i][n1] = 2;
        }
        for (int i = 0; i < n1; i++) {
            dp[n2][i] = 1;
        }

        std::string word = word1 + word2;

        int pos1 = 0, pos2 = 0;
        for (int i = 0; i < word.size(); i++) {
            if (search(pos1, pos2, dp) <= 1) {
                word[i] = w1[pos1];
                pos1++;
            } else if (search(pos1, pos2, dp) == 2) {
                word[i] = w2[pos2];
                pos2++;
            }
        }
        return word;
    }
};


int main() {}
