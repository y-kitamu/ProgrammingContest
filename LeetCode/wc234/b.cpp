#include <bits/stdc++.h>

using ll = long long int;


ll GCD(ll a, ll b) { return b == 0 ? a : GCD(b, a % b); }

ll LCM(ll a, ll b) { return a * (b / GCD(a, b)); }


class Solution {
  public:
    int reinitializePermutation(int n) {
        std::vector<int> count(n, n + 1);
        std::vector<int> perm(n);
        std::iota(perm.begin(), perm.end(), 0);
        for (int i = 1; i <= n; i++) {
            perm = permute(perm);
            for (int j = 0; j < n; j++) {
                if (perm[j] == j) {
                    count[j] = std::min(count[j], i);
                }
            }
        }

        ll cnt = 1;
        for (int i = 0; i < n; i++) {
            cnt = LCM(cnt, count[i]);
        }
        return cnt;
    }

    std::vector<int> permute(std::vector<int>& perm) {
        std::vector<int> arr(perm.size());
        for (int i = 0; i < perm.size(); i++) {
            if (i % 2 == 0) {
                arr[i] = perm[i / 2];
            } else {
                arr[i] = perm[perm.size() / 2 + (i - 1) / 2];
            }
        }
        return arr;
    }
};


int main() {}
