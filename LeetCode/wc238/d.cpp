#include <bits/stdc++.h>

class Solution {
  public:
    int binarySearch(int min, int max, const int idx, const int val, std::vector<std::vector<int>> res) {
        if (min == max) {
            return min;
        }
        int mid = (min + max) / 2;
        if (res[mid][idx] == val) {
            return mid;
        }
        if (val < res[mid][idx]) {
            return binarySearch(min, mid - 1, idx, val, res);
        }
        return binarySearch(mid + 1, max, idx, val, res);
    }


    int maxBuilding(int n, std::vector<std::vector<int>>& restrictions) {
        restrictions.emplace_back(std::vector<int>({1, 0}));
        int num_res = restrictions.size();
        auto res = restrictions;
        std::sort(res.begin(), res.end(), [](auto& lhs, auto& rhs) { return lhs[0] < rhs[0]; });

        auto comp = [](auto& lhs, auto& rhs) { return lhs[1] > rhs[1]; };
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(comp)> que{comp};
        for (auto& r : res) {
            que.push(r);
        }

        std::vector<bool> flag(num_res, false);
        while (!que.empty()) {
            auto r = que.top();
            que.pop();
            if (flag[r[0]]) {
                continue;
            }
            auto idx = binarySearch(0, num_res, 0, r[0], res);
            res[idx] = r;
            if (idx > 0) {
                auto lhs = res[idx - 1];
                if (lhs[1] - r[1] > r[0] - lhs[0]) {
                    que.push(std::vector<int>({lhs[0], r[1] + r[0] - lhs[0]}));
                }
            }
            if (idx < num_res - 1) {
                auto rhs = res[idx + 1];
                if (rhs[1] - r[1] > rhs[0] - r[0]) {
                    que.push(std::vector<int>({rhs[0], r[1] + rhs[0] - r[0]}));
                }
            }
            flag[r[0]] = true;
        }

        for (auto& val : res) {
            std::cout << "(" << val[0] << ", " << val[1] << "), ";
        }
        std::cout << std::endl;

        int max = 0;
        for (int i = 0; i < num_res - 1; i++) {
            int idiff = res[i + 1][0] - res[i][0];
            int hdiff = std::abs(res[i + 1][1] - res[i][1]);
            int h = (idiff - hdiff) / 2 + std::max(res[i][1], res[i + 1][1]);
            max = std::max(h, max);
        }
        max = std::max(max, n - res[num_res - 1][0] + res[num_res - 1][1]);
        return max;
    }
};


int main() {}
