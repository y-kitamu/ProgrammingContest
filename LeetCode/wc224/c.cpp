#include <bits/stdc++.h>

class Solution {
  public:
    int largestSubmatrix(std::vector<std::vector<int>>& matrix) {
        std::vector<std::pair<int, int>> pairs;
        int max_row = 1;
        for (int col = 0; col < matrix[0].size(); col++) {
            int start = -1, end = -1;
            for (int row = 0; row < matrix.size(); row++) {
                if (matrix[row][col] == 1) {
                    if (start == -1) {
                        start = end = row;
                    } else {
                        end = row;
                    }
                    max_row = std::max(row + 1, max_row);
                } else {
                    if (start != -1 && end != -1) {
                        pairs.emplace_back(std::make_pair(start, end));
                    }
                    start = end = -1;
                }
            }
            if (start != -1 && end != -1) {
                pairs.emplace_back(std::make_pair(start, end));
            }
        }

        std::sort(pairs.begin(), pairs.end(), [](auto& lhs, auto& rhs) {
            if (lhs.first < rhs.first) {
                return true;
            } else if (lhs.first > rhs.first) {
                return false;
            }
            return lhs.second > lhs.second;
        });

        std::vector<std::vector<int>> rcnts(max_row + 1, std::vector<int>(pairs.size() + 1, 0));
        std::vector<std::vector<int>> ccnts(max_row + 1, std::vector<int>(pairs.size() + 1, 0));
        std::vector<std::vector<int>> maxs(max_row + 1, std::vector<int>(pairs.size() + 1, 0));
        for (int row = 1; row <= max_row; row++) {
            for (int col = 1; col <= pairs.size(); col++) {
                if (pairs[col - 1].first <= row - 1 && row - 1 <= pairs[col - 1].second) {
                    rcnts[row][col] = rcnts[row - 1][col] + 1;
                    ccnts[row][col] = ccnts[row][col - 1] + 1;
                } else {
                    rcnts[row][col] = rcnts[row - 1][col];
                    ccnts[row][col] = ccnts[row][col - 1];
                }
                maxs[row][col] = std::max(maxs[row][col - 1], maxs[row - 1][col]);
                maxs[row][col] = std::max(maxs[row][col], rcnts[row][col] * ccnts[row][col]);
            }
        }
        return maxs[max_row][pairs.size()];
    }
};

int main() {}
