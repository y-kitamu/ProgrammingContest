#include <bits/stdc++.h>


void add(int mini, int maxi, int val, int idx, int left, int right, std::vector<int>& seg) {
    if (maxi <= left || right <= mini) {
        return;
    }
    if (mini <= left && right <= maxi) {
        seg[idx] += val;
        return;
    }
    int mid = (left + right) / 2;
    add(mini, maxi, val, idx * 2 + 1, left, mid, seg);
    add(mini, maxi, val, (idx + 1) * 2, mid, right, seg);
}

int get(int idx, std::vector<int>& seg) {
    if (idx == 0) {
        return seg[0];
    }
    return get((idx - 1) / 2, seg) + seg[idx];
}


int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> seg(n * 4, 0);
    int offset = 1;
    while (offset < n) {
        offset *= 2;
    }
    for (int i = 0; i < q; i++) {
        int com;
        std::cin >> com;
        if (com == 0) {
            int s, t, x;
            std::cin >> s >> t >> x;
            add(s - 1, t, x, 0, 0, offset, seg);
        } else {
            int t;
            std::cin >> t;
            std::cout << get(offset - 1 + t - 1, seg) << std::endl;
        }
    }
}
