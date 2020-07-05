#include <bits/stdc++.h>



int main() {
    int MOD = 1000000007;
    int N, K;
    std::cin >> N >> K;

    int zeros = 0;
    std::vector<long long int> negs, poss;
    for (int i = 0; i < N; i++) {
        int val;
        std::cin >> val;
        if (val == 0) {
            zeros++;
        }
        if (val > 0) {
            poss.emplace_back(val);
        } else {
            negs.emplace_back(val);
        }
    }

    std::sort(negs.begin(), negs.end());
    std::sort(poss.begin(), poss.end());

    int n_neg = negs.size();
    int n_pos = poss.size();

    int num = 0;
    while (num < K) {

    }
}
