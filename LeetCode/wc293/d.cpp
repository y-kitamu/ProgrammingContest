/**
 * @file d.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-15 11:46:52
 */
#include <bits/stdc++.h>

class CountIntervals {
    struct Node {
        int min, max, count = 0;
        bool flag = false;
        Node* lhs = nullptr;
        Node* rhs = nullptr;
    };
    Node* root = nullptr;

  public:
    CountIntervals() { root = new Node{0, 1 << 30}; }

    void add(int left, int right) { _add(root, left, right + 1); }

    int _add(Node* node, int left, int right) {
        if (right <= node->min || node->max <= left || node->flag) {
            return node->count;
        }
        if (left <= node->min && node->max <= right) {
            node->flag = true;
            node->count = node->max - node->min;
            // printNode(node);
            return node->count;
        }
        int mid = (node->min + node->max) / 2;
        if (node->lhs == nullptr) {
            node->lhs = new Node{node->min, mid};
        }
        if (node->rhs == nullptr) {
            node->rhs = new Node{mid, node->max};
        }
        int cl = _add(node->lhs, left, right);
        int cr = _add(node->rhs, left, right);
        if (node->lhs != nullptr && node->rhs != nullptr) {
            if (node->lhs->flag && node->rhs->flag) {
                node->flag = true;
            }
        }
        node->count = cl + cr;
        // printNode(node);
        return node->count;  //
    }

    void printNode(Node* node) {
        std::cout << node->min << ", " << node->max << ", " << node->count << std::endl;
    }

    int count() { return root->count; }
};


int main() {
    int N = 1e5;
    std::vector<int> lhs(N), rhs(N);

    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());
    std::uniform_int_distribution<> dist(1, 1 << 30);
    for (int i = 0; i < N; i++) {
        int v1 = dist(engine), v2 = dist(engine);
        if (v1 > v2) {
            std::swap(v1, v2);
        }
        lhs[i] = v1;
        rhs[i] = v2;
    }

    for (int i = 0; i < N; i++) {
        lhs[i] = i * 10 + 1;
        rhs[i] = i * 10 + 2;
    }

    std::vector<int> ans(N);
    CountIntervals* obj = new CountIntervals();
    for (int i = 0; i < N; i++) {
        obj->add(lhs[i], rhs[i]);
        ans[i] = obj->count();
    }

    std::cout << ans[0] << std::endl;
    std::cout << ans[N - 1] << std::endl;
}
