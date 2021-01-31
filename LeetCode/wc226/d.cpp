#include <bits/stdc++.h>


class Solution {
  public:
    std::string str;
    std::vector<std::vector<int>> memo;

    bool search(int i, int j) {
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (j - i <= 1) {
            memo[i][j] = str[i] == str[j];
            return memo[i][j];
        }
        memo[i][j] = str[i] == str[j] && search(i + 1, j - 1);
        return memo[i][j];
    }

    bool checkPartitioning(std::string s) {
        str = s;
        memo = std::vector<std::vector<int>>(s.size(), std::vector<int>(s.size(), -1));
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                search(i, j);
            }
        }

        bool flag = false;
        for (int i = 0; i < memo.size() - 1; i++) {
            for (int j = i + 1; j < memo.size() - 1; j++) {
                flag |= memo[0][i] && memo[i + 1][j] && memo[j + 1][memo.size() - 1];
            }
        }
        return flag;
    }
};

int main() {}
