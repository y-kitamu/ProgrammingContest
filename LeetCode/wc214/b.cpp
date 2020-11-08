#include <bits/stdc++.h>

class Solution {
public:
    int minDeletions(std::string s) {
        std::map<char, int> map;
        for (auto c : s) {
            if (map.find(c) == map.end()) {
                map[c] = 1;
            } else {
                map[c]++;
            }
        }
        std::vector<int> vals;
        for (auto pair : map) {
            vals.emplace_back(pair.second);
        }
        std::sort(vals.begin(), vals.end(), [](auto &lhs, auto &rhs) { return lhs < rhs; });
        std::set<int> used;
        int count = 0;
        for (auto val : vals) {
            while (used.find(val) != used.end()) {
                count++;
                val--;
            }
            if (val != 0) {
                used.insert(val);
            }
        }
        return count;
    }
};

int main() {
    std::cout << Solution().minDeletions("abc") << std::endl;
}
