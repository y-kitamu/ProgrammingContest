#include <iostream>
#include <vector>

class UnionFord {
  public:
    UnionFord(int N) {
        tree = std::vector<int>(N);
        for (int i = 0; i < N; i++) {
            tree[i] = i;
        }
    };

    int parent(int x) {
        if (x == tree[x]) {
            return x;
        }
        return parent(tree[x]);
    }

    void unite(int x, int y) {
        int parent_x = parent(x);
        int parent_y = parent(y);

        if (parent_x == parent_y) {
            return;
        }

        tree[parent_y] = parent_x;
    }

    bool same(int x, int y) {
        int parent_x = parent(x);
        int parent_y = parent(y);
        return parent_x == parent_y;
    }

    std::vector<int> tree;
};


int main() {
    int N, Q;
    std::cin >> N >> Q;

    UnionFord tree(N);

    for (int i = 0; i < Q; i++) {
        int com, x, y;
        std::cin >> com >> x >> y;
        if (com == 0) {
            tree.unite(x, y);
        } else {
            std::cout << (int)tree.same(x, y) << std::endl;;
        }
    }
}
