#include <iostream>

void insertionSort(int* A, int N) {
    auto show_element =
        [&]() {
            for (int i = 0; i < N - 1; i++) {
                std::cout << A[i] << " ";
            }
            std::cout << A[N - 1] << std::endl;
        };
    
    show_element();
    
    for (int i = 1; i < N; i ++) {
        int val = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > val) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = val;
        show_element();
    }
}

int main(int argc, char ** argv) {
    int N;
    std::cin >> N;

    int arr[N];

    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    insertionSort(arr, N);
}
