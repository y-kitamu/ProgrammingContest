#include <iostream>
#include <vector>
#include <queue>


class PriorityTree {
  public:
    PriorityTree() {}

    void add(int idx, int val) {
        tree.push_back(std::make_pair(idx, val));
        int num = tree.size() - 1;

        while (num > 0) {
            if (val < tree[(num - 1) / 2].second) {
                std::swap(tree[(num - 1) / 2], tree[num]);
                num = (num - 1) / 2;
            } else {
                break;
            }
        }
    }

    std::pair<int, int> pop() {
        std::pair<int, int> top = tree[0];

        tree[0] = tree[tree.size() - 1];

        int num = 0;
        while (num < (int)tree.size()) {
            int l = num * 2 + 1;
            int r = num * 2 + 2;
            int min_idx;
            if (l < (int)tree.size() && tree[num].second > tree[l].second) min_idx = l;
            else min_idx = num;

            if (r < (int)tree.size() && tree[min_idx].second > tree[r].second)  min_idx = r;

            if (min_idx != num) {
                std::swap(tree[min_idx], tree[num]);
                num = min_idx;
            } else {
                break;
            }
        }
        tree.erase(tree.begin() + tree.size() - 1);
        return top;
    }

    std::vector<std::pair<int, int>> tree;
};


int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> ada_mat(n, std::vector<int>(n));
    std::vector<bool> is_intree(n, false);
    int min_i = 0, min_j = 0;

    PriorityTree tree = PriorityTree();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> ada_mat[i][j];
            if (ada_mat[i][j] < ada_mat[min_i][min_j]) {
                min_i = i;
                min_j = j;
            }
        }
    }

    is_intree[min_i] = true;
    is_intree[min_j] = true;

    for (int i = 0; i < n; i++) {
        if (!is_intree[i] && ada_mat[min_i][i] != -1) {
            tree.add(i, ada_mat[min_i][i]);
        }
        if (!is_intree[i] && ada_mat[min_j][i] != -1) {
            tree.add(i, ada_mat[min_j][i]);
        }
    }

    int total = 0;
    while (tree.tree.size() > 0) {
        std::pair<int, int> elem = tree.pop();
        int idx = elem.first;
        int val = elem.second;

        if (!is_intree[idx]) {
            // std::cout << idx << std::endl;
            // std::cout << total << std::endl;
            total += val;
            is_intree[idx] = true;

            for (int i = 0; i < n; i++) {
                if (!is_intree[i] && ada_mat[idx][i] != -1) {
                    tree.add(i, ada_mat[idx][i]);
                }
            }
        }
    }

    std::cout << total << std::endl;
}
