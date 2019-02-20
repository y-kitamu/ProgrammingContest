#include <iostream>
#include <vector>
#include <memory>

class BStree {
public:
    struct Node {
        int key = -1;
        std::shared_ptr<Node> parent = NIL, left = NIL, right = NIL;
        Node(int key) : key(key) {}
    };

    BStree(int n) : node_num(n) {}
    
    void insert(int key) {
        auto z = std::make_shared<Node>(key);
        std::shared_ptr<Node> x = root, y = NIL;
        while (x != NIL) {
            y = x;
            if (z->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        z->parent = y;
        if (y == NIL) {
            root = z;
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
        nodes.push_back(z);
    }

    void printInorder(std::shared_ptr<Node> node) {
        if (node == NIL) return;
        printInorder(node->left);
        std::cout << " " << node->key;
        printInorder(node->right);
    }

    void printPreorder(std::shared_ptr<Node> node) {
        if (node == NIL) return;
        std::cout << " " << node->key;
        printPreorder(node->left);
        printPreorder(node->right);
    }

private:
    int node_num;
    std::vector<std::shared_ptr<Node>> nodes;

public:
    static const std::shared_ptr<Node> NIL;
    std::shared_ptr<Node> root = NIL;

};

const std::shared_ptr<BStree::Node> BStree::NIL = std::make_shared<BStree::Node>(-1);

int main() {
    int n;
    std::cin >> n;

    BStree tree(n);

    for (int i = 0; i < n; i++) {
        std::string order;
        std::cin >> order;
        if (order == "insert") {
            int key;
            std::cin >> key;
            tree.insert(key);
        } else if (order == "print") {
            tree.printInorder(tree.root);
            std::cout << std::endl;
            tree.printPreorder(tree.root);
            std::cout << std::endl;
        }
    }
}
