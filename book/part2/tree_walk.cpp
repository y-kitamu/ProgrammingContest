#include <iostream>
#include <memory>
#include <vector>

class BinaryTree {
public:
    struct Node { int parent = -1, left = -1, right = -1; };

    BinaryTree(int n) : node_num(n) {
        node = std::vector<std::unique_ptr<Node>>(node_num);
        for (int i = 0; i < node_num; i++) {
            node[i] = std::make_unique<Node>();
        }
    }

    void inputData(int id, int left, int right) {
        node[id]->left = left;
        node[id]->right = right;
        if (left != -1) {
            node[left]->parent = id;
        }
        if (right != -1) {
            node[right]->parent = id;
        }
    }

    int searchRoot() {
        int root;
        for (int i = 0; i < node_num; i++) {
            if (node[i]->parent == -1) {
                root = i;
                break;
            }
        }
        return root;
    }

    void preorder(int id) {
        std::cout << " " << id;
        if (node[id]->left != -1) {
            preorder(node[id]->left);
        }
        if (node[id]->right != -1) {
            preorder(node[id]->right);
        }
    }

    void inorder(int id) {
        if (node[id]->left != -1) {
            inorder(node[id]->left);
        }
        std::cout << " " << id;
        if (node[id]->right != -1) {
            inorder(node[id]->right);
        }
    }

    void postorder(int id) {
        if (node[id]->left != -1) {
            postorder(node[id]->left);
        }
        if (node[id]->right != -1) {
            postorder(node[id]->right);
        }
        std::cout << " " << id;
    }

    int node_num;
    std::vector<std::unique_ptr<Node>> node;
};


int main() {
    int n;
    std::cin >> n;

    BinaryTree tree(n);

    int id, left, right;
    for (int i = 0; i < n; i++) {
        std::cin >> id >> left >> right;
        tree.inputData(id, left, right);
    }

    int root = tree.searchRoot();
    
    std::cout << "Preorder" << std::endl;
    tree.preorder(root);
    std::cout << std::endl;

    std::cout << "Inorder"  << std::endl;
    tree.inorder(root);
    std::cout << std::endl;

    std::cout << "Postorder" << std::endl;
    tree.postorder(root);
    std::cout << std::endl;
    
    return 0;
}
