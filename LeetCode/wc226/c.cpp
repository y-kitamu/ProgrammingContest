#include <bits/stdc++.h>


class Solution {
  public:
    std::vector<bool> canEat(std::vector<int>& candiesCount, std::vector<std::vector<int>>& queries) {
        std::vector<long long int> candieSum(candiesCount.size() + 1, 0);
        for (int i = 0; i < candiesCount.size(); i++) {
            candieSum[i + 1] = candieSum[i] + candiesCount[i];
        }

        std::vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            auto query = queries[i];
            long long int max_cand = candieSum[query[0] + 1];
            long long int min_cand = candieSum[query[0]];
            std::cout << min_cand << " , " << (long long int)(query[1] + 1) * query[2] << " , "
                      << max_cand << ", " << query[1] << std::endl;
            ans[i] = (min_cand < (long long int)(query[1] + 1) * query[2] && query[1] < max_cand);
        }
        return ans;
    }
};


int main() {}
