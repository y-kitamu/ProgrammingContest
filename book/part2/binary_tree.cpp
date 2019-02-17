#include <iostream>
#include <string>

class BinaryTree {
public:
    struct Node { int parent = -1, left = -1, right = -1, brother = -1; };

    BinaryTree() {
        std::cin >> node_num;
        node = new Node[node_num];
        depth = new int[node_num];
        height = new int[node_num];
    }

    void inputData() {
        for (int i = 0; i < node_num; i++) {
            setNode();
        }
    }

    void setNode() {
        int id, left, right;
        std::cin >> id >> left >> right;
        node[id].left = left;
        node[id].right = right;
        if (left != -1) {
            node[left].parent = id;
            node[left].brother = right;
        }
        if (right != -1) {
            node[right].parent = id;
            node[right].brother = left;
        }
    }

    int searchRoot() {
        int root;
        for (int i = 0; i < node_num; i++) {
            if (node[i].parent == -1) {
                root = i;
                break;
            }
        }
        return root;
    }

    void calcDepth(int id, int d) {
        depth[id] = d;
        if (node[id].left != -1) calcDepth(node[id].left, d + 1);
        if (node[id].right != -1) calcDepth(node[id].right, d + 1);
    }

    void calcHeight(int i) {
        int lheight = 0, rheight = 0;
        if (node[i].left != -1) {
            calcHeight(node[i].left);
            lheight = height[node[i].left] + 1;
        }
        if (node[i].right != -1) {
            calcHeight(node[i].right);
            rheight = height[node[i].right] + 1;
        }
        height[i] = std::max(lheight, rheight);
    }
    
    void printAll() {
        for (int i = 0; i < node_num; i++) {
            printNode(i);
        }
    }
    
    void printNode(int id) {
        std::cout << "node " << id;
        std::cout << ": parent = " << node[id].parent;
        std::cout << ", sibling = " << node[id].brother;

        int deg = 0;
        if (node[id].left != -1) deg++;
        if (node[id].right != -1) deg++;
        std::cout << ", degree = " << deg;

        std::cout << ", depth = " << depth[id];
        std::cout << ", height = " << height[id] << ", ";

        if (node[id].parent == -1) std::cout << "root" << std::endl;
        else if (node[id].left == -1 && node[id].right == -1) std::cout << "leaf" << std::endl;
        else std::cout << "internal node" << std::endl;
    }

    int node_num;
    int *depth;
    int *height;
    Node *node;
};

int main() {
    BinaryTree tree = BinaryTree();
    
    tree.inputData();
    int root = tree.searchRoot();
    tree.calcDepth(root, 0);
    tree.calcHeight(root);
    tree.printAll();
}
