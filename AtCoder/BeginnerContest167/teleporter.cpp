#include <iostream>
#include <vector>


struct Node {
    int idx;
    Node* child = nullptr;
    bool is_passed = false;
    int loop_idx;
};

int main() {
    int N;
    long long int K;
    std::cin >> N >> K;

    std::vector<Node> A(N);

    for (int i = 0; i < N; i++) {
        int next;
        std::cin >> next;
        A[i].idx = i;
        A[i].child = &A[next - 1];
    }

    int idx = 0, count = 0;
    while (true) {
        if (A[idx].is_passed) {
            break;
        }
        A[idx].is_passed = true;
        A[idx].loop_idx = count;
        idx = A[idx].child->idx;
        count++;
    }
    int n_head = A[idx].loop_idx;
    int n_loop = count - A[idx].loop_idx;

    if (K < n_head) {
        auto node = &A[0];
        for (int i = 0; i < K; i++) {
            node = node->child;
        }
        std::cout << node->idx + 1 << std::endl;
    } else {
        long long int n = (K - n_head) % n_loop;
        auto node = &A[idx];
        for (int i = 0; i < n; i++) {
            node = node->child;
        }
        std::cout << node->idx + 1 << std::endl;
    }
}
