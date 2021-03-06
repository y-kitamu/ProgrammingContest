#include <bits/stdc++.h>

class Solution {
public:
    int waysToSplit(std::vector<int>& nums) {
        long long int MOD = 1e9 + 7;

        int N = nums.size();
        std::vector<long long int> sums(N, 0);
        sums[0] = nums[0];
        for (int i = 1; i < N; i++) {
            sums[i] = sums[i - 1] + nums[i];
        }

        long long int mini = 0, maxi = 0;
        long long int count = 0;
        for (long long int i = 0; i < N; i++) {
            mini = std::max(mini, i + 1);
            if (sums[i] * 3 > sums[N - 1]) {
                break;
            }
            while (sums[i] * 2 > sums[mini]) {
                mini++;
            }
            maxi = std::max(mini, maxi);
            if (sums[mini] - sums[i] > sums[N - 1] - sums[mini]) {
                break;
            }
            while (maxi < N && sums[maxi] - sums[i] <= sums[N - 1] - sums[maxi]) {
                maxi++;
            }
            count = (count + maxi - mini) % MOD;
        }
        return count;
    }
};


int main() {

}
