#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

class BinaryTree {
public:
    struct Node { int parent = -1, left = -1, right = -1; };

    BinaryTree(int n) : node_num(n) {

        nodes = std::vector<std::unique_ptr<Node>>(node_num);
        for (int i = 0; i < node_num; i++) {
            nodes[i] = std::make_unique<Node>();
        }

        preorder = std::vector<int>(node_num);
        inorder = std::vector<int>(node_num);
        for (int i = 0; i < node_num; i++) {
            std::cin >> preorder[i];
        }
        for (int i = 0; i < node_num; i++) {
            std::cin >> inorder[i];
        }

        root = preorder[0];
    }
    
    void reconstructTree(int n, int start, int end) {
        int pos =
            std::find(inorder.begin() + start, inorder.begin() + end, preorder[n]) - (inorder.begin() + start);

        if (pos + start > start) {
            nodes[preorder[n] - 1]->left = preorder[n + 1];
            nodes[preorder[n + 1] - 1]->parent = preorder[n];
            reconstructTree(n + 1, start, start + pos);
        }
        if (pos + start < end - 1) {
            nodes[preorder[n] - 1]->right = preorder[n + pos + 1];
            nodes[preorder[n + pos + 1] - 1]->parent = preorder[n];
            reconstructTree(n + pos + 1, start + pos + 1, end);
        }
    }

    void linePostOrder(int i) {
        if (i == -1) return;

        linePostOrder(nodes[i - 1]->left);
        linePostOrder(nodes[i - 1]->right);

        postorder.push_back(i);
    }

    void print() {
        int i = 0;
        for (; i < node_num - 1; i++) {
            std::cout << postorder[i] << " ";
        }
        std::cout << postorder[i] << std::endl;
    }

    int node_num, root;
    std::vector<int> preorder, inorder, postorder;
    std::vector<std::unique_ptr<Node>> nodes;
};

int main() {
    int n;
    std::cin >> n;
    
    BinaryTree tree(n);
    tree.reconstructTree(0, 0, n);
    tree.linePostOrder(tree.root);
    tree.print();
}
