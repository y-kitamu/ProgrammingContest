#include <bits/stdc++.h>

class Solution {
public:
    int countPairs(std::vector<int>& deliciousness) {
        std::map<long long int, long long int> map;
        long long int MOD = 1e9 + 7;

        for (auto val : deliciousness) {
            if (map.find(val) == map.end()) {
                map[val] = 0;
            }
            map[val]++;
        }

        long long int count = 0;
        long long int power = 1;
        for (int i = 0; i <= 22; i++, power *= 2) {
            for (auto pair : map) {
                if (pair.first > power / 2) {
                    continue;
                }
                long long int other = power - pair.first;
                if (other == pair.first) {
                    count = (count + pair.second * (pair.second - 1) / 2) % MOD;
                } else {
                    if (map.find(other) != map.end()) {
                        count = (count + pair.second * map[other]) % MOD;
                    }
                }
            }
        }
        return count;
    }
};


int main() {

}
