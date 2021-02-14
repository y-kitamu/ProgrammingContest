#include <bits/stdc++.h>


class Solution {
  public:
    int countHomogenous(std::string s) {
        long long int left = 0;
        long long int right = 0;
        const long long int MOD = 1e9 + 7;
        long long int sum = 0;
        while (left < s.size()) {
            while (s[left] == s[right]) {
                right++;
            }
            sum = (sum + ((right - left + 1) * (right - left) / 2)) % MOD;

            left = right;
        }
        return sum;
    }
};


int main() {}
