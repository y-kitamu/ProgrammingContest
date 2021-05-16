#include <bits/stdc++.h>


class FindSumPairs {
  public:
    FindSumPairs(std::vector<int>& nums1, std::vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for (auto& val : nums2) {
            if (counts.find(val) == counts.end()) {
                counts[val] = 0;
            }
            counts[val]++;
        }
    }

    void add(int index, int val) {
        counts[n2[index]]--;
        n2[index] += val;
        int res = n2[index];
        if (counts.find(res) == counts.end()) {
            counts[res] = 0;
        }
        counts[res]++;
    }

    int count(int tot) {
        int sum = 0;
        for (int i = 0; i < n1.size(); i++) {
            int res = tot - n1[i];
            if (counts.find(res) != counts.end()) {
                sum += counts[res];
            }
        }
        return sum;
    }

    std::vector<int> n1, n2;
    std::map<int, int> counts;
};


int main() {}
