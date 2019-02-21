#include <iostream>
#include <vector>
#include <memory>
#include <functional>

class BStree {
public:
    struct Node {
        int key = -2e9;
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

    bool find(int key) {
        auto x = root;
        while (x != NIL) {
            if (x->key == key) return true;
            else if (x->key < key) x = x->right;
            else if (x->key > key) x = x->left;
        }
        return false;
    }

    void del(int key) {
        auto x = root;
        while (x->key != key) {
            if (x->key < key) x = x->right;
            else x = x->left;
        }
        
        delete_node(x);
    }

    void delete_node(std::shared_ptr<Node> x) {
        if (x->left == NIL && x->right == NIL) {
            if (x->parent->left == x) x->parent->left = NIL;
            else x->parent->right = NIL;
            x = NIL;
        } else if (x->left == NIL) {
            if (x->parent->left == x) x->parent->left = x->right;
            else x->parent->right = x->right;
            x->right->parent = x->parent;
        } else if (x->right == NIL) {
            if (x->parent->left == x) x->parent->left = x->left;
            else x->parent->right = x->left;
            x->left->parent = x->parent;
        } else {
            auto y = x->right;
            while (y->left != NIL) {
                y = y->left;
            }
            x->key = y->key;
            delete_node(y);
        }
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
        } else if (order == "find") {
            int key;
            std::cin >> key;
            if (tree.find(key)) std::cout << "yes" << std::endl;
            else std::cout << "no" << std::endl;
        } else if (order == "delete") {
            int key;
            std::cin >> key;
            tree.del(key);
        } else if (order == "print") {
            tree.printInorder(tree.root);
            std::cout << std::endl;
            tree.printPreorder(tree.root);
            std::cout << std::endl;
        }
    }
}
