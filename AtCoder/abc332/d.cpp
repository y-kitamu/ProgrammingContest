/**
 * @file d.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2023-12-10 21:26:11
 */
#include <bits/stdc++.h>


int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::vector<int>> A(H, std::vector<int>(W)), B(H, std::vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> A[i][j];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> B[i][j];
        }
    }

    std::vector<int> perm_h(H), perm_w(W);
    std::iota(perm_h.begin(), perm_h.end(), 0);
    std::iota(perm_w.begin(), perm_w.end(), 0);

    auto count_reverse_number = [](std::vector<int>& perm) {
        int count = 0;
        for (int i = 0; i < perm.size(); i++) {
            for (int j = i + 1; j < perm.size(); j++) {
                if (perm[i] > perm[j]) {
                    count++;
                }
            }
        }
        return count;
    };
    int min = -1;
    do {
        do {
            bool flag = true;
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (A[perm_h[i]][perm_w[j]] != B[i][j]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) {
                    break;
                }
            }
            if (flag) {
                int count = count_reverse_number(perm_h) + count_reverse_number(perm_w);
                if (min == -1 || min > count) {
                    min = count;
                }
            }
        } while (std::next_permutation(perm_w.begin(), perm_w.end()));
    } while (std::next_permutation(perm_h.begin(), perm_h.end()));
    std::cout << min << std::endl;
}
