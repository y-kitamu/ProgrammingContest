#include <iostream>

void printSort(int * A, int N) {
    for (int i = 0; i < N - 1; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << A[N - 1] << std::endl;
}

void insertionSort(int * A, int N) {
    for (int i = 0; i < N; i++) {
        int v = A[i];
        for (int j = i - 1; j >= 0; j--) {
            if (v > A[j]) break;
            A[j + 1] = A[j];
            A[j] = v;
        }
        printSort(A, N);
    }
}

int main() {
    int N;
    std::cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    insertionSort(A, N);
}
