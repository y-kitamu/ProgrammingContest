#include <bits/stdc++.h>

class Solution {
public:
    int minPartitions(std::string n) {
        int max = 0;
        for (auto c : n) {
            max = std::max((int)(c - '0'), max);
        }
        return max;
    }
};

int main() {

}
