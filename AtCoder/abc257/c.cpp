/**
 * @file c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-25 21:09:16
 */
#include <bits/stdc++.h>


struct Person {
    int w;
    int pc;
};

int main() {
    int N;
    std::string S;
    std::cin >> N >> S;

    int nc = 0, np = 0;
    for (auto& c : S) {
        if (c == '1') {
            np++;
        }
    }

    auto comp = [](auto& lhs, auto& rhs) {
        if (lhs.w == rhs.w) {
            return lhs.pc > rhs.pc;
        }
        return lhs.w > rhs.w;
    };
    std::priority_queue<Person, std::vector<Person>, decltype(comp)> que{comp};
    for (int i = 0; i < N; i++) {
        int w;
        std::cin >> w;
        if (S[i] == '0') {
            w++;
        }
        que.push(Person{w, (int)(S[i] - '0')});
    }

    int max = np;
    while (!que.empty()) {
        auto top = que.top();
        // std::cout << top.w << ", " << top.pc << std::endl;
        que.pop();
        if (top.pc == 0) {
            nc++;
        } else {
            np--;
        }
        max = std::max(nc + np, max);
    }
    std::cout << max << std::endl;
}
