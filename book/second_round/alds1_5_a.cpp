#include <iostream>

bool search(int val, int * A, int a_idx, int a_num, int q) {
    if (val == q) {
        return true;
    }
    if (val > q || a_idx >= a_num) {
        return false;
    } 
    
    return search(val + A[a_idx], A, a_idx + 1, a_num, q) ||
        search(val, A, a_idx + 1, a_num, q);
}

int main() {
    int n;
    std::cin >> n;
    
    int A[n];
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int m;
        std::cin >> m;
        if (search(0, A, 0, n, m)) {
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }
}
