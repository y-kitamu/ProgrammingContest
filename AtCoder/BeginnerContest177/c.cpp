#include <bits/stdc++.h>

long long int MOD = 1e9 + 7;

long long int modPow(long long int x, long long int a) {
  if (a == 1) return x;
  if (a % 2) return (x * modPow(x, a - 1)) % MOD;
  long long int t = modPow(x, a / 2);
  return (t * t) % MOD;
}

long long int  modInv(long long int x) {
  return modPow(x, MOD - 2);
}

int main() {
    int N;
    std::cin >> N;

    std::vector<long long int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    long long int sum = 0;
    long long int sqs = 0;
    for (int i = 0; i < N; i++) {
        sum = (sum + A[i]) % MOD;
        sqs = (sqs + A[i] * A[i]) % MOD;
    }
    long long int mod = ((sum * sum % MOD - sqs) * modInv(2)) % MOD;
    if (mod < 0) {
        mod += MOD;
    }
    std::cout << mod << std::endl;
}
