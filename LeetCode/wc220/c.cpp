#include <bits/stdc++.h>

class Solution {
public:
    int maxResultNaive(std::vector<int>& nums, int k) {
        int length = nums.size();

        std::vector<int> scores(length, (int)-2e9);
        scores[0] = nums[0];
        for (int i = 1; i < length; i++) {
            for (int j = std::max(i - k, 0); j < i; j++) {
                scores[i] = std::max(scores[i], scores[j] + nums[i]);
            }
        }
        return scores[length - 1];
    }

    int maxResult(std::vector<int>& nums, int k) {

    }
};


int main() {

}
