#include <bits/stdc++.h>


using ll = long long int;

class Solution {
  public:
    int maxValue(int n, int index, int maxSum) {
        index++;
        int idx1 = std::min(index, n - index + 1);
        maxSum -= n;
        std::cout << idx1 << " , " << maxSum << std::endl;
        if (idx1 > 31 || maxSum >> idx1 == 0) {
            int cnt = std::sqrt(maxSum);
            return cnt + 1;
        }
        maxSum -= idx1 * idx1;
        int cons = idx1 * 2 - 1;
        int idx2 = std::max(index, n - index + 1) - idx1;
        std::cout << idx2 << " , " << maxSum << std::endl;
        if ((2 * cons + idx2 + 1) * idx2 >= maxSum * 2) {
            int val = binarySearch(0, 1e9, 2 * cons + 1, maxSum * 2);
            return idx1 + 1 + val;
        }
        maxSum -= (2 * cons + idx2 + 1) * idx2 / 2;
        std::cout << maxSum << std::endl;
        return maxSum / n + idx1 + idx2 + 1;
    }

    int binarySearch(ll min, ll max, ll cons2, ll sum2) {
        if (min == max) {
            return min;
        }
        ll mid = (min + max + 1) / 2;
        if ((cons2 + mid) * mid <= sum2) {
            return binarySearch(mid, max, cons2, sum2);
        }
        return binarySearch(min, mid - 1, cons2, sum2);
    }
};


int main() {}
