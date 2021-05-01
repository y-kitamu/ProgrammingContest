#include <bits/stdc++.h>


bool check(int idx, std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (i == idx || vec[i] == 0) {
            continue;
        }
        for (int j = i + 1; j < vec.size(); j++) {
            if (j == idx || vec[j] == 0) {
                continue;
            }
            if ((i | j | idx) == vec.size() - 1) {
                return true;
            }
        }
    }
    return false;
}


int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> ss(5, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
        std::cin >> ss[0][i] >> ss[1][i] >> ss[2][i] >> ss[3][i] >> ss[4][i];
    }

    auto comp = [&ss](auto& lhs, auto& rhs) {
        return ss[lhs.first][lhs.second] < ss[rhs.first][rhs.second];
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> que{comp};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            que.push(std::make_pair(j, i));
        }
    }

    std::vector<int> checks(N, 0);
    std::vector<int> flags(1 << 5, 0);

    int power = 1e9;
    while (!que.empty()) {
        auto top = que.top();
        que.pop();
        checks[top.second] += 1 << top.first;

        flags[checks[top.second]] = 1;

        auto val = ss[top.first][top.second];
        power = std::min(power, val);

        if (check(checks[top.second], flags)) {
            break;
        }
    }

    std::cout << power << std::endl;
}
