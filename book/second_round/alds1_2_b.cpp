#include <iostream>

int selectionSort(int * A, int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        int min_idx = i;
        for (int j = i + 1; j < N; j++) {
            if (A[j] < A[min_idx]) {
                min_idx = j;
            }
        }
        if (i != min_idx) {
            std::swap(A[min_idx], A[i]);
            count++;
        }
    }
    return count;
}


void printSort(int * A, int N) {
    for (int i = 0; i < N - 1; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << A[N - 1] << std::endl;
}


int main() {
    int N;
    std::cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    int count = selectionSort(A, N);
    printSort(A, N);
    std::cout << count << std::endl;
}
