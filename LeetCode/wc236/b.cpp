#include <bits/stdc++.h>

class Solution {
  public:
    int findTheWinner(int n, int k) {
        std::vector<bool> friends(n, true);
        int cur = -1;
        for (int i = 0; i < n - 1; i++) {
            int cnt = 0;
            while (cnt < k) {
                cur = (cur + 1) % n;
                cnt++;
                while (!friends[cur]) {
                    cur = (cur + 1) % n;
                }
            }
            std::cout << cur << std::endl;
            friends[cur] = false;
        }

        int win;
        for (int i = 0; i < n; i++) {
            if (friends[i]) {
                win = i + 1;
            }
        }
        return win;
    }
};

int main() {}
