#include <bits/stdc++.h>


class Solution {
  public:
    int countBalls(int lowLimit, int highLimit) {
        std::map<int, int> cnts;
        for (int val = lowLimit; val <= highLimit; val++) {
            int i = val;
            int cnt = 0;
            while (i / 10 > 0) {
                cnt += i % 10;
                i /= 10;
            }
            cnt += i % 10;
            std::cout << cnt << std::endl;
            if (cnts.find(cnt) == cnts.end()) {
                cnts[cnt] = 0;
            }
            cnts[cnt]++;
        }
        int max = 0;
        for (auto pair : cnts) {
            max = std::max(pair.second, max);
        }
        return max;
    }
};


int main() {}
