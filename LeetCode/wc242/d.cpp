#include <bits/stdc++.h>


class Solution {
  public:
    int stoneGameVIII(std::vector<int>& stones) {
        int n = stones.size();
        std::vector<long long int> sum(n, 0);
        sum[0] = stones[0];
        for (int i = 1; i < n; i++) {
            sum[i] += sum[i - 1] + stones[i];
        }

        long long int max = sum[n - 1];
        for (int i = 1; i < n - 1; i++) {
            max = std::max(max, sum[i] - sum[n - 1]);
        }
        return max;
    }
};


int main() {}
