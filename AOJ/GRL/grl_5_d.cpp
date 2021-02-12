#include <bits/stdc++.h>


constexpr int INF = -1e9;


void print_vec(const std::vector<int>& vec) {
    for (auto val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}


class SegTree {
  public:
    SegTree(std::vector<int> first, std::vector<int> last) : first(first), last(last) {
        n = 1;
        int len = n;
        while (n <= first.size() * 2) {
            n *= 2;
            len += n;
        }
        seg = std::vector<int>(len, 0);
        lazy = std::vector<int>(len, 0);
    }

    void add(int v, int w) {
        int min = first[v], max = last[v] + 1;
        addImpl(w, min, max, 0, n, 0);
    }

    void eval(int idx) {
        if (lazy[idx] == 0) {
            return;
        }
        if (idx * 2 + 2 < seg.size()) {
            lazy[idx * 2 + 1] += lazy[idx];
            lazy[idx * 2 + 2] += lazy[idx];
        }
        seg[idx] += lazy[idx];
        lazy[idx] = 0;
    }

    void addImpl(int val, int min, int max, int left, int right, int idx) {
        if (max <= left || right <= min) {
            return;
        }
        if (min <= left && right <= max) {
            lazy[idx] += val;
            eval(idx);
            return;
        }
        eval(idx);
        int mid = (left + right) / 2;
        addImpl(val, min, max, left, mid, idx * 2 + 1);
        addImpl(val, min, max, mid, right, idx * 2 + 2);
    }

    int getSum(int u) { return getSumImpl(first[u], 0, n, 0); }

    int getSumImpl(int val, int left, int right, int idx) {
        if (val < left || right <= val) {
            return 0;
        }
        eval(idx);
        if (left == val && left + 1 == right) {
            return seg[idx];
        }
        int mid = (left + right) / 2;
        return getSumImpl(val, left, mid, idx * 2 + 1) + getSumImpl(val, mid, right, idx * 2 + 2);
    }

    void print() {
        std::cout << "seg = ";
        print_vec(seg);
        std::cout << "lazy= ";
        print_vec(lazy);
    }

    int n;
    std::vector<int> seg, lazy;
    std::vector<int> first, last;
};


void eulerTour(int idx, int& cnt, const std::vector<std::vector<int>>& linked_list,
               std::vector<int>& first, std::vector<int>& last) {
    if (first[idx] == INF) {
        first[idx] = cnt;
    }
    cnt++;
    for (auto next : linked_list[idx]) {
        eulerTour(next, cnt, linked_list, first, last);
    }
    last[idx] = cnt;
    cnt++;
}


int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> linked_list(n);
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        std::vector<int> childs(k);
        for (int j = 0; j < k; j++) {
            std::cin >> childs[j];
        }
        linked_list[i] = childs;
    }

    std::vector<int> first(n, INF), last(n, INF);
    int cnt = 0;
    eulerTour(0, cnt, linked_list, first, last);
    std::vector<int> sums(cnt, 0);

    // print_vec(first);
    // print_vec(last);

    SegTree seg(first, last);
    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int cmd;
        std::cin >> cmd;
        if (cmd == 0) {
            int v, w;
            std::cin >> v >> w;
            seg.add(v, w);
            // seg.print();
        } else {
            int u;
            std::cin >> u;
            std::cout << seg.getSum(u) << std::endl;
            // seg.print();
        }
    }
}
