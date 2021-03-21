#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> mat(N, std::vector<int>(N));
    std::vector<int> diff_x(N - 1), diff_y(N - 1);
    bool flag = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> mat[i][j];
            if (j > 0) {
                if (i == 0) {
                    diff_x[j - 1] = mat[i][j] - mat[i][j - 1];
                } else {
                    flag &= (mat[i][j] - mat[i][j - 1]) == diff_x[j - 1];
                }
            }

            if (i > 0) {
                if (j == 0) {
                    diff_y[i - 1] = mat[i][j] - mat[i - 1][j];
                } else {
                    flag &= (mat[i][j] - mat[i - 1][j]) == diff_y[i - 1];
                }
            }
        }
    }

    int min_a = 0, cur_a = 0;
    int min_b = 0, cur_b = 0;

    for (int i = 0; i < N - 1; i++) {
        cur_a += diff_x[i];
        cur_b += diff_y[i];
        min_a = std::min(cur_a, min_a);
        min_b = std::min(cur_b, min_b);
    }

    min_a = -min_a;
    min_b = -min_b;
    if (min_a + min_b > mat[0][0] || !flag) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
        min_a = mat[0][0] - min_b;
        std::vector<int> A(N, min_a), B(N, min_b);
        for (int i = 0; i < N - 1; i++) {
            A[i + 1] = A[i] + diff_x[i];
            B[i + 1] = B[i] + diff_y[i];
        }

        auto print = [](std::vector<int>& vec) {
            int N = vec.size();
            for (int i = 0; i < N; i++) {
                std::cout << vec[i];
                if (i < N - 1) {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        };

        print(B);
        print(A);
    }
}
