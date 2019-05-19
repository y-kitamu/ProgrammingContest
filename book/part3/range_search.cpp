#include <iostream>
#include <vector>


class kdTree {
  public:
    struct node {
        int x, y;
        node *parent, *left, *right;
    };

    node createTree(int depth) {
        
    }
    
    kdTree(int N) {
        node = std::vector<std::pair<int, int>>(N);
        for (int i = 0; i < N; i++) {
            int x, y;
            std::cin >> x >> y;
            point_list[i] = std::make_pair(x, y);
        }
        
    }


    std::vector<std::pair<int, int>>  point_list;
    node *nil;
};


int main() {
    int n, q;
    std::cin >> n;

    kdTree tree(n);

    std::cin >> q;

    for (int i = 0; i < q; i++) {
        
    }
}
