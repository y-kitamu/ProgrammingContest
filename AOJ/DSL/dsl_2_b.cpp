#include <bits/stdc++.h>


void add(int idx, int val, std::vector<int>& seg) {
    seg[idx] += val;
    if (idx == 0) {
        return;
    }
    add((idx - 1) / 2, val, seg);
}

int getSum(int mini, int maxi, int idx, int left, int right, std::vector<int>& seg) {
    if (maxi <= left || right <= mini) {
        return 0;
    }
    if (mini <= left && right <= maxi) {
        return seg[idx];
    }
    int mid = (left + right) / 2;
    int sum = getSum(mini, maxi, idx * 2 + 1, left, mid, seg);
    sum += getSum(mini, maxi, (idx + 1) * 2, mid, right, seg);
    return  sum;
}


int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> seg(4 * n, 0);

    int offset = 1;
    while (offset < n) {
        offset *= 2;
    }
    offset--;
    for (int i = 0; i < q; i++) {
        int com, x, y;
        std::cin >> com >> x >> y;
        if (com == 0) {
            add(offset + x - 1, y, seg);
        } else {
            int sum = getSum(x - 1, y, 0, 0, offset + 1, seg);
            std::cout << sum << std::endl;
        }
    }
}
