#include <bits/stdc++.h>

long long int MOD = 1000000007;

int main() {
    std::string L;
    std::cin >> L;

    int length = L.length();
    std::vector<long long int> pow3(L.length() + 1, 1), pow2(L.length() + 1, 1);
    for (int i = 1; i <= length; i++) {
        pow3[i] = pow3[i - 1] * 3 % MOD;
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }

    long long int sum = pow3[length];
    int zero_count = 0;
    for (int i = 0; i < length; i++){
        if (L[i] == '0') {
            sum = sum - (pow2[i + 1 - zero_count] * pow3[length - i - 1]) % MOD;
            if (sum < 0)  {
                sum += MOD;
            }
            zero_count++;
        }
    }

    std::cout << sum << std::endl;
}
