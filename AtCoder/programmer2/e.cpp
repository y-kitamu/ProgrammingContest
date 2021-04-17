#include <bits/stdc++.h>


void solve(int level, int min, int max, bool is_rev, const std::string& S, const int& K,
           std::vector<std::map<char, int>>& maps) {
    if (level == 0) {
        for (int i = 0; i < max - min; i++) {
            auto idx = K + i;
            if (is_rev) {
                idx = K + max - min - 1 - i;
            }
            if (maps[idx].find(S[min + i]) == maps[idx].end()) {
                maps[idx][S[min + i]] = 0;
            }
            // std::cout << idx << " , " << min + i << " , " << S[min + i] << std::endl;
            maps[idx][S[min + i]]++;
        }
        return;
    }

    if ((min - max) % 2 != 0) {
        auto c = S[(min + max) / 2];
        if (maps[K - level].find(c) == maps[K - level].end()) {
            maps[K - level][c] = 0;
        }
        maps[K - level][c]++;
    }
    is_rev = true;
    solve(level - 1, min, (min + max) / 2, is_rev, S, K, maps);
    solve(level - 1, (min + max + 1) / 2, max, !is_rev, S, K, maps);
}


int main() {
    int K;
    std::string S;
    std::cin >> K >> S;

    auto len = S.length();
    auto token = len;
    for (int i = 0; i < K; i++) {
        if (token == 0) {
            std::cout << "impossible" << std::endl;
            return 0;
        }
        token /= 2;
    }

    if (token == 1) {
        std::cout << "impossible" << std::endl;
        return 0;
    }

    std::vector<std::map<char, int>> maps(K + token);
    bool is_rev = false;
    solve(K, 0, len, is_rev, S, K, maps);

    int cnt = 0;
    for (int i = 0; i < K; i++) {
        if (maps[i].empty()) {
            continue;
        }
        int max = 0, sum = 0;
        for (auto& pair : maps[i]) {
            max = std::max(max, pair.second);
            sum += pair.second;
        }
        cnt += sum - max;
    }

    std::string tk = "";
    int mini = 1 << K;
    for (int i = 0; i < token; i++) {
        int max = 0, sum = 0, min = 1 << K;
        char c;
        for (auto& pair : maps[K + i]) {
            // std::cout << pair.first << pair.second << " ";
            if (pair.second > max) {
                min = std::min(pair.second - max, min);
                max = std::max(max, pair.second);
                c = pair.first;
            } else {
                min = std::min(max - pair.second, min);
            }
            sum += pair.second;
        }
        // std::cout << std::endl;
        if (token % 2 == 0 || i != token / 2) {
            mini = std::min(mini, min);
        }
        tk += c;
        cnt += sum - max;
    }
    // std::cout << cnt << std::endl;

    bool flag = token > 0;
    for (int i = 0; i < token / 2; i++) {
        flag &= tk[i] == tk[token - i - 1];
    }
    if (flag) {
        cnt += mini;
    }

    std::cout << cnt << std::endl;
}
