#include <bits/stdc++.h>


class Solution {
  public:
    bool canReach(std::string s, int minJump, int maxJump) {
        std::vector<bool> flag(s.length(), false);
        std::queue<int> que;
        flag[0] = true;
        for (int i = minJump; i < s.length(); i++) {
            if (flag[i - minJump]) {
                // std::cout << "push " << i - minJump << std::endl;
                que.push(i - minJump);
            }
            if (s[i] == '0' && !que.empty()) {
                flag[i] = true;
            }
            if (que.front() == i - maxJump) {
                // std::cout << "pop " << i - maxJump << std::endl;
                que.pop();
            }
        }
        return flag[s.length() - 1];
    }
};


int main() {}
