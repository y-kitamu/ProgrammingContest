#include <iostream>
#include <cmath>

int main() {
    int NUMBER = 998244353;
    
    int N, M, val;

    std::cin >> N >> M;

    int row_vec[N] = {}, col_vec[M] = {};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> val;
            row_vec[i] += val % 2;
            col_vec[j] += val % 2;
        }
    }

    int row_even = 1, col_even = 1, row_odd = 1, col_odd = 1;
    bool is_col_odd = false, is_row_odd = false;
    for (int i = 0; i < N; i++) {
        if (row_vec[i] % 2 == 0) {
            row_even *= 2 % NUMBER;
        } else {
            row_odd *= 2 % NUMBER;;
            is_row_odd = true;
        }
    }
    
    for (int j = 0; j < M; j++) {
        if (col_vec[j] % 2 == 0) {
            col_even *= 2 % NUMBER;
        } else {
            col_odd *= 2 % NUMBER;
            is_col_odd = true;
        }
    }

    std::cout << row_even << " " << row_odd << std::endl;
    std::cout << col_even << " " << col_odd << std::endl;
    
    int cnt = 0;
    if (is_row_odd) {
        cnt += row_odd / 2 * (col_even + col_odd / 2 - 1);
    }
    if (is_col_odd) {
        cnt += col_odd / 2 * (row_even + row_odd / 2 - 1);
    }
    std::cout << cnt << std::endl;
    
}
