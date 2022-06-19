/**
 * @file d.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-19 12:03:40
 */
#include <bits/stdc++.h>

class Solution {
  public:
    long long sellingWood(int m, int n, std::vector<std::vector<int>>& prices) {
        std::vector<std::vector<long long>> rgrid(m + 1, std::vector<long long>(n + 1, 0)),
            cgrid(m + 1, std::vector<long long>(n + 1, 0));
        for (auto& price : prices) {
            long long h = price[0], w = price[1], v = price[2];
            for (int i = w; i <= n; i++) {
                rgrid[h][i] = std::max(rgrid[h][i], rgrid[h][i - w] + v);
            }
            for (int i = h; i <= m; i++) {
                cgrid[i][w] = std::max(cgrid[i][w], cgrid[i - h][w] + v);
            }
        }

        // auto pprint = [](auto& vvec) {
        //     for (auto& vec : vvec) {
        //         for (auto& val : vec) {
        //             std::cout << val << " ";
        //         }
        //         std::cout << std::endl;
        //     }
        // };
        // std::cout << "rgrid" << std::endl;
        // pprint(rgrid);
        // std::cout << "cgrid" << std::endl;
        // pprint(cgrid);

        std::vector<long long> rows(m + 1), cols(n + 1);
        for (int i = 0; i <= m; i++) {
            rows[i] = rgrid[i][0];
            for (int j = 1; j <= n; j++) {
                rows[i] = std::max(rgrid[i][j], rows[i]);
            }
        }
        for (int i = 0; i <= n; i++) {
            cols[i] = cgrid[0][i];
            for (int j = 1; j <= m; j++) {
                cols[i] = std::max(cgrid[j][i], cols[i]);
            }
        }

        // auto print = [](auto& vec) {
        //     for (auto& val : vec) {
        //         std::cout << val << " ";
        //     }
        //     std::cout << std::endl;
        // };
        // print(rows);
        // print(cols);

        std::vector<long long> dpv(m + 1, 0), dph(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            for (int j = i; j <= m; j++) {
                dpv[j] = std::max(dpv[j], dpv[j - i] + rows[i]);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                dph[j] = std::max(dph[j], dph[j - i] + cols[i]);
            }
        }

        long long ans = 0;
        for (auto& val : dpv) {
            ans = std::max(ans, val);
        }
        for (auto& val : dph) {
            ans = std::max(ans, val);
        }
        return ans;
    }
};


int main() {}
