#include <bits/stdc++.h>


int mod_pow(int n, int r, int mod) {
    int res = 1;
    int pow = n;
    while (r > 0) {
        if (r & 1) {
            res = (res * pow) % mod;
        }
        pow = (pow * pow) % mod;
        r >>= 1;
    }
    return res;
}


int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    std::vector<int> order_a;
    std::set<int> set;

    int val = a % 10;
    while (set.find(val) == set.end()) {
        set.insert(val);
        order_a.emplace_back(val);
        val = (val * (a % 10)) % 10;
    }

    int mod = order_a.size();
    int res = mod_pow(b % mod, c, mod);
    if (res == 0) {
        res = mod;
    }
    std::cout << order_a[--res] << std::endl;
}
