#include <iostream>
#include <string>

struct Node {
    int id;
    int parent = -1;
    int degree = 0;
    int *child;
};

class Tree {
public:    
    struct Node2 {int parent = NIL, left = NIL, right = NIL; };

    Tree(int node_num) : node_num(node_num) {
        nodes = new Node2[node_num];
        depths = new int[node_num];
    }

    void setNode() {
        int id, child_num;
        std::cin >> id >> child_num;
        if (child_num > 0) {
            int children[child_num];
            for (int i = 0; i < child_num; i++) {
                std::cin >> children[i];
                nodes[children[i]].parent = id;

                if (i == 0) {
                    nodes[id].left = children[i];
                } else {
                    nodes[children[i - 1]].right = children[i];
                }
            }
        }
    }

    void setDepth(int id, int p) {
        depths[id] = p;
        if (nodes[id].right != NIL) {
            setDepth(nodes[id].right, p);
        }
        if (nodes[id].left != NIL) {
            setDepth(nodes[id].left, p + 1);
        }
    }

    void printInfo(int id) {
        std::cout << "node " << id << ": parent = " << nodes[id].parent << ", depth = " << depths[id] << ", ";
        if (nodes[id].parent == NIL) {
            std::cout << types[0];
        } else if (nodes[id].left == NIL) {
            std::cout << types[2];
        } else {
            std::cout << types[1];
        }
        std::cout << ", [";
        
        int child_id = nodes[id].left;
        while (child_id != NIL) {
            std::cout << child_id;
            if (nodes[child_id].right != NIL) {
                std::cout << ", ";
            }
            child_id = nodes[child_id].right;
        }
        std::cout << "]" << std::endl;
    }

    std::string types[3] = {"root", "internal node", "leaf"};
    int node_num;
    Node2 *nodes;
    int *depths;
    static const int NIL = -1;
};

int main() {
    int n;
    std::cin >> n;

    Tree tree(n);
    for (int i = 0; i < n; i++) {
        tree.setNode();
    }

    int root;
    for (int i = 0; i < n; i++) {
        if (tree.nodes[i].parent == tree.NIL) {
            root = i;
            break;
        }
    }

    tree.setDepth(root, 0);
    
    for (int i = 0; i < n; i++) {
        tree.printInfo(i);
    }
}
