#include <iostream>
#include <vector>


class UnionFind {
  public:
    UnionFind(int N) : parent(N) {
        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }
    }

    int root(int x) {
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        parent[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    std::vector<int> parent;
};


int main() {
    int n, m, q;
    std::cin >> n >> m;

    UnionFind uf(n);
    
    for (int i = 0; i < m; i++) {
        int s, t;
        std::cin >> s >> t;
        uf.unite(s, t);
    }

    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int s, t;
        std::cin >> s >> t;
        if (uf.same(s, t)) {
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }
}
