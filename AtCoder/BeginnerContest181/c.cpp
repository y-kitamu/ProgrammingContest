#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> points(N, std::vector<int>(2));
    for (int i = 0; i < N; i++) {
        std::cin >> points[i][0] >> points[i][1];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                int lhs = (points[k][0] - points[i][0]) * (points[j][1] - points[i][1]);
                int rhs = (points[k][1] - points[i][1]) * (points[j][0] - points[i][0]);
                if (lhs == rhs) {
                    std::cout << "Yes" << std::endl;
                    return 0;
                }
            }
        }
    }
    std::cout << "No" << std::endl;
}
