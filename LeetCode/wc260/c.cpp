/*
 * c.cpp
 *
 * Create Date : 2021-09-26 11:45:01
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    bool placeWordInCrossword(std::vector<std::vector<char>>& board, std::string word) {
        int m = board.size();
        int n = board[0].size();
        int wl = word.length();
        // std::cout << "m = " << m << ", n = " << n << ", wl = " << wl << std::endl;

        std::vector<std::vector<int>> sv(m, std::vector<int>(n, 0)), sh(m, std::vector<int>(n, 0));
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                // std::cout << x << " , " << y << ", word = " << board[y][x] << std::endl;
                if (board[y][x] == '#') {
                    continue;
                }
                if (sv[y][x] == 0 && y <= m - wl) {
                    bool flag = y == 0 || board[y - 1][x] == '#';
                    for (int w = 0; w < wl; w++) {
                        // std::cout << "board = " << board[y + w][x] << ", word = " << word[w]
                        //           << std::endl;
                        flag &= board[y + w][x] == ' ' || board[y + w][x] == word[w];
                        sv[y + w][x] = 1;
                        if (!flag) {
                            break;
                        }
                    }
                    if (flag) {
                        if (y + wl == m || board[y + wl][x] == '#') {
                            // std::cout << "top to bot : " << x << " , " << y << std::endl;
                            return true;
                        }
                    }
                }
                if (sh[y][x] == 0 && x <= n - wl) {
                    bool flag = x == 0 || board[y][x - 1] == '#';
                    for (int w = 0; w < wl; w++) {
                        flag &= board[y][x + w] == ' ' || board[y][x + w] == word[w];
                        sh[y][x + w] = 1;
                        if (!flag) {
                            break;
                        }
                    }
                    if (flag) {
                        if (x + wl == n || board[y][x + wl] == '#') {
                            // std::cout << "lef to rig : " << x << " , " << y << std::endl;
                            return true;
                        }
                    }
                }
            }
        }

        sv = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));
        sh = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));
        for (int y = m - 1; y >= 0; y--) {
            for (int x = n - 1; x >= 0; x--) {
                if (board[y][x] == '#') {
                    continue;
                }
                if (sv[y][x] == 0 && y >= wl - 1) {
                    bool flag = y == m - 1 || board[y + 1][x] == '#';
                    for (int w = 0; w < wl; w++) {
                        flag &= board[y - w][x] == ' ' || board[y - w][x] == word[w];
                        sv[y - w][x] = 1;
                        if (!flag) {
                            break;
                        }
                    }
                    if (flag) {
                        if (y - wl == -1 || board[y - wl][x] == '#') {
                            // std::cout << "bot to top : " << x << " , " << y << std::endl;
                            return true;
                        }
                    }
                }
                if (sh[y][x] == 0 && x >= wl - 1) {
                    bool flag = x == n - 1 || board[y][x + 1] == '#';
                    for (int w = 0; w < wl; w++) {
                        flag &= board[y][x - w] == ' ' || board[y][x - w] == word[w];
                        sh[y][x - w] = 1;
                        if (!flag) {
                            break;
                        }
                    }
                    if (flag) {
                        if (x - wl == -1 || board[y][x - wl] == '#') {
                            // std::cout << "rig to lef : " << x << " , " << y << std::endl;
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

int main() {}
