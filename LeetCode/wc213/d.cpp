#include <bits/stdc++.h>


class Solution {
public:
    std::string kthSmallestPath(std::vector<int>& destination, int k) {
        std::vector<std::vector<int>> counts(
            destination[0] + 1, std::vector<int>(destination[1] + 1, 1));
        for (int row = 1; row <= destination[0]; row++) {
            for (int col = 1; col <= destination[1]; col++) {
                counts[row][col] = counts[row][col - 1] + counts[row - 1][col];
            }
        }
        int row = destination[0], col = destination[1];
        std::string str;
        while (row > 0 || col > 0) {
            if (row == 0) {
                str.append("H");
                col--;
                continue;
            }
            if (col == 0) {
                str.append("V");
                row--;
                continue;
            }
            if (k <= counts[row][col - 1]) {
                str.append("H");
                col--;
                continue;
            }
            k -= counts[row][col - 1];
            str.append("V");
            row--;
        }
        return str;
    }
};


int main() {
    std::vector<int> destination {2, 3};
    std::cout << Solution().kthSmallestPath(destination, 2) << std::endl;
}
