#include <bits/stdc++.h>


class Solution {
  public:
    int getXORSum(std::vector<int>& arr1, std::vector<int>& arr2) {
        int xor1 = arr1[0];
        for (int i = 1; i < arr1.size(); i++) {
            xor1 ^= arr1[i];
        }
        int xor2 = arr2[0];
        for (int i = 1; i < arr2.size(); i++) {
            xor2 ^= arr2[i];
        }
        return xor1 & xor2;
    }
};


int main() {}
