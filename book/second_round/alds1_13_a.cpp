#include <bits/stdc++.h>


bool check_consistece(int row, int col, const std::vector<std::pair<int, int>> &pos) {
    for (auto && pair : pos) {
        if (pair.second == col || std::abs(pair.first - row) == std::abs(pair.second - col)) {
            return false;
        }
    }
    return true;
}


bool queen_pos(int row, int col, std::vector<std::pair<int, int>>& pos) {
    if (row == 8) {
        return true;
    }

    bool exists = false;
    for (auto p : pos) {
        exists |= p.first == row;
    }
    if (!exists) {
        if (!check_consistece(row, col, pos)) {
            return false;
        }
        pos.emplace_back(row, col);
    }
    for (int i = 0; i < 8; i++) {
        if (queen_pos(row + 1, i, pos)) {
            return true;
        }
    }
    if (!exists) {
        pos.erase(pos.end() - 1);
    }
    return false;
}


int main() {
    int k;
    std::cin >> k;
    std::vector<std::pair<int, int>> pos;
    for (int i = 0; i < k; i++) {
        int r, c;
        std::cin >> r >> c;
        pos.emplace_back(std::make_pair(r, c));
    }

    for (int i = 0; i < 8; i++) {
        if (queen_pos(0, i, pos)) {
            break;
        }
    }

    std::vector<std::vector<char>> res(8, std::vector<char>(8, '.'));
    for (auto&& p : pos) {
        res[p.first][p.second] = 'Q';
    }

    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            std::cout << res[r][c];
        }
        std::cout << std::endl;
    }
}
