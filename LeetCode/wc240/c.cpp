#include <bits/stdc++.h>

class Solution {
  public:
    std::vector<int> index_sort(std::vector<int>& vec) {
        std::vector<int> indices(vec.size());
        std::iota(indices.begin(), indices.end(), 0);
        std::sort(indices.begin(), indices.end(),
                  [&vec](auto& lhs, auto& rhs) { return vec[lhs] > vec[rhs]; });
        return indices;
    }

    int maxSumMinProduct(std::vector<int>& nums) {
        std::vector<int> roots(nums.size());
        std::iota(roots.begin(), roots.end(), 0);
        auto find_root = [&roots](auto idx) {
            std::vector<int> indices;
            while (roots[idx] != idx) {
                indices.emplace_back(idx);
                idx = roots[idx];
            }
            for (auto& i : indices) {
                roots[i] = idx;
            }
            return idx;
        };

        std::vector<long long int> sum(nums.size());
        auto sorted_idx = index_sort(nums);

        long long int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            int idx = sorted_idx[i];
            sum[idx] = nums[idx];

            if (idx > 0) {
                auto lroot = find_root(idx - 1);
                if (sum[lroot] > 0) {
                    sum[idx] += sum[lroot];
                    roots[lroot] = idx;
                }
            }
            if (idx < nums.size() - 1) {
                auto rroot = find_root(idx + 1);
                if (sum[rroot] > 0) {
                    sum[idx] += sum[rroot];
                    roots[rroot] = idx;
                }
            }
            max = std::max(sum[idx] * nums[idx], max);
        }
        long long int MOD = 1e9 + 7;
        int res = max % MOD;
        return res;
    }
};


int main() {}
