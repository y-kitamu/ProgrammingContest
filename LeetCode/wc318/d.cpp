/**
 * @file d.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-11-06 12:09:01
 */
#include <bits/stdc++.h>


class Solution {
  public:
    long long minimumTotalDistance(std::vector<int>& robot, std::vector<std::vector<int>>& factory) {
        std::sort(robot.begin(), robot.end());
        std::sort(factory.begin(), factory.end(),
                  [](const std::vector<int>& a, const std::vector<int>& b) { return a[0] < b[0]; });
        std::vector<int> facs;
        for (auto& f : factory) {
            for (int i = 0; i < f[1]; i++) {
                facs.push_back(f[0]);
            }
        }

        std::cout << "robot = ";
        for (auto& r : robot) {
            std::cout << r << " ";
        }
        std::cout << std::endl;

        std::cout << "facs = ";
        for (auto& val : facs) {
            std::cout << val << " ";
        }
        std::cout << std::endl;

        std::vector<long long> dp(facs.size() + 1, 0);
        for (int i = 0; i < robot.size(); i++) {
            std::vector<long long> next(facs.size() + 1, 1e18);
            for (int j = 0; j < facs.size(); j++) {
                next[j + 1] = std::min(next[j], dp[j] + std::abs(robot[i] - facs[j]));
            }

            std::cout << "i = " << i << std::endl;
            for (auto& val : next) {
                std::cout << val << " ";
            }
            std::cout << std::endl;

            dp = next;
        }
        return dp[facs.size()];
    }
};

int main() {}
