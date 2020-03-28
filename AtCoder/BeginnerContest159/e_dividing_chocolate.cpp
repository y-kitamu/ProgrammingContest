/*
 * e_dividing_chocolate.cpp
 *
 * Create Date : 2020-03-28 11:11:19
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>
#include <vector>

int judge(const std::vector<std::vector<int>> &count, const std::vector<int> & perm,
          const int K, const int W) {
    auto h_div_count = perm.size();
    std::vector<int> v_perm;
    auto prev_idx = 0;
    for (auto idx = 1 ;idx < W + 1;) {
        for (auto h_idx = 1; h_idx < h_div_count; h_idx++) {
            int choco_num = count[perm[h_idx]][idx] - count[perm[h_idx]][prev_idx]
                - count[perm[h_idx - 1]][idx] + count[perm[h_idx - 1]][prev_idx];
            if (choco_num > K) {
                if (idx - prev_idx == 1) {
                    return -1;
                }
                v_perm.push_back(idx - 1);
                prev_idx = idx - 1;
                idx--;
                break;
            }
        }
        idx++;
    }
    return perm.size() + v_perm.size() - 2;
}

int main() {
    int H, W, K;

    std::cin >> H >> W >> K;

    std::vector<std::vector<char>> S(H, std::vector<char>(W));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            std::cin >> S[h][w];
        }
    }

    std::vector<std::vector<int>> count(H + 1, std::vector<int>(W + 1, 0));
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            int val = S[h - 1][w - 1] == '0' ? 0 : 1;
            count[h][w] += val
                + count[h - 1][w] + count[h][w - 1] - count[h - 1][w - 1];
        }
    }

    int min_div_c = W + H -2;
    for (int bit = 0; bit < (1 << (H - 1)); bit++) {
        std::vector<int> perm;
        perm.push_back(0);
        for (int i = 0; i < H - 1; i++) {
            if (bit & (1 << i)) {
                perm.push_back(i + 1);
            }
        }
        perm.push_back(H);

        int div_c = judge(count, perm, K, W);
        if (div_c != -1 && div_c < min_div_c) {
            min_div_c = div_c;
        }
    }
    std::cout << min_div_c << std::endl;
}
