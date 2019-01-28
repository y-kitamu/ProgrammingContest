#include <iostream>


void selectionSort(int *A, int N) {
    int count = 0;
    for (int i = 0; i < N - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < N; j++) {
            if (A[min_idx] > A[j]) {
                min_idx = j;
            }
        }
        if (i != min_idx) {
            std::swap(A[i], A[min_idx]);
            count++;
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << A[i];
        if (i != N - 1) {
            std::cout << " ";
        } else {
            std::cout << std::endl;
        }
    }
    std::cout << count << std::endl;
    
    return;
}


int main(int argc, char ** argv) {
    int N;
    std::cin >> N;

    int arr[N];
    
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    selectionSort(arr, N);
}
