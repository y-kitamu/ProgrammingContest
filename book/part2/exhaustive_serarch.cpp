#include <iostream>


bool check(int *A, int n, int m) {
    bool canMakeNumber = false;
    for (int i = 0; i < n; i++) {
        if (A[i] == m) {
            return true;
        } else if (A[i] < m) {
            canMakeNumber |= check(A + i + 1, n - i - 1, m - A[i]);
        }
    }
    return canMakeNumber;
}


int solve(int *A, int n, int m) {
    if (n == 0) return false;
    if (m == A[0]) return true;
    return solve(A + 1, n - 1, m - A[0]) || solve(A + 1, n - 1, m);
}


int main() {
    int n, q, m;
    
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cin >> q;
    for (int i = 0; i < q; i++) {
        std::cin >> m;
        if (solve(arr, n, m)) {
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }
}
