#include <bits/stdc++.h>

class Solution {
public:
    int concatenatedBinary(int n) {
        long long int MOD = 1e9 + 7;
        long long int sum = 1;
        long long int digit = 1;
        long long int exp = 2;
        for (long long int i = 2; i <= n; i++) {
            if (exp == i) {
                exp *= 2;
                digit++;
            }
            sum = (sum * exp + i) % MOD;
        }
        return sum;
    }
};


int main() {

}
