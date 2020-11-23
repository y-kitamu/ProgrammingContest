#include <bits/stdc++.h>


int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    std::vector<std::vector<std::vector<double>>> vals(
        101, std::vector<std::vector<double>>(101, std::vector<double>(101, 0.0)));
    for (int a = 99; a >= 0; a--) {
        for (int b = 99; b >= 0; b--) {
            for (int c = 99; c >= 0; c--) {
                int sum = a + b + c;
                if (sum == 0) {
                    continue;
                }
                vals[a][b][c] = (double)a / sum * (1 + vals[a + 1][b][c]) +
                    (double)b / sum * (1 + vals[a][b + 1][c]) +
                    (double)c / sum * (1 + vals[a][b][c + 1]);
            }
        }
    }
    std::cout << std::fixed << std::setprecision(10) << vals[A][B][C] << std::endl;

}
