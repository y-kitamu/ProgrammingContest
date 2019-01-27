#include <iostream>


void bublleSort(int *A, int N) {
    int count = 0;

    int flag = 1;
    int idx = 0;
    while (flag) {
        flag = 0;
        for (int i = N - 1; i > idx; i--) {
            if (A[i - 1] > A[i]) {
                std::swap(A[i - 1], A[i]);
                flag = 1;
                count++;
            }
        }
        idx++;
    }

    for (int i = 0; i < N - 1; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << A[N - 1] << std::endl;

    std::cout << count << std::endl;
}

int main(int argc, char ** argv) {
    int N;
    std::cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    bublleSort(arr, N);
}
