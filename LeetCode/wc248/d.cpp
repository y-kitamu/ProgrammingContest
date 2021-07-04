/*
 * d.cpp
 *
 * Create Date : 2021-07-04 11:46:12
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int longestCommonSubpath(int n, std::vector<std::vector<int>>& paths) {
        int m = paths.size();
        int max = 1e5;
        for (auto& path : paths) {
            max = std::min((int)path.size(), max);
        }

        int min = 0;
        while (min != max) {
            int mid = (min + max + 1) / 2;
            std::cout << "min = " << min << ", max = " << max << ", mid = " << mid << std::endl;

            std::map<std::string, int> cnts;
            for (auto& path : paths) {
                std::set<std::string> set;
                std::string val = "";
                for (int i = 0; i < mid - 1; i++) {
                    val += std::to_string(path[i]);
                }

                for (int i = mid - 1; i < path.size(); i++) {
                    val += std::to_string(path[i]);
                    if (set.find(val) == set.end()) {
                        set.insert(val);
                        std::cout << val << " ";
                        if (cnts.find(val) == cnts.end()) {
                            cnts[val] = 0;
                        }
                        cnts[val]++;
                    }
                    val = val.erase(0, std::to_string(path[i - mid + 1]).length());
                }
                std::cout << std::endl;
            }

            bool flag = false;
            for (auto& pair : cnts) {
                std::cout << pair.first << " = " << pair.second << std::endl;
                if (pair.second == m) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                min = mid;
            } else {
                max = mid - 1;
            }
        }

        return min;
    }
};


int main() {}
