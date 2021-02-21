#include <bits/stdc++.h>

class Solution {
  public:
    std::vector<int> minOperations(std::string boxes) {
        std::vector<int> ans(boxes.length());
        for (int i = 0; i < boxes.length(); i++) {
            for (int j = 0; j < boxes.length(); j++) {
                if (boxes[j] == '1') {
                    ans[i] += std::abs(j - i);
                }
            }
        }
        return ans;
    }
};


int main() {}
