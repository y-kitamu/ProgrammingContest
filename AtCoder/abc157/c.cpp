#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::map<int, int> map;
    bool flag = true;
    for (int i = 0; i < M; i++) {
        int s, c;
        std::cin >> s >> c;
        if (map.find(s) == map.end()) {
            map[s] = c;
        } else {
            flag &= map[s] == c;
        }
        if (s == 1 && N > 1) {
            flag &= c > 0;
        }
    }

    if (flag) {
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (map.find(i) == map.end()) {
                if (i == 1 && N > 1) {
                    ans = 1;
                } else {
                    ans *= 10;
                }
            } else {
                ans = ans * 10 + map[i];
            }
        }
        std::cout << ans << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
}
