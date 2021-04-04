#include <bits/stdc++.h>

class Solution {
  public:
    std::vector<int> findingUsersActiveMinutes(std::vector<std::vector<int>>& logs, int k) {
        std::map<int, std::set<int>> map;
        for (auto& log : logs) {
            map[log[0]].insert(log[1]);
        }

        std::vector<int> res(k, 0);
        for (auto& pair : map) {
            int uam = pair.second.size();
            if (1 <= uam && uam <= k) {
                res[uam - 1]++;
            }
        }
        return res;
    }
};


int main() {}
