#include <iostream>
#include <vector>


class kDTree {
  public:
    kDTree(std::vector<std::pair<int, int>> point_list, int n) {
        
    }
};


int main() {
    int n, q;
    std::cin << n << std::endl;

    kDTree tree;
    
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
    }

    std::cin << q << std::endl;

    for (int i = 0; i < q; i++) {
        int sx, tx, sy, ty;
        std::cin >> sx >> tx >> sy >> ty;
    }

    return 0;
}
