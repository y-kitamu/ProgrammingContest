#include <bits/stdc++.h>


using ll = long long int;

int main() {
    int N;
    std::cin >> N;

    std::vector<ll> X(N), C(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i] >> C[i];
        C[i]--;
    }

    ll MAX = 2e9, MIN = -2e9;
    std::vector<ll> mins(N, MAX), maxs(N, MIN);
    for (int i = 0; i < N; i++) {
        mins[C[i]] = std::min(mins[C[i]], X[i]);
        maxs[C[i]] = std::max(maxs[C[i]], X[i]);
    }

    auto calc_dist = [](ll cur, ll node, ll dst) { return std::abs(node - cur) + std::abs(dst - node); };

    std::vector<ll> dp(2, 0);
    ll cur_min = 0, cur_max = 0;
    for (int i = 0; i < N; i++) {
        if (mins[i] > maxs[i]) {
            continue;
        }

        ll to_min = std::min(dp[0] + calc_dist(cur_min, maxs[i], mins[i]),
                             dp[1] + calc_dist(cur_max, maxs[i], mins[i]));
        ll to_max = std::min(dp[0] + calc_dist(cur_min, mins[i], maxs[i]),
                             dp[1] + calc_dist(cur_max, mins[i], maxs[i]));
        dp[0] = to_min;
        dp[1] = to_max;
        cur_min = mins[i];
        cur_max = maxs[i];
    }
    ll dist = std::min(dp[0] + std::abs(cur_min), dp[1] + std::abs(cur_max));
    std::cout << dist << std::endl;
}
