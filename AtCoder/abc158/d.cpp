#include <bits/stdc++.h>


int main() {
    std::string S;
    std::cin >> S;

    bool is_reverse = false;
    std::string head = "";
    int Q;
    std::cin >> Q;
    for (int i = 0; i < Q; i++) {
        int cmd;
        std::cin >> cmd;
        if (cmd == 1) {
            is_reverse = !is_reverse;
        } else {
            int f;
            char c;
            std::cin >> f >> c;
            bool is_head = f == 1;
            if ((is_head && is_reverse) || (!is_head && !is_reverse)) {
                S += c;
            } else {
                head += c;
            }
        }
    }

    std::string ans = "";
    // std::cout << head << std::endl;
    if (is_reverse) {
        std::reverse(S.begin(), S.end());
        ans = S + head;
    } else {
        std::reverse(head.begin(), head.end());
        ans = head + S;
    }
    std::cout << ans << std::endl;
}
