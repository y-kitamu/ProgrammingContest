#include <bits/stdc++.h>


class Solution {
  public:
    int kthLargestValue(std::vector<std::vector<int>> &matrix, int k) {
        std::vector<int> values((matrix.size() + 1) * (matrix[0].size() + 1), 0);

        int rows = matrix.size(), cols = matrix[0].size();
        for (int row = 1; row <= rows; row++) {
            for (int col = 1; col <= cols; col++) {
                int idx = row * (cols + 1) + col;
                values[idx] = matrix[row - 1][col - 1] ^ values[idx - 1] ^ values[idx - cols - 1] ^
                              values[idx - cols - 2];
            }
        }

        std::sort(values.begin(), values.end(), [](auto &lhs, auto &rhs) { return lhs > rhs; });
        return values[k - 1];
    }
};


int main() {}
