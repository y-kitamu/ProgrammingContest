/**
 * @file d.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-26 12:03:05
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int minimumScore(std::vector<int>& nums, std::vector<std::vector<int>>& edges) {
        int n = nums.size();
        std::vector<std::vector<int>> ll(n);
        for (auto& edge : edges) {
            ll[edge[0]].emplace_back(edge[1]);
            ll[edge[1]].emplace_back(edge[0]);
        }
        std::vector<int> flag(n, -1);
        int total = calcSum(0, flag, nums, ll);

        return solve(0, total, -1, flag, ll);
    }

    int calcSum(int root, std::vector<int>& flag, std::vector<int>& vals,
                std::vector<std::vector<int>>& ll) {
        flag[root] = vals[root];
        for (auto& next : ll[root]) {
            if (flag[next] == -1) {
                flag[root] ^= calcSum(next, flag, vals, ll);
            }
        }
        return flag[root];
    }

    int solve(int root, int total, int parent, std::vector<int>& vals,
              std::vector<std::vector<int>>& ll) {
        int min = 1e9;
        for (auto& next : ll[root]) {
            if (next == parent) {
                continue;
            }
            min = std::min(min, solve(next, total, root, vals, ll));

            std::queue<std::vector<int>> que;
            int res = vals[next];
            int other = total ^ res;
            for (auto& nx : ll[root]) {
                if (nx != next) {
                    que.push({nx, root, res, other});
                }
            }
            for (auto& nx : ll[next]) {
                if (nx != root) {
                    que.push({nx, next, other, res});
                }
            }

            while (!que.empty()) {
                auto vec = que.front();
                std::cout << next << " " << vec[0] << std::endl;
                que.pop();
                int r = vals[vec[0]];
                int o = vec[3] ^ r;

                int mn = std::min(std::min(std::abs(r - vec[2]), std::abs(o - vec[2])), std::abs(r - o));
                min = std::min(mn, min);

                for (auto& nx : ll[vec[0]]) {
                    if (nx == vec[1]) {
                        continue;
                    }
                    que.push({nx, vec[0], vec[2], vec[3]});
                }
            }
        }
        return min;
    }
};


int main() {}
