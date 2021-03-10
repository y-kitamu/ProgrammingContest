#include <bits/stdc++.h>

using ll = long long int;


ll binarySearch(ll min, ll max, ll A, ll B, ll X) {
    if (min == max) {
        return min;
    }
    ll mid = (min + max + 1) / 2;
    ll d = std::log10(mid) + 1;
    if (mid * A + d * B > X) {
        return binarySearch(min, mid - 1, A, B, X);
    }
    return binarySearch(mid, max, A, B, X);
}


int main() {
    ll A, B, X;
    std::cin >> A >> B >> X;

    std::cout << binarySearch(0, 1e9, A, B, X) << std::endl;
}
