#include <bits/stdc++.h>

template <class T>
T extgcd(T a, T b, T& x, T& y) {
    T d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= a / b * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}


template <class T>
T mod_inverse(T a, T m) {
    T x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}


template <class T>
T mod_facto(T n, T p) {
    T res = 1;
    for (T i = 1; i <= n; i++) {
        res = (res * i) % p;
    }
    return res;
}


template <class T>
std::vector<std::vector<T>> mod_combs(T n, T p) {
    std::vector<std::vector<T>> dp(n + 1, std::vector<T>(n + 1, 0));
    for (int i = 0; i < n + 1; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % p;
        }
    }
    return dp;
}


int main() {
    constexpr long long int p = 1e9 + 7;
    long long int n, k;
    std::cin >> n >> k;
    if (n > k) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<std::vector<long long int>> mods = mod_combs(k, p);

    // std::cout << mods[k][n] << " , " << mod_facto(n, p) << std::endl;
    std::cout << (mods[k][n] * mod_facto(n, p)) % p << std::endl;
}
