#include <bits/stdc++.h>

class Solution {
public:
    int minimumIncompatibility(std::vector<int>& nums, int k) {
        std::vector<int> counts(16, 0);
        for (int i = 0; i < nums.size(); i++) {
            counts[nums[i] - 1]++;
        }

        std::vector<int> one;
        std::vector<std::pair<int, int>> multi;
        for (int i = 0; i < 16; i++) {
            if (counts[i] > k) {
                return -1;
            }
            if (counts[i] == 1) {
                one.emplace_back(i);
            } else {
                multi.emplace_back(std::make_pair(i, counts[i]));
            }
        }
        std::cout << "start" << std::endl;
        return search(one, multi, 0, nums.size() / k, k);
    }

    int search(std::vector<int> one, std::vector<std::pair<int, int>> _multi, int idx, int l, int k) {
        if (k == 0) {
            return 0;
        }
        int sum = -1;
        int num_multi = 0;
        for (auto pair : _multi) {
            if (pair.second > 0) {
                num_multi++;
            }
        }
        for (int i = std::min(l, num_multi); i >= 0; i--) {
            int num_pick_from_one = l - i;
            if (idx + num_pick_from_one - 1>= one.size()) {
                continue;
            }

            std::vector<std::pair<int, int>> multi = _multi;

            // pick i items from multi by small order
            int picked = 0;
            int min_val = -1;
            int max_val = -1;
            for (auto & pair : multi) {
                if (pair.second > 0) {
                    pair.second--;
                    if (picked == 0) {
                        min_val = pair.first;
                    }
                    picked++;
                    if (picked == i) {
                        max_val = pair.first;
                        break;
                    }
                }
            }

            if (max_val == -1) {
                // can't pick i items from multi
                continue;
            }
            int min = min_val, max = max_val;
            if (num_pick_from_one > 0) {
                min = std::min(one[idx], min_val);
                max = std::max(one[idx + num_pick_from_one - 1], max_val);
            }
            int res = search(one, multi, idx + num_pick_from_one, l, k - 1);

            if (res == -1) {
                continue;
            }
            if (sum == -1) {
                sum = max - min + res;
            } else {
                sum = std::min(max - min + res, sum);
            }
            std::cout << "k = " << k << ", res = " << res << ", sum = " << sum << std::endl;
        }
        return sum;
    }
};


int main() {

}
