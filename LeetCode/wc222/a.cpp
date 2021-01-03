#include <bits/stdc++.h>

class Solution {
public:
    int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) {
        std::sort(boxTypes.begin(), boxTypes.end(), [] (auto &lhs, auto &rhs) { return lhs[1] > rhs[1]; });
        int sum = 0;
        int cnt = 0;
        for (auto box : boxTypes) {
            int num = std::min(truckSize - cnt, box[0]);
            sum += num * box[1];
            cnt += num;
            if (cnt == truckSize) {
                break;
            }
        }
        return sum;
    }
};


int main() {

}
