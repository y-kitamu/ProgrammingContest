#include <bits/stdc++.h>


int count(std::vector<int>& status, std::vector<std::vector<int>>& conds) {
    int cnt = 0;
    for (auto cond : conds) {
        if (status[cond[0]] > 0 && status[cond[1]] > 0) {
            cnt++;
        }
    }
    return cnt;
}


int search(int idx, std::vector<int> status, std::vector<std::vector<int>>& conds,
           std::vector<std::vector<int>>& choice) {
    if (idx == choice.size()) {
        return count(status, conds);
    }

    status[choice[idx][0]]++;
    int cnt1 = search(idx + 1, status, conds, choice);
    status[choice[idx][0]]--;
    status[choice[idx][1]]++;
    int cnt2 = search(idx + 1, status, conds, choice);
    status[choice[idx][1]]--;
    return std::max(cnt1, cnt2);
}


int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> conds(M, std::vector<int>(2));
    for (int i = 0; i < M; i++) {
        std::cin >> conds[i][0] >> conds[i][1];
        conds[i][0]--;
        conds[i][1]--;
    }

    int K;
    std::cin >> K;
    std::vector<std::vector<int>> choice(K, std::vector<int>(2));
    for (int i = 0; i < K; i++) {
        std::cin >> choice[i][0] >> choice[i][1];
        choice[i][0]--;
        choice[i][1]--;
    }

    std::vector<int> status(N, 0);
    std::cout << search(0, status, conds, choice) << std::endl;
}
