#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    auto comp = [](auto& lhs, auto& rhs) { return lhs.first < rhs.first; };
    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>,
                        decltype(comp)>
        que0{comp}, que1{comp}, que2{comp}, que3{comp};

    for (int i = 0; i < N; i++) {
        std::string s;
        std::cin >> s;

        int lsum = 0, rsum = 0, min = 0, max = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                lsum++;
            } else {
                lsum--;
                min = std::min(lsum, min);
            }

            if (s[s.length() - i] == '(') {
                rsum++;
                max = std::max(rsum, max);
            } else {
                rsum--;
            }
        }
        if (min == 0 && lsum >= 0) {
            que0.push(std::make_pair(lsum, s));
        } else if (min < 0 && lsum >= 0) {
            que1.push(std::make_pair(min, s));
        } else if (max > 0 && lsum < 0) {
            que2.push(std::make_pair(lsum, s));
        } else {
            que3.push(std::make_pair(lsum, s));
        }
    }

    int state = 0;
    auto calc = [&state](auto& que) {
        while (!que.empty()) {
            auto top = que.top();
            que.pop();
            for (auto& c : top.second) {
                if (c == '(') {
                    state++;
                } else {
                    state--;
                }
                if (state < 0) {
                    return false;
                }
            }
        }
        return true;
    };

    if (calc(que0) && calc(que1) && calc(que2) && calc(que3) && state == 0) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
