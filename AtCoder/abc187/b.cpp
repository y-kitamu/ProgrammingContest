#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> loc(N, std::vector<int>(2));
    for (int i = 0; i < N; i++) {
        std::cin >> loc[i][0] >> loc[i][1];
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (std::abs(loc[i][1] - loc[j][1]) <= std::abs(loc[i][0] - loc[j][0])) {
                cnt++;
            }
        }
    }
    std::cout << cnt << std::endl;
}
