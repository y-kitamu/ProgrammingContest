#include <bits/stdc++.h>


class Solution {
public:
    int eatenApples(std::vector<int>& apples, std::vector<int>& days) {
        auto compare = [] (auto &lhs, auto& rhs) {
            return lhs.first > rhs.first;
        };

        int count = 0;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> que {compare};
        for (int i = 0; i < apples.size(); i++) {
            if (days[i] == 0 && apples[i] == 0) {
            } else {
                que.push(std::make_pair(days[i] + i, apples[i]));
            }
            while (!que.empty()) {
                auto top = que.top();
                que.pop();
                if (top.first <= i) {
                    continue;
                }
                count++;
                if (top.second - 1 > 0) {
                    que.push(std::make_pair(top.first, top.second - 1));
                }
                break;
            }
            std::cout << i << " , " << count << std::endl;
        }
        int day = apples.size() - 1;
        while (!que.empty()) {
            auto top = que.top();
            que.pop();
            int cnt = std::min(top.first - day, top.second);
            count += cnt;
            day += cnt;
        }

        return count;
    }
};

int main() {

}
