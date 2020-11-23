#include <bits/stdc++.h>

class Solution {
public:
    std::string getSmallestString(int n, int k) {
        std::vector<int> vals(n, 26);
        int sum = 26 * n;
        for (int i = 0; i < n; i++) {
            int res = sum - k;
            if (res == 0) {
                break;
            }
            if (res > 25) {
                vals[i] = 1;
                sum -= 25;
            } else {
              vals[i] = 26 - res;
              sum -= res;
            }
        }
        std::string ans = "";
        for (int i = 0; i < n; i++) {
            ans += ('a' + vals[i]  - 1);
        }
        return ans;
    }
};


int main() {
    int n, k;
    std::cin >> n >> k;
    std::cout << Solution().getSmallestString(n, k) << std::endl;
}
