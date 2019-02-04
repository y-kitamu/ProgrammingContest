#include <iostream>
#include <cstring>

int partition(int *A, char *C, int p, int r) {
    int x = A[r];
    int i = p;

    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            std::swap(A[i], A[j]);
            std::swap(C[i], C[j]);
            i++;
        }
    }
    std::swap(A[i], A[r]);
    std::swap(C[i], C[r]);
    return i;
}

void quickSort(int *A, char *C, int p, int r) {
    if (p < r) {
        int q = partition(A, C, p, r);
        quickSort(A, C, p, q - 1);
        quickSort(A, C, q + 1, r);
    }
}


bool checkStable(int *A, char *C, int * At, char *Ct, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (A[i] == A[i + 1]) {
            for (int j = 0; j < n; j++) {
                if (C[i] == Ct[j] && A[i] == At[j]) {
                    break;
                } else if (C[i + 1] == Ct[j] && A[i + 1] == At[j]){
                    return false;
                }
            }
        }
    }
    return true;
}


int main() {
    int n;
    std::cin >> n;

    char C[n], Ct[n];
    int A[n], At[n];
    for (int i = 0; i < n; i++) {
        std::cin >> C[i] >> A[i];
    }

    std::memcpy(Ct, C, sizeof(char) * n);
    std::memcpy(At, A, sizeof(int) * n);

    quickSort(A, C, 0, n - 1);

    if (checkStable(A, C, At, Ct, n)) {
        std::cout << "Stable" <<std::endl;
    } else {
        std::cout << "Not stable" << std::endl;
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << C[i] << " " << A[i] << std::endl;
    }
}
