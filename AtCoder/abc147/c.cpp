#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<std::pair<int, int>>> test(N);
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        for (int j = 0; j < a; j++) {
            int x, y;
            std::cin >> x >> y;
            x--;
            test[i].emplace_back(std::make_pair(x, y));
        }
    }

    int max_cnt = 0;
    for (int i = 1; i < 1 << N; i++) {
        std::vector<int> flag(N);
        for (int j = 0; j < N; j++) {
            flag[j] = (i >> j) & 1;
        }

        bool ok = true;
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (flag[j] == 0) {
                continue;
            }
            for (auto pair : test[j]) {
                ok &= flag[pair.first] == pair.second;
            }
            cnt++;
        }
        if (ok) {
            max_cnt = std::max(cnt, max_cnt);
        }
    }
    std::cout << max_cnt << std::endl;
}
