#include <bits/stdc++.h>


constexpr long long int MAXIMUM = (1ll << 31) - 1;


void update(int idx, std::vector<long long int>& seg) {
    int parent = (idx - 1) / 2;
    int bro = idx % 2 * 2 - 1 + idx;
    seg[parent] = std::min(seg[idx], seg[bro]);
    if (parent == 0) {
        return;
    }
    update(parent, seg);
}


long long int find(int mini, int maxi, int idx, int left, int right, const std::vector<long long int>& seg) {
    if (maxi <= left || right <= mini) {
        return MAXIMUM;
    }
    if (mini <= left && right <= maxi) {
        return seg[idx];
    }
    long long int lmin = find(mini, maxi, idx * 2 + 1, left, (left + right) / 2, seg);
    long long int rmin = find(mini, maxi, (idx + 1) * 2, (left + right) / 2, right, seg);
    return std::min(lmin, rmin);
}


int main() {
    long long int n, q;
    std::cin >> n >> q;

    std::vector<long long int> a(4 * n, MAXIMUM);
    long long int right = 1;
    while (right < n) {
        right *= 2;
    }
    for (int i = 0; i < q; i++) {
        int com;
        long long x, y;
        std::cin >> com >> x >> y;
        // std::cout << com << " , " << x << " , " << y << std::endl;
        if (com == 0) {
            int idx = right - 1 + x;
            a[idx] = y;
            update(idx, a);
        } else {
            std::cout << find(x, y + 1, 0, 0, right, a) << std::endl;;
        }
    }
}
