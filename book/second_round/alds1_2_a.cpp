#include <iostream>

int bubbleSort(int * A, int N) {
    int count = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = N - 1; i > 0 ; i--) {
            if (A[i] < A[i - 1]) {
                std::swap(A[i], A[i - 1]);
                flag = true;
                count++;
            }
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
    int count = bubbleSort(A, N);
    printSort(A, N);
    std::cout << count << std::endl;
}
