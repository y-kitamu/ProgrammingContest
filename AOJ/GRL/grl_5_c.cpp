#include <bits/stdc++.h>


constexpr int INF = 1e9;

struct Node {
    Node() {}
    Node(int idx, int height) : idx(idx), height(height) {}
    int idx = INF, height = INF;
};

bool operator<(const Node& n1, const Node& n2) { return n1.height < n2.height; }
bool operator>(const Node& n1, const Node& n2) { return n2 < n1; }
bool operator<=(const Node& n1, const Node& n2) { return !(n2 < n1); }
bool operator>=(const Node& n1, const Node& n2) { return !(n1 < n2); }


class SegTree {
  public:
    SegTree() {}
    SegTree(std::vector<int> indices, std::vector<int> heights) {
        seg = std::vector<Node>(indices.size() * 4);
        N = 1;
        while (N < indices.size()) {
            N *= 2;
        }
        for (int i = 0; i < indices.size(); i++) {
            insert(i, Node(indices[i], heights[i]), 0, N, 0);
        }
    }

    void insert(int idx, Node node, int left, int right, int seg_idx) {
        if (idx < left || right <= idx) {
            return;
        }
        if (node.height < seg[seg_idx].height) {
            seg[seg_idx] = node;
        }
        if (idx == left && left + 1 == right) {
            return;
        }
        int mid = (left + right) / 2;
        insert(idx, node, left, mid, seg_idx * 2 + 1);
        insert(idx, node, mid, right, seg_idx * 2 + 2);
    }

    Node search(int min, int max, int left, int right, int idx) {
        if (min >= right || left >= max) {
            return Node();
        }
        if (min <= left && right <= max) {
            return seg[idx];
        }
        int mid = (left + right) / 2;
        return std::min(search(min, max, left, mid, idx * 2 + 1),
                        search(min, max, mid, right, idx * 2 + 2));
    }

    int N;
    std::vector<Node> seg;
};


void eulerTour(int idx, int h, std::vector<int>& verts, std::vector<int>& height,
               std::vector<int>& first, std::vector<std::vector<int>>& linked_list) {
    verts.emplace_back(idx);
    height.emplace_back(h);
    if (first[idx] == INF) {
        first[idx] = verts.size() - 1;
    }
    for (auto next : linked_list[idx]) {
        eulerTour(next, h + 1, verts, height, first, linked_list);
        verts.emplace_back(idx);
        height.emplace_back(h);
    }
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

    std::vector<int> verts, height, first(n, INF);
    eulerTour(0, 0, verts, height, first, linked_list);

    SegTree seg(verts, height);

    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v;
        std::cin >> u >> v;
        int min = std::min(first[u], first[v]);
        int max = std::max(first[u], first[v]) + 1;
        auto n = seg.search(min, max, 0, seg.N, 0);
        std::cout << n.idx << std::endl;
    }
}
