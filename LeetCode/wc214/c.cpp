#include <bits/stdc++.h>

class Solution {
public:
    int maxProfit(std::vector<int>& inventory, int orders) {
        long long int MOD = 1e9 + 7;
        std::sort(inventory.begin(), inventory.end(), [](auto &lhs, auto &rhs) { return lhs > rhs; });
        long long int value = 0;
        for (long long int i = 0; i < inventory.size(); i++) {
            if (i == inventory.size() - 1) {
                long long int num = orders / (i + 1);
                long long int res = orders % (i + 1);
                long long int val = (inventory[i] * 2 - num + 1) * num * (i + 1) / 2 % MOD;
                val = (val + res * (inventory[i] - num) % MOD) % MOD;
                value = (value + val) % MOD;
                break;
            }
            if (inventory[i] == inventory[i + 1]) {
                continue;
            }
            long long int num_pick = (inventory[i] - inventory[i + 1]) * (i + 1);
            if (num_pick < orders) {
                long long int val = (inventory[i] + inventory[i + 1] + 1) * num_pick / 2 % MOD;
                value = (value + val) % MOD;
                orders -= num_pick;
            } else {
                long long int num = orders / (i + 1);
                long long int res = orders % (i + 1);
                long long int val = (inventory[i] * 2 - num + 1) * num * (i + 1) / 2 % MOD;
                val = (val + res * (inventory[i] - num) % MOD) % MOD;
                value = (value + val) % MOD;
                break;
            }
        }
        return value;
    }
};


int main() {
    std::vector<int> vec({680754224,895956841,524658639,3161416,992716630,7365440,582714485,422256708,332815744,269407767});
    std::cout << Solution().maxProfit(vec, 707568720) << std::endl;
}
