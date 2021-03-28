#include <bits/stdc++.h>

using ll = long long int;


const int MAX = 510000;
const ll MOD = 998244353;
// const ll MOD = 1e9 + 7;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main() {
    ll N, M;
    std::cin >> N >> M;

    COMinit();
    std::vector<std::vector<ll>> dp(log2(M) + 1, std::vector<ll>(M, 0));
    for (int i = 0; i < M; i++) {
        dp[0][i] = 1;
    }

    std::vector<ll> cnt(M, 1);
    cnt[0] = 1;
    for (int i = 2; i <= M; i++) {
        int val = i;
        for (int k = 2; k <= std::sqrt(i) + 1; k++) {
            ll c = 0;
            while (val % k == 0) {
                val /= k;
                c++;
            }
            // std::cout << c << " ";
            cnt[i - 1] *= (c + 1);
        }
        // std::cout << val << std::endl;
        if (val > 1) {
            cnt[i - 1] *= 2;
        }
        // std::cout << std::endl;
    }

    for (auto& val : cnt) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    ll ans = M;
    for (int i = 1; i <= log2(M); i++) {
        ll pow = COM(N - 1, i);
        ll sum = 0;
        for (int j = 0; j < M; j++) {
            sum = (sum + COM(cnt[j] - 1, i)) % MOD;
        }
        std::cout << i << " , " << pow << " , " << sum << std::endl;
        ans = (ans + pow * sum % MOD) % MOD;
    }

    std::cout << ans << std::endl;
}
