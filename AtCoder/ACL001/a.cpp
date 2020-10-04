#include <bits/stdc++.h>


struct Node {
    int loc_index;
    int left_node, right_node;
};


int np = 0;
std::vector<Node> tree;
std::vector<std::vector<int>> locs;
std::vector<int> disjoint;

int make2DTree(int lhs, int rhs, int depth, std::vector<std::vector<int>>& locs) {
    if (!(lhs < rhs)) {
        return -1;
    }
    if (depth % 2 == 0) {
        std::sort(locs.begin() + lhs, locs.begin() + rhs, [](auto &l, auto &r) { return l[1] < r[1]; });
    } else {
        std::sort(locs.begin() + lhs, locs.begin() + rhs, [](auto &l, auto &r) { return l[2] < r[2]; });
    }
    int idx = np++;
    int mid = (lhs + rhs) / 2;
    tree[idx].loc_index = mid;
    tree[idx].left_node = make2DTree(lhs, mid, depth + 1, locs);
    tree[idx].right_node = make2DTree(mid + 1, rhs, depth + 1, locs);
    return idx;
}


void find(int node_idx, int sx, int tx, int sy, int ty, int depth, int val) {
    std::vector<int> loc = locs[tree[node_idx].loc_index];
    int loc_idx = loc[0], loc_x = loc[1], loc_y = loc[2];
    if (sx < loc_x && loc_x < tx && sy < loc_y && loc_y < ty) {
        if (disjoint[loc_idx] < val) {
            disjoint[val] = disjoint[loc_idx];
            val = disjoint[loc_idx];
        }
        disjoint[loc_idx] = val;
    }

    if (depth % 2 == 0) {
        if (tree[node_idx].left_node != -1 && sx < loc_x) {
            find(tree[node_idx].left_node, sx, tx, sy, ty, depth + 1, val);
        }
        if (tree[node_idx].right_node != -1 && loc_x < tx) {
            find(tree[node_idx].right_node, sx, tx, sy, ty, depth + 1, val);
        }
    } else {
        if (tree[node_idx].left_node != -1 && sy < loc_y) {
            find(tree[node_idx].left_node, sx, tx, sy, ty, depth + 1, val);
        }
        if (tree[node_idx].right_node != -1 && loc_y < ty) {
            find(tree[node_idx].right_node, sx, tx, sy, ty, depth + 1, val);
        }
    }
}


int main() {
    int N;
    std::cin >> N;
    locs = std::vector<std::vector<int>>(N, std::vector<int>(3));
    disjoint = std::vector<int>(N);
    for (int i = 0; i < N; i++) {
        locs[i][0] = i;
        disjoint[i] = i;
        std::cin >> locs[i][1] >> locs[i][2];
    }


    tree = std::vector<Node>(N);
    make2DTree(0, N, 0, locs);

    for (int i = 0; i < N; i++) {
        find(0, 0, locs[i][1], 0, locs[i][2], 0, locs[i][0]);
        find(0, locs[i][1], N + 1, locs[i][2], N + 1, 0, locs[i][0]);
    }

    auto find_root = [] (int idx) {
        std::vector<int> indices;
        while (disjoint[idx] != idx) {
            indices.emplace_back(idx);
            idx = disjoint[idx];
        }
        for (auto i : indices) {
            disjoint[i] = idx;
        }
        return idx;
    };

    std::map<int, int> map;
    for (int i = 0; i < N; i++) {
        int root = find_root(i);
        if (map.find(root) == map.end()) {
            map[root] = 0;
        }
        map[root]++;
    }

    for (int i = 0; i < N; i++) {
        std::cout << map[find_root(i)] << std::endl;
    }
}
