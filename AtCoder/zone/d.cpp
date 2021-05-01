#include <bits/stdc++.h>


int main() {
    std::string S;
    std::cin >> S;

    std::deque<char> que;
    bool is_end = true;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'R') {
            is_end = !is_end;
        } else {
            if (que.empty()) {
                que.push_back(S[i]);
                continue;
            }
            if (is_end) {
                if (que.back() == S[i]) {
                    que.pop_back();
                } else {
                    que.push_back(S[i]);
                }
            } else {
                if (que.front() == S[i]) {
                    que.pop_front();
                } else {
                    que.push_front(S[i]);
                }
            }
        }
    }

    std::string res = "";
    if (is_end) {
        while (!que.empty()) {
            res += que.front();
            que.pop_front();
        }
    } else {
        while (!que.empty()) {
            res += que.back();
            que.pop_back();
        }
    }
    std::cout << res << std::endl;
}
