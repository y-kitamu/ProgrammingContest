#include <iostream>


void countingSort(int *A, int *B, int k, int n) {
    int C[k] = {};

    for (int j = 0; j < n; j++) {
        C[A[j]]++;
    }

    for (int i = 1; i < k; i++) {
        C[i] = C[i] + C[i - 1];
    }

    for (int j = n - 1; j >=  0; j--) {
        B[--C[A[j]]] = A[j];
    }
}


int main() {
    int n;
    std::cin >> n;

    int A[n], B[n];

    int max_val = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
        if (max_val < A[i]) max_val = A[i];
    }

    countingSort(A, B, max_val + 1, n);

    for (int i = 0; i < n; i++) {
        std::cout << B[i];
        if (i != n - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}
