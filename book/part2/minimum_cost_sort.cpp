#include <iostream>
#include <cstring>

int partition(int *B, int left, int right) {
    int part = B[right - 1];
    int idx = left;
    for (int i = left; i < right; i++) {
        if (B[i] < part){
            std::swap(B[i], B[idx]);
            idx++;
        }
    }
    std::swap(B[idx], B[right - 1]);
    return idx;
}


void quickSort(int *B, int left, int right) {
    if (left < right) {
        int idx = partition(B, left, right);
        quickSort(B, left, idx);
        quickSort(B, idx + 1, right);
    }
}

int calcCost(int *A, int *B, int N) {
    int cost = 0;
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (A[j] == B[i]) {
                cost += A[j] + A[i];
                std::swap(A[j], A[i]);
                break;
            }
        }
    }
    return cost;
}


int main() {
    int N;
    std::cin >> N;

    int A[N], B[N];
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    memcpy(B, A, sizeof(int) * N);

    quickSort(B, 0, N);
    int cost = calcCost(A, B, N);

    std::cout << cost << std::endl;
}
