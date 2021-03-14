#include <bits/stdc++.h>

class Solution {
  public:
    int maximumScore(std::vector<int>& nums, int k) {
        std::vector<std::pair<int, int>> before;
        std::vector<std::pair<int, int>> after;

        int min = nums[k];
        for (long long int i = k - 1; i >= 0; i--) {
            if (nums[i] < min) {
                before.emplace_back(std::make_pair(i + 1, min));
                min = nums[i];
            }
        }
        before.emplace_back(std::make_pair(0, min));

        min = nums[k];
        for (int i = k + 1; i < nums.size(); i++) {
            if (nums[i] < min) {
                after.emplace_back(std::make_pair(i - 1, min));
                min = nums[i];
            }
        }
        after.emplace_back(std::make_pair(nums.size() - 1, min));

        int score = 0;
        int bidx = 0;
        int aidx = 0;
        while (true) {
            if (bidx == before.size() - 1 && aidx == after.size() - 1) {
                break;
            }
            auto b = before[bidx];
            auto a = after[aidx];
            score = std::max((a.first - b.first + 1) * std::min(a.second, b.second), 0);

            if (aidx == after.size() - 1) {
                bidx++;
            } else if (bidx == before.size() - 1) {
                aidx++;
            } else if (before[bidx + 1].second > after[aidx + 1].second) {
                bidx++;
            } else {
                aidx++;
            }
        }

        return score;
    }
};


int main() {}
