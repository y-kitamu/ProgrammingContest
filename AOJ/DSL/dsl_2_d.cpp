#include <bits/stdc++.h>


struct Node {
    Node() {}
    Node(int priority, long long int val): val(val), priority(priority) {}
    long long int val = (1ll << 31) - 1;
    int priority = -1;
};


void update(int mini, int maxi, int priority, int val, int idx, int left, int right,
            std::vector<Node>& seg) {
    if (maxi <= left || right <= mini) {
        return;
    }
    if (mini <= left && right <= maxi) {
        seg[idx].priority = priority;
        seg[idx].val = val;
        return;
    }
    update(mini, maxi, priority, val, idx * 2 + 1, left, (left + right) / 2, seg);
    update(mini, maxi, priority, val, (idx + 1) * 2, (left + right) / 2, right, seg);
}


Node find(int idx, const std::vector<Node>& seg) {
    if (idx == 0) {
        return seg[0];
    }
    Node node = find((idx - 1) / 2, seg);
    if (seg[idx].priority < node.priority) {
        return node;
    }
    return seg[idx];
}

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<Node> seg(n * 4);
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
            update(s, t + 1, i, x, 0, 0, offset, seg);
        } else {
            int i;
            std::cin >> i;
            std::cout << find(offset - 1 + i, seg).val << std::endl;
        }
    }
}
