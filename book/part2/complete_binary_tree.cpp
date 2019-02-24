#include <iostream>
#include <vector>
#include <memory>

struct Node;
static const std::shared_ptr<Node> NIL = std::make_shared<Node>();

struct Node {
    int key;
    std::shared_ptr<Node> parent = NIL, left = NIL, right = NIL;
};


int main() {
    int N;
    std::cin >> N;

    // std::vector<std::shared_ptr<Node>> nodes(N, std::make_shared<Node>());
    std::vector<std::shared_ptr<Node>> nodes(N);

    for (int i = 0; i < N; i++) {
        nodes[i] = std::make_shared<Node>();
        
        int key;
        std::cin >> key;
        nodes[i]->key = key;
        
        if (i > 0) {
            nodes[i]->parent = nodes[(i - 1) / 2];
            if (i % 2 == 1) {
                nodes[(i - 1) / 2]->left = nodes[i];
            } else {
                nodes[(i - 1) / 2]->right = nodes[i];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << "node " << i + 1 << ": key = " << nodes[i]->key << ", ";
        if (nodes[i]->parent != NIL) {
            std::cout << "parent key = " << nodes[i]->parent->key << ", ";
        }
        if (nodes[i]->left != NIL) {
            std::cout << "left key = " << nodes[i]->left->key << ", ";
        }
        if (nodes[i]->right != NIL) {
            std::cout << "right key = " << nodes[i]->right->key << ", ";
        }
        std::cout << std::endl;
    }
}
