#include <bits/stdc++.h>


class Solution {
  public:
    std::vector<int> sort_index(std::vector<int>& ref) {
        std::vector<int> idx(ref.size());
        std::iota(idx.begin(), idx.end(), 0);
        std::sort(idx.begin(), idx.end(), [&ref](auto& lhs, auto& rhs) { return ref[lhs] < ref[rhs]; });
        return idx;
    }

    int minAbsoluteSumDiff(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n = nums1.size();
        auto sorted_idx = sort_index(nums1);
        // std::vector<int> sorted_idx(n, 0);
        // std::iota(sorted_idx.begin(), sorted_idx.end(), 0);

        std::vector<int> sorted1(n), sorted2(n);
        for (int i = 0; i < n; i++) {
            sorted1[i] = nums1[sorted_idx[i]];
            sorted2[i] = nums2[sorted_idx[i]];
        }

        int pos = 0;
        int max_diff = 0;
        long long int sum = 0;
        auto compare = [&sorted2, &pos, &max_diff](auto itr, auto asd_before, auto i) {
            auto diff = asd_before - std::abs(sorted2[i] - *itr);
            if (diff > max_diff) {
                max_diff = diff;
                pos = i;
            }
        };

        auto print_vec = [](std::vector<int> vec) {
            for (auto& val : vec) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        };
        print_vec(sorted1);
        print_vec(sorted2);

        for (int i = 0; i < n; i++) {
            int asd_before = std::abs(sorted2[i] - sorted1[i]);
            sum += asd_before;
            auto itr = std::lower_bound(sorted1.begin(), sorted1.end(), sorted2[i]);
            if (itr != sorted1.end()) {
                compare(itr, asd_before, i);
            }
            if (itr != sorted1.begin()) {
                itr--;
                compare(itr, asd_before, i);
            }
        }

        std::cout << pos << " " << max_diff << std::endl;
        long long int mod = 1e9 + 7;
        sum = (sum - max_diff) % mod;
        return sum;
    }
};


int main() {}
