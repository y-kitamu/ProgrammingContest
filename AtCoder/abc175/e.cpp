#include <bits/stdc++.h>


using ll = long long int;


int main() {
    int R, C, K;
    std::cin >> R >> C >> K;

    std::vector<std::vector<int>> map(R, std::vector<int>(C, 0));
    for (int i = 0; i < K; i++) {
        int r, c, v;
        std::cin >> r >> c >> v;
        map[--r][--c] = v;
    }

    std::vector<std::vector<ll>> cur(C, std::vector<ll>(4, 0)), prev(C, std::vector<ll>(4, 0));
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            ll val = map[r][c];
            ll pval = std::max(std::max(prev[c][0], prev[c][1]), std::max(prev[c][2], prev[c][3]));
            cur[c][0] = pval;
            cur[c][1] = pval + val;
            if (c > 0) {
                cur[c][0] = std::max(cur[c - 1][0], cur[c][0]);
                auto c1 = std::max(cur[c - 1][1], cur[c - 1][0] + val);
                cur[c][1] = std::max(c1, cur[c][1]);
                cur[c][2] = std::max(cur[c - 1][2], cur[c - 1][1] + val);
                cur[c][3] = std::max(cur[c - 1][3], cur[c - 1][2] + val);
            }
        }
        prev = cur;
        std::fill(cur.begin(), cur.end(), std::vector<ll>(4, 0));
    }

    ll res =
        std::max(std::max(prev[C - 1][0], prev[C - 1][1]), std::max(prev[C - 1][2], prev[C - 1][3]));
    std::cout << res << std::endl;
}
