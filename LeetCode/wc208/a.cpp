#include <bits/stdc++.h>


class Solution {
public:
    int minOperations(std::vector<std::string>& logs) {
        int deep = 0;
        for (auto log : logs) {
            if (log == "./") {
                continue;
            }
            if (log == "../") {
                deep = std::max(0, deep - 1);
            } else {
                deep++;
            }
        }
        return abs(deep);
    }
};


int main() {
    std::vector<std::string> logs {
        "d1/","../","../","../"
        // "d1/","d2/","./","d3/","../","d31/"
    };
    std::cout << Solution().minOperations(logs) << std::endl;;
}
